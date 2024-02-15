#include "dcmodule.h"
#include"tty.h"
#include"ocpp.h"
#include"poll.h"
#include "modbus.h"
extern QMutex mutex1;
int can_fd,can2_fd, i;
int nbytes;
struct sockaddr_can addr,addr_2;
struct ifreq ifr,ifr_2;
struct can_frame frame;
QQueue<int> can_module;
extern QQueue<int> queue;
extern Can_Module_Transmit   CAN_TX_2;
extern Can_Module_Recieve CAN_RX_2;
extern struct LoadSharing Sharing;
extern Can_Module_Transmit CAN_TX;
extern Can_Module_Recieve CAN_RX;
//extern PowerModuleOutput Pm_Out;
extern Charger_Status CCS;
extern Charger_Status CCS2;
//extern Rfid_Auth RAuth;
extern struct input_event ev[64];
unsigned int voltage; //taken from gloquad
float current;//taken from gloquad
int rfid_scanner_fd = 0;

static unsigned long int can_baudrate = 125000;
unsigned long int baud_size= 10000;
const char * dev_name="can0";
const char * dev_name_2="can1";
unsigned int Voltage_Frame[8]={0x03,0x00,0x00,0x21,0x42,0x70,0x00,0x00};
unsigned int Current_Frame[8]={0x03,0x00,0x00,0x22,0x00,0x00,0x00,0x00};

unsigned int flush_buffer[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

//unsigned int feedback_frame[8]={0x10,0x00,0x00,0x01,0x00,0x00,0x00,0x00};
unsigned int Response_frame[8];
unsigned int Response_frame2[8];

uint8_t shutdown_frame[8] = {0x03,0x00,0x00,0x30,0x00,0x01,0x00,0x00};
uint8_t boot_frame[8] = {0x03,0x00,0x00,0x30,0x00,0x00,0x00,0x00};
uint8_t read_volatge[8] = {0x10,0x00,0x00,0x01,0x00,0x00,0x00,0x00};
uint8_t read_current[8] = {0x10,0x00,0x00,0x02,0x00,0x00,0x00,0x00};

uint8_t read_Status_A[8] = {0x10,0x00,0x00,0x0c,0x00,0x00,0x00,0x00};
uint8_t read_Status_B[8] = {0x10,0x00,0x00,0x0d,0x00,0x00,0x00,0x00};
uint8_t read_Status_C[8] = {0x10,0x00,0x00,0x0e,0x00,0x00,0x00,0x00};

uint8_t ReceivedBuff[BuffSize][8]= {0};
uint8_t plc_req =0,plc_req_2=0;

unsigned int ReceivedFrameCounter = 0;
uint16_t ParsedFrameCounter= 0;
bool flag=0,bCabelCharge = 0;
extern int bIsolation_ok;
extern struct Parameter set_parameter;
//POWER Module 1 82 address send frame id : 0x060c1781, rcv frame Id: 0x860f8411
//POWER Module 2 80 address send frame id : 0x060c0781, rcv frame Id: 0x860f8401

Dcmodule::Dcmodule(QObject *parent) : QObject(parent)
{

}
int Dcmodule::can_setting(const char* can, const int bitrate, int enable)
{
    int ret = 0;
    char cmdline[128] = { '\0' };
    if(enable == 1){
        sprintf(cmdline,
                "ip link set %s type can bitrate %ld triple-sampling on; ifconfig %s up",
                can, bitrate, can);
    }
    ret = system(cmdline);
    sleep(2);
    return WEXITSTATUS(ret);
}

int Dcmodule::can_setting1( const long int baud_size,int enable)
{
    int ret1 = 0;
    char cmdline[128] = { '\0' };

    if(enable == 1){
        sprintf(cmdline,"ifconfig can0 txqueuelen %ld",baud_size);
    }

    ret1 = system(cmdline);
    sleep(2);
    return WEXITSTATUS(ret1);
}
void Dcmodule::Timer_Init(void)
{
    QTimer *timer = new QTimer();
    timer->setInterval(1000);    
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    timer->start();
    can_module.enqueue(Pm_On);
    qDebug()<<"Timer Event call "<< endl;
}
void Dcmodule::TestModeEvent(void)
{
   if(CCS.start == Charging_Start)
    {
        CAN_TX.Dc_main = 0xA5;    // change
        CAN_TX.Pm1_voltage = set_parameter.DC_VMAX;
        if(set_parameter.PMIndividual_ED == true)
        {
            CAN_TX.Pm1_current = set_parameter.DC_IMAX;
        }
        else
        {
            CAN_TX.Pm1_current = set_parameter.DC_IMAX/2;
        }
        can_module.enqueue(Pm_Power1);  
    }
   else if(CCS.start == Charging_Stop || CCS.start == Try_To_Start || CCS.start == Try_To_Stop)
    {
        if(CCS.DC_Voltage_1 < 100)
        {
            CAN_TX.Dc_main = 0;
        }       
    }
   if(CCS2.start == Charging_Start)
    {
        CAN_TX_2.Dc_main = 0xA5; // oN
      //  CAN_TX.Pm1_current = set_parameter.DC_IMAX/2;
        CAN_TX_2.Pm1_voltage = set_parameter.DC_VMAX;
        if(set_parameter.PMIndividual_ED == true)
        {
            CAN_TX_2.Pm1_current = set_parameter.DC_IMAX;
        }
        else
        {
            CAN_TX_2.Pm1_current = set_parameter.DC_IMAX/2;
        }
        can_module.enqueue(Pm_Power1_2);
    }
   else if(CCS2.start == Charging_Stop || CCS2.start == Try_To_Start || CCS2.start == Try_To_Stop)
    {
        if(CCS2.DC_Voltage_1 < 100)
        {
            CAN_TX_2 .Dc_main = 0;
        }
    }
}
void Dcmodule::TimerEvent(void)
{
    if(set_parameter.TestMode_ED == true)
    {
        TestModeEvent();
        return;
    }
    if(plc_req == SessionSetupReq)
    {
        //can_module.enqueue(Pm_Off);        
        CAN_TX.Precharge = 0;
        CAN_TX.Dc_main = 0;
        CAN_TX.Ac_main = 0xA5;
    }
    else if(plc_req == ServiceDiscoveryReq)
    {

    }
    else if(plc_req == ServicePaymentSelectionReq)
    {

    }
    else if(plc_req == ContractAuthenticationReq)
    {

    }
    else if(plc_req == ChargeParameterDiscoveryReq)
    {

    }
    else if(plc_req == PowerDeliveryReq)
    {

    }
    else if(plc_req == CableCheckReq)
    {        
        if(bIsolation_ok == 0)
        {
            can_module.enqueue(Cable_Check);
        }        
    }
    else if(plc_req == PreChargeReq)
    {       
        can_module.enqueue(Pm_Power1);       
    }
    else if(plc_req == CurrentDemandReq)
    {
       can_module.enqueue(Pm_Power1);

        if(Sharing.Is_LoadSharing == true)
        {
           if(Sharing.G2_Is_Available_LS == LS_Occupie && Sharing.G1_Need_Tb_LS == LS_Yes)
           {
               can_module.enqueue(read_V12_2);
           }
           can_module.enqueue(Pm_Power1_2);
        }
    }
    else if(plc_req == WeldingDetectionReq)
    {        

    }
    else if(plc_req == SessionStopReq)
    {        
         CAN_TX.Dc_main = 0;
    }
    else if(plc_req == ReportINITReq)
    {

    }
    else if(plc_req == ReportSLAC)
    {

    }
    else if(plc_req == ReportSDP)
    {

    }
    else if(plc_req == ReportV2G)
    {

    }
    else if(plc_req == ReportSTATE)
    {

    }
    else if(plc_req == ReportSTATEReq)
    {

    }
/****************************************************************************************/
    if(plc_req_2 == SessionSetupReq)
    {       
        CAN_TX_2.Dc_main = 0;
        CAN_TX_2.Ac_main = 1;
    }
    else if(plc_req_2 == ServiceDiscoveryReq)
    {

    }
    else if(plc_req_2 == ServicePaymentSelectionReq)
    {

    }
    else if(plc_req_2 == ContractAuthenticationReq)
    {

    }
    else if(plc_req_2 == ChargeParameterDiscoveryReq)
    {

    }
    else if(plc_req_2 == PowerDeliveryReq)
    {

    }
    else if(plc_req_2 == CableCheckReq)
    {       
        can_module.enqueue(Cable_Check_2);
    }
    else if(plc_req_2 == PreChargeReq)
    {                     
        can_module.enqueue(Pm_Power1_2);
    }
    else if(plc_req_2 == CurrentDemandReq)
    {
        if(Sharing.Is_LoadSharing == true)
        {
            if(Sharing.G1_Is_Available_LS == LS_Occupie && Sharing.G2_Need_Tb_LS == LS_Yes)
            {
                can_module.enqueue(read_V12);
            }
            can_module.enqueue(Pm_Power1);
        }
        can_module.enqueue(Pm_Power1_2);
    }
    else if(plc_req_2 == WeldingDetectionReq)
    {

    }
    else if(plc_req_2 == SessionStopReq)
    {                                
        CAN_TX_2.Dc_main = 0;
    }
    else if(plc_req_2 == ReportINITReq)
    {

    }
    else if(plc_req_2 == ReportSLAC)
    {

    }
    else if(plc_req_2 == ReportSDP)
    {

    }
    else if(plc_req_2 == ReportV2G)
    {

    }
    else if(plc_req_2 == ReportSTATE)
    {

    }
    else if(plc_req_2 == ReportSTATEReq)
    {

    }
}
bool On_Module(int can_fd){

    if(set_parameter.PMIndividual_ED == true){
        frame.can_id  = 0x06080f80  | CAN_EFF_FLAG;
        printf("On Power Module Individual \r\n");
    }
    else{
        frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
        printf("On Power Module broadcast \r\n");
    }
    
    frame.can_dlc = 8;
    for(int i =0;i<8;i++)
    {
        frame.data[i]=boot_frame[i];
    }

    nbytes = write(can_fd, &frame, sizeof(frame));
    if (nbytes < 0) {
        printf("can raw socket write\r\n");
        //return false;
    }
    return true;
}
#ifdef BOOT
int Dcmodule::boot_dc1(){
    //if(power_module_status == 0)
    {
            frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
            frame.can_dlc = 8;
            for(int i =0;i<8;i++)    }

            {
                frame.data[i]=boot_frame[i];
            }

            nbytes = write(can_fd, &frame, sizeof(frame));
            if (nbytes < 0) {
                perror("can raw socket write");
                return 1;
            }
      // power_module_status =1;
     }
/*    usleep(10000);
    printf("\n");
    printf("boot_dc1= 0x0%03x\n",frame.can_id);
    //printf("\n");
    printf("boot frame= ");
    int j =0;
    for(j = 0;j < 8; j++)
    {
        printf("0x0%x ",frame.data[j]);
        //printf("%d\n", j);
    }
    return 0;
*/
}

}

// boot frame for dc module 2...............
int Dcmodule::boot_dc2(){
    frame.can_id  = 0X06080780  | CAN_EFF_FLAG;
    frame.can_dlc = 8;

    for(int i =0;i<8;i++)
    {
        frame.data[i]=boot_frame[i];
    }

    nbytes = write(s, &frame, sizeof(frame));
    if (nbytes <0) {
        perror("can raw socket write");
        return false;
    }
    return true;
}
#endif
////////////volatge conversion////////////////////////////
/*
 *
 *  brief Dcmodule::voltage_conv
 */
bool Off_Module(int can_fd){
    printf("Off Power Module\r\n");              
    if(set_parameter.PMIndividual_ED == true){
        frame.can_id  = 0x06080f80  | CAN_EFF_FLAG;
    }
    else{
        frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    }
    frame.can_dlc = 8;
    for(int i =0;i<8;i++)
    {
        frame.data[i]=shutdown_frame[i];
    }

    nbytes = write(can_fd, &frame, sizeof(frame));
    if (nbytes <0) {
        printf("can raw socket write \r\n");
        //return true;
    }
    return false;
}
/*
void Dcmodule::voltage_conv(float volt_buffer){

    myfloat var;
    long int hex=0, j=1, remain;
   // volt_buffer_1 = (unsigned int)volt_buffer;

#ifdef PMODULE
    printf("volt_buffer=%d",volt_buffer);
#endif

    var.f = volt_buffer;
    volt_buffer = 0;
    printIEEE(var);
    for(int q=0;q<=31;q++)
    {
        remain=y[q];
        hex=hex+remain*j;
        j=j*2;
    }

 //   qDebug() <<"Hex: " << QString::number(hex, 16).toUpper();

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3] = 0x21;// assign voltage
    frame.data[5] = hex>>16;
    //volt_buffer=hex>>24;
 //   qDebug() <<"5 pOS Hex: " << QString::number(frame.data[5], 16).toUpper();
    frame.data[4]= hex>>24;
 //   qDebug() <<"4 pOS Hex: " << QString::number(frame.data[4], 16).toUpper();
  //  dummy=hex>>8;
    frame.data[6] = 0;//(quint8)hex>>8;
  //  dummy=hex;
    frame.data[7] = 0;//(quint8)hex;
    hex =0;
}
////////////////////current conversion//////////////////////////////////
void Dcmodule::current_conv(float buffer)
{
    myfloat var;
    uint8_t dummy;
    long int hex=0, j=1, remain;

    var.f = buffer/30.0f;

    printIEEE(var);
    for(int q=0;q<=31;q++)
    {
        remain=y[q];
        hex=hex+remain*j;
        j=j*2;
    }

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3]=0x22;

#ifdef PMODULE
    printf("\r\n");
    printf("buffer value in decimal current dc=%f",var.f);
#endif

    dummy=hex>>8;
    frame.data[6] = dummy;
    dummy=hex;
    frame.data[7] = dummy;

    dummy=hex>>16;
    frame.data[5] = dummy;
    dummy=hex>>24;
    frame.data[4]= dummy;
    buffer = dummy =0;
    hex =0;
}*/
int  tempbind(){
    Dcmodule pdc;
    int ret;
    printf("Waiting for CAN-id_0\r\n");
    can_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW); //SOCK_DGRAM  SOCK_RAW
    if (can_fd < 0) {
        perror("Socket");
        return 1;
    }

    can2_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW); //SOCK_DGRAM  SOCK_RAW
    if (can2_fd < 0) {
        perror("Socket");
        return 1;
    }

    strcpy(ifr.ifr_name, "can0" );
    ioctl(can_fd, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(can_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return 1;
    }

    strcpy(ifr.ifr_name, "can1" );
    ioctl(can2_fd, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(can2_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return 1;
    }

    ret = pdc.can_setting(dev_name, can_baudrate, 1);
    if( ret < 0){
        printf("Set can device %s failed!\r\n",dev_name);
        exit(EXIT_FAILURE);
    }

    ret = pdc.can_setting(dev_name_2, can_baudrate, 1);
    if( ret < 0){
        printf("Set can device %s failed!\r\n",dev_name_2);
        exit(EXIT_FAILURE);
    }

    struct can_filter rfilter[3];
    rfilter[0].can_id  =  0x060f8000;// 0x060F8411;
    rfilter[0].can_mask= CAN_EFF_MASK;

    rfilter[1].can_id  = 0x060f8008;// 0x060F8401;
    rfilter[1].can_mask= CAN_EFF_MASK;

    rfilter[2].can_id  =  0x0A100100;
    rfilter[2].can_mask= CAN_EFF_MASK;

    setsockopt(can_fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
    setsockopt(can2_fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

    return 0;
}
void rcvP12_v(int can_fd){
    Dcmodule pdc;

    frame.can_id  =  0x06080f80| CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        frame.data[i]=read_volatge[i];
    }
    if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        printf(" can voltage write frame error module 1");
        return ;
    }

#ifdef SIXTEE
     frame.can_id  =  0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_volatge[i];
     }

     if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can voltage write frame error module 2");
         return ;
     }
#endif
     return;
}
void rcvP12_i(int can_fd){
    Dcmodule pdc;

    frame.can_id  =  0x06080f80 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG"//0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        frame.data[i]=read_current[i];
    }
    if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        printf(" can current write frame error module 1");
        return ;
    }

#ifdef SIXTEE
     frame.can_id  = 0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_current[i];
     }

     if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can current write frame error module 2");
         return ;
     }
#endif
     return;
}
int powerdc(int can_fd ,float voltage,float current){

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3] = 0x21;// assign voltage

    split_int.dfloat = voltage;

    frame.data[5] = split_int.byte[2];
    frame.data[4]= split_int.byte[3];
    frame.data[6] = 0; //(quint8)hex>>8;
    frame.data[7] = 0; //(quint8)hex;

    if(set_parameter.PMIndividual_ED == true){
        frame.can_id  = 0x06080f80  | CAN_EFF_FLAG;
    }
    else{
        frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    }

    frame.can_dlc = 8;
    if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        return 1;
    }      
    split_int.dfloat = current/30.0f;

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3]=0x22;

    frame.data[6] = split_int.byte[1];
    frame.data[7] = split_int.byte[0];
    frame.data[5] = split_int.byte[2];
    frame.data[4] = split_int.byte[3];

  // frame.can_id  = 0x060C1781 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG"
    if(set_parameter.PMIndividual_ED == true){
        frame.can_id  = 0x06080f80  | CAN_EFF_FLAG;
    }
    else{
        frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    }

    frame.can_dlc = 8;
    if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        return 1;
    }
    return 0;
}
void rcvS12(int can_fd,unsigned char phase){

    frame.can_id  =  0x06080f80| CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        if(phase == 1)
        {
            frame.data[i]=read_Status_A[i];
        }
        else if(phase == 2)
        {
            frame.data[i]=read_Status_B[i];
        }
        else if(phase == 3)
        {
            frame.data[i]=read_Status_C[i];
        }
    }
    if (write(can_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        printf(" can voltage write frame error module 1");
        return ;
    }
#ifdef SIXTEE
     frame.can_id  =  0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_Status[i];
     }

     if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can voltage write frame error module 2");
         return ;
     }
#endif
     return;
}
#ifdef M2
int  tempbind_2(){
    Dcmodule pdc;
    int ret;

    printf("Waiting for CAN-id_2\r\n");
    can2_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW); //SOCK_DGRAM  SOCK_RAW
    if (can2_fd < 0) {
        perror("Socket");
        return 1;
    }

    strcpy(ifr_2.ifr_name, "can1" );
    ioctl(can2_fd, SIOCGIFINDEX, &ifr_2);

    memset(&addr_2, 0, sizeof(addr_2));
    addr_2.can_family = AF_CAN;
    addr_2.can_ifindex = ifr_2.ifr_ifindex;

    if (bind(can2_fd, (struct sockaddr *)&addr_2, sizeof(addr_2)) < 0) {
        perror("Bind");
        return 1;
    }

    ret = pdc.can_setting(dev_name_2, can_baudrate, 1);
    if( ret < 0){
        printf("Set can device %s failed!\r\n",dev_name);
        exit(EXIT_FAILURE);
    }

    struct can_filter rfilter[3];
    rfilter[0].can_id  =  0x060f8000;// 0x060F8411;
    rfilter[0].can_mask= CAN_EFF_MASK;

    rfilter[1].can_id  = 0x060f8008;// 0x060F8401;  //0x060F8005;
    rfilter[1].can_mask= CAN_EFF_MASK;

    rfilter[2].can_id  =  0x0A100100;
    rfilter[2].can_mask= CAN_EFF_MASK;

    setsockopt(can2_fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
    return 0;
}

/*bool Off_Module_2(){
    printf("Off Power Module\r\n");
    frame.can_id  = 0x0607ff80  | CAN_EFF_FLAG;
    frame.can_dlc = 8;

    for(int i =0;i<8;i++)
    {
        frame.data[i]=shutdown_frame[i];
    }

    nbytes = write(can2_fd, &frame, sizeof(frame));
    if (nbytes <0) {
        printf("can raw socket write \r\n");
        return true;
    }
    return false;
}
bool On_Module_2(){

    printf("On Power Module\r\n");
    frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    frame.can_dlc = 8;
    for(int i =0;i<8;i++)
    {
        frame.data[i]=boot_frame[i];
    }

    nbytes = write(can2_fd, &frame, sizeof(frame));
    if (nbytes < 0) {
        printf("can raw socket write\r\n");
        return false;
    }
    return true;
}
int powerdc_2(float voltage,float current){

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3] = 0x21;// assign voltage

    split_int.dfloat = voltage;

    frame.data[5] = split_int.byte[2];

//    qDebug() <<"5 pOS Hex: " << QString::number(frame.data[5], 16).toUpper();
    frame.data[4]= split_int.byte[3];
  //  qDebug() <<"4 pOS Hex: " << QString::number(frame.data[4], 16).toUpper();

    frame.data[6] = 0;//(quint8)hex>>8;

    frame.data[7] = 0;//(quint8)hex;

    //frame.can_id  = 0x060C1781 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG"
    frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    frame.can_dlc = 8;

    if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {

        return 1;
    }
        ///////////check current//////////////////////////

    //buffer=current;
    split_int.dfloat = current/30.0f;
 //   pdc.current_conv(current);

    frame.data[0]=0x03;
    frame.data[1]=0x00;
    frame.data[2]=0x00;
    frame.data[3]=0x22;

    frame.data[6] = split_int.byte[1];
    frame.data[7] = split_int.byte[0];

    frame.data[5] = split_int.byte[2];
    frame.data[4]= split_int.byte[3];

  //  frame.can_id  = 0x060C1781 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG"
    frame.can_id  = 0X0607ff80  | CAN_EFF_FLAG;
    frame.can_dlc = 8;

    if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        return 1;
    }
    return 0;
}
void rcvP12_i_2(){
    Dcmodule pdc;

    frame.can_id  =  0x06080f80 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG"//0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        frame.data[i]=read_current[i];
    }
    if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
      printf(" can current write frame error module 1");
        return ;
    }

#ifdef SIXTEE
     frame.can_id  = 0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_current[i];
     }

     if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can current write frame error module 2");
         return ;
     }
#endif
     return;
}
void rcvS12_2(unsigned char phase){
   // Dcmodule pdc;
    frame.can_id  =  0x06080f80| CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        if(phase == 1)
        {
            frame.data[i]=read_Status_A[i];
        }
        else if(phase == 2)
        {
            frame.data[i]=read_Status_B[i];
        }
        else if(phase == 3)
        {
            frame.data[i]=read_Status_C[i];
        }
    }

    if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        printf(" can voltage write frame error module 1");
        return ;
    }

#ifdef SIXTEE
     frame.can_id  =  0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_Status[i];
     }

     if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can voltage write frame error module 2");
         return ;
     }
#endif
     return;
}
void rcvP12_v_2(){
   // Dcmodule pdc;
    frame.can_id  =  0x06080f80| CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C1781
    frame.can_dlc = 8;
    for (i = 0; i < frame.can_dlc; i++)
    {
        frame.data[i]=read_volatge[i];
    }
    if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        printf(" can voltage write frame error module 1");
        return ;
    }

#ifdef SIXTEE
     frame.can_id  =  0x06080780 | CAN_EFF_FLAG; //for extended id, have to masking with "CAN_EFF_FLAG" //0x060C0781
     frame.can_dlc = 8;
     for (i = 0; i < frame.can_dlc; i++)
     {
         frame.data[i]=read_volatge[i];
     }

     if (write(can2_fd, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
         printf(" can voltage write frame error module 2");
         return ;
     }
#endif
     return;
}*/
void Dcmodule::IO2_transmit(void)
{
    frame.can_id  = 0x0A105695 | CAN_EFF_FLAG;
    frame.can_dlc = 8;
    frame.data[0] = 0xff;
    frame.data[1] = CAN_TX_2.Ac_main;    
    frame.data[3] = CAN_TX_2.Precharge;
    frame.data[2] = CAN_TX_2.Dc_main;

    if((CCS2.Error == NoError) /*||(CCS2.ALM_status == true)*/)
    {
        frame.data[4] = 0x00;
    }
    else
    {
        frame.data[4] = 0xA5;
        printf("ERROR+---%d\n ",CCS2.Error);
    }
    frame.data[5] = CAN_TX_2.Load_Sharing;
    frame.data[6] = CAN_TX_2.HardReset; // Hardreset 0xA5
    frame.data[7] = 0xff;

//    if(CAN_TX_2.Load_Sharing == 0)
//    {
//        if(Sharing.G1_Need_Tb_LS == LS_Active)
//        {
//            Sharing.G1_Need_Tb_LS = LS_No;
//        }
//        if(Sharing.G2_Need_Tb_LS == LS_Active)
//        {
//             Sharing.G2_Need_Tb_LS = LS_No;
//        }
//    }

    nbytes = write(can2_fd, &frame, sizeof(frame));
    if (nbytes < 0) {
        perror("can raw socket write");
        return ;
    }
    return;
}
#endif
void Dcmodule::IO_transmit(void)
{
    frame.can_id  = 0x0A105695 | CAN_EFF_FLAG;
    frame.can_dlc = 8;
    frame.data[0] = 0xff;
    frame.data[1] = CAN_TX.Ac_main;
    frame.data[2] = CAN_TX.Dc_main;
    frame.data[3] = CAN_TX.Precharge;

    if((CCS.Error == NoError) /*|| (CCS.ALM_status == true)*/)
    {
        frame.data[4] = 0x00;
    }
    else
    {
        frame.data[4] = 0xA5;
        printf("ERROR+---%d\n ",CCS.Error);
    }
    frame.data[5] = 0xff;
    frame.data[6] = CAN_TX.HardReset; // 0xA5 HardReset
    frame.data[7] =  (CAN_TX.Dc_main == 0xA5) ? 0xA5 : ((CAN_TX_2.Dc_main == 0xA5) ? 0xA5 : 0);

    nbytes = write(can_fd, &frame, sizeof(frame));
    if(nbytes < 0) {
        perror("can raw socket write");
        return;
    }
    return;
}
void Dcmodule::Imd_StatusBit(unsigned char  hex)
{
    quint8 result,result1,result2;
    result=((hex>>7)&01);
    if(result==1){
        //printf("result=%d\n",result);
#ifdef IMD_Debug
        printf("Hardware Error occur\n");
#endif
    }

    result=((hex>>6)&01);
    if(result==1){
        //printf("result=%d\n",result);
#ifdef IMD_Debug
        printf("No Estimate Error occur\n");
#endif
    }

    result=((hex>>5)&01);
    if(result==1){
#ifdef IMD_Debug
        printf("High Uncertanity occur\n");
#endif
    }

    result=((hex>>4)&01);
    if(result==1){
        //printf("result=%d\n",result);
#ifdef IMD_Debug
        printf("reserve bit\n");
#endif
    }

    result=((hex>>3)&01);
    if(result==1){
#ifdef IMD_Debug
        printf("result=%d\n",result);
        printf("High voltage occur\n");
#endif
    }

    result=((hex>>2)&01);
    if(result==1){
#ifdef IMD_Debug
        printf("result=%d\n",result);
        printf("Low volatge error occur\n");
#endif
    }

    result=((hex>>1)&01);
#ifdef IMD_Debug
    printf("result8=%d\n",result);
#endif

    result2=(hex&01);
#ifdef IMD_Debug
    printf("result9=%d\n",result);
#endif

    if(result & result2)
     {
#ifdef IMD_Debug
        printf("isolation fault\n");
#endif
    }
    else if(result | result2)
    {
#ifdef IMD_Debug
        printf("isolation status warning\n");
#endif
    }
}
void Dcmodule::can_module_run(void)
{  
    int num_16_high,num_16_low;
    bool UnderVoltage_ccs1,OverVoltage_ccs1,OverCurrentFailure_ccs1,PowerLoss_ccs1,MeterFailure_ccs1;
    bool Max_Bettery_voltage;
    bool Isolation_Status;
    long int num;
    bool power_module_status = 0,power_module_status_2=0;
    bool chasis_connection;
    bool Powersuppyleval;
    bool  ExitationVoltageLeval;
    bool  Vx1andVx2connection;
    bool  Vx1;
    bool  Vx2;

     qDebug() << "can thread" << QThread::currentThreadId();
     ptr_rf = new RFID(this);
     int last_signal = 1;
     int call_io = 0;
     Dcmodule d;
     int rfidfd = -1;
     int ret = -1;
     rfidfd =   ptr_rf->keypad_init("/dev/input/event4");
     if(rfidfd ==  -1)
     {
       CCS.SCAN_TAGID = -1;
     }
#ifdef NO_PLC_THREAD
    ptr_ccs = new dcComboPLC(this,0);   
#ifdef M2
    ptr2_ccs = new dccomboplc_2(this);
#endif
   /*******************DC cOMBOpLC*********************************/
   int length = 0;
   int size = 0,size_2;
   int tty_fd_PLC,tty2_fd_PLC;
   char frame_232[TTY_READ_BUFFER_SIZE];
   QByteArray databuf,databuf_2;
   static QByteArray rcvData,rcvData_2;
   tty_fd_PLC = ptr_ccs-> OpenSerialPort("/dev/ttymxc1");
#ifdef M2
   tty2_fd_PLC = ptr2_ccs-> OpenSerialPort("/dev/ttymxc2");
#endif
   QThread::msleep(100);can_fd
   ptr_ccs->Request_ReportSTATE(tty_fd_PLC);
#ifdef M2
   ptr2_ccs->Request_ReportSTATE(tty2_fd_PLC);
#endif
#endif
    while (1) {        
        if(++call_io > 8)
        {
                can_module.enqueue(Io_Card);
                can_module.enqueue(Io_Card_2);

            //can_module.enqueue(V_read_PhaseA_1);
            //can_module.enqueue(V_read_PhaseB_1);
            //can_module.enqueue(V_read_PhaseC_1);            
            call_io = 0;
        }
        if((call_io % 2) == 0)
        {
            if(can_module.isEmpty() == false)
            {
                 switch(can_module.dequeue())
                 {
                    case Pm_Off :
                    {
                         if(power_module_status == 1)
                         {
                            power_module_status = Off_Module(can_fd);
                         }
                         break;
                    }
                    case Pm_On :
                    {
                        if(power_module_status == 0)
                         {
                            power_module_status  = On_Module(can_fd);
                            if(power_module_status == false )
                            {
                               // send_signal(C_Communication_Error);
                            }
                         }
                         break;
                    }
                    case Cable_Check :
                    {
                        if(plc_req == CableCheckReq)
                         {
                            if((bIsolation_ok == 0) && (power_module_status == 1))
                            {
                                 if(powerdc(can_fd,CAN_TX.Pm1_voltage,CAN_TX.Pm1_current) == 0)
                                 {

                                 }                                 
                            }
                         }
                        break;
                    }
                    case Pm_Power1 :
                    {
                            if(power_module_status == 1)
                            {
                               powerdc(can_fd,CAN_TX.Pm1_voltage,CAN_TX.Pm1_current);
                            }
                            break;
                    }
                    case Pm_Power2 :
                    {
                              break;
                    }
                    case Io_Card :
                    {
                             IO_transmit();
                             break;
                    }
                    case read_V12 :
                    {
                            rcvP12_v(can_fd);
                            break;
                    }
                    case read_I12 :
                    {
                            rcvP12_i(can_fd);
                            break;
                    }
                    case Pm_Off_2 :
                     {
                          if(power_module_status_2 == 1)
                          {
                             power_module_status_2 = Off_Module(can2_fd);
                          }
                          break;
                     }
                    case Pm_On_2 :
                     {
                         if(power_module_status_2 == 0)
                          {
                             power_module_status_2  = On_Module(can2_fd);
                             if(power_module_status_2 == false)
                             {

                             }
                          }
                          break;
                     }
                    case Cable_Check_2 :
                     {
                         if(plc_req_2 == CableCheckReq)
                          {
                             if((bIsolation_ok == 0) && (power_module_status_2 == 1))
                             {
                                  if(powerdc(can2_fd,CAN_TX_2.Pm1_voltage,CAN_TX_2.Pm1_current) == 0)
                                  {

                                  }
                             }
                          }
                         break;
                     }
                    case Pm_Power1_2 :
                     {
                             if(power_module_status_2 == 1)
                             {
                                powerdc(can2_fd,CAN_TX_2.Pm1_voltage,CAN_TX_2.Pm1_current);
                             }
                             break;
                     }
                    case Pm_Power2_2 :
                     {
                               break;
                     }
                    case Io_Card_2 :
                     {
                              IO2_transmit();
                              break;
                     }
                    case read_V12_2 :
                     {
                             rcvP12_v(can2_fd);
                             break;
                     }
                    case read_I12_2 :
                     {
                             rcvP12_i(can2_fd);
                              break;
                     }
#ifdef NO_PLC_THREAD
                    case Stop_Charging :
                    {
                              ptr_ccs->Charger_Stop(tty_fd_PLC);
                                break;
                    }
                    case Report_state :
                    {
                           ptr_ccs -> Request_ReportSTATE(tty_fd_PLC);
                            break;
                    }
                    case Start_Charging :
                    {
                          // qDebug() << "Start_Charging .."<<endl;
                             ptr_ccs->Charger_Start(tty_fd_PLC);
                             break;
                    }
                    case HardReset_state :
                    {
                            ptr_ccs->EVSE_RESET(tty_fd_PLC);
                            break;
                    }
#endif
                    case Q_Connect :
                    {
                           send_signal(P_Connect);
                           break;
                    }
                    case Q_Discharge :
                    {
                            send_signal(P_Disconnect);
                            break;
                    }
                    case Q_Charging :
                    {
                           send_signal(P_Charging);
                           break;
                    }
                    case Q_Available :
                    {
                           send_signal(P_Available);
                           break;
                    }
                    case Q_Connect_2 :
                    {
                        send_signal(P2_Connect);
                        break;
                    }
                    case Q_Discharge_2 :
                    {
                         send_signal(P2_Disconnect);
                         break;
                    }
                    case Q_Charging_2 :
                    {
                        send_signal(P2_Charging);
                        break;
                    }
                    case V_read_PhaseA_1 :
                    {
                        rcvS12(can_fd,1);
                        break;
                    }
                    case Q_Available_2 :
                    {
                    send_signal(P2_Available);
                    break;
                    }
                    case V_read_PhaseB_1 :
                    {
                             rcvS12(can_fd,2);
                             break;
                    }
                    case V_read_PhaseC_1 :
                    {
                              rcvS12(can_fd,3);
                              break;
                    }
                    case V_read_PhaseA_2 :
                    {
                         rcvS12(can2_fd,1);
                         break;
                    }
                    case V_read_PhaseB_2 :
                    {
                          rcvS12(can2_fd,2);
                          break;
                    }
                    case V_read_PhaseC_2 :
                    {
                           rcvS12(can2_fd,3);
                           break;
                    }
#ifdef NO_PLC_THREAD
                    case RS232_ReadError_1 :
                    {
                        tty_fd_PLC = ptr_ccs-> OpenSerialPort("/dev/ttymxc1");
                        if(tty_fd_PLC == -1)
                        {                            
                            send_signal(COmm_1_232_Fail);
                        }
                        else
                        {
                            send_signal(I_O_NoError);
                        }
                         break;
                    }
                    case RS232_ReadError_2 :
                    {
                         tty2_fd_PLC = ptr2_ccs-> OpenSerialPort("/dev/ttymxc2");
                         if(tty2_fd_PLC == -1)
                         {
                             send_signal(COmm_2_232_Fail);
                         }
                         else
                         {
                             send_signal(I_O_NoError);
                         }
                          break;
                     }
#endif
                 };
            }
        }
        ret =  (can_fd == -1) ?  -1: tty_read_ready(can_fd);
        if(ret == 1)
        {           
            nbytes = read(can_fd, &frame, sizeof(struct can_frame));           
            if (nbytes < 0) {
                qDebug()<<"CAN 0 down"<<endl;
                perror("CAN 0 Read");
goto next;
            }
            if(frame.can_id == 0x860f8000)
            {
                num_16_high =(frame.data[4]<<8)|(frame.data[5]);
                num_16_low =(frame.data[6]<<8)|(frame.data[7]);

                num = 0;                
                num = (num_16_high << 16)|(num_16_low);
                if(frame.data[3] == 0x01)
                {
                    CCS.DcOutputModule_2 = *((float*)&num);
                    if(CCS.DcOutputModule_2 < 0)
                    {
                        CCS.DcOutputModule_2 = -CCS.DcOutputModule_2;
                    }                    
                }
                else if(frame.data[3] == 0x02)
                {
                    CCS.DC_Current_2 = *((float*)&num);
                    if(CCS.DC_Current_2 < 0)
                    {
                        CCS.DC_Current_2 = -CCS.DC_Current_2;
                    }
#ifdef PLC_DEBUG
                    qDebug()<<"Revieve Current PM2 : "<< CCS.DC_Current_2 <<endl;
#endif                
                }
            }
            else if(frame.can_id == 0x860F8008)
            {
                num = 0;
                num_16_high =(frame.data[4]<<8)|(frame.data[5]);
                num_16_low =(frame.data[6]<<8)|(frame.data[7]);
                num = (num_16_high << 16)|(num_16_low);

                if(frame.data[3] == 0x01)
                {
                    CCS.DcOutputModule_1 = *((float*)&num);
                    if( CCS.DcOutputModule_1 < 0)
                    {
                         CCS.DcOutputModule_1 = -CCS.DcOutputModule_1;
                    }
#ifdef PLC_DEBUG
                    qDebug()<<"Revieve Voltage PM1 : "<< CCS.DC_Voltage_1<<endl;
#endif                    
                }
                else if(frame.data[3] == 0x02)
                {
                    CCS.DC_Current_1 = *((float*)&num);
                    if(CCS.DC_Current_1  < 0)
                    {
                        CCS.DC_Current_1  = -CCS.DC_Current_1;
                    }                  
                }
                else if(frame.data[3] == 0x0c)
                {                    
                    CCS.voltage_L1 = *((float*)&num);
                     qDebug()<< "Phase A: "<< CCS.voltage_L1<<endl;
                }
                else if(frame.data[3] == 0x0d)
                {
                    CCS.voltage_L2 = *((float*)&num);;
                     qDebug()<< "Phase B: "<< CCS.voltage_L2<<endl;
                }
                else if(frame.data[3] == 0x0e)
                {
                    CCS.voltage_L3 = *((float*)&num);;
                     qDebug()<< "Phase C: "<<CCS.voltage_L3<<endl;
                }
            }
            else if(frame.can_id == 0x8A100100)
            {                
#ifdef PLC_DEBUG
                qDebug()<<"Revieve Byte PM : "<< nbytes<<endl;
                qDebug()<<"Revieve Byte FROM io card 1 : "<< nbytes<<endl;
#endif
               CAN_RX.Status_Imd = frame.data[0];
               Max_Bettery_voltage = ((CAN_RX.Status_Imd >> 3) & 01);
               Isolation_Status = ((CAN_RX.Status_Imd >> 1) & 01) | ((CAN_RX.Status_Imd >> 0) & 01);
               
//               if(Max_Bettery_voltage == 1)
//               {
//                   //printf("Max Bettery Voltage\r\n");
//               }

                CAN_RX.Error_Imd = frame.data[1];
                chasis_connection = ((CAN_RX.Error_Imd >> 5) & 01); //0 -good 1- broken
                Powersuppyleval = ((CAN_RX.Error_Imd >> 2) & 01);    // 0 -good 1 - outof range
                ExitationVoltageLeval = ((CAN_RX.Error_Imd >> 3) & 01); // 0 - correct 1 -  outofspec
                Vx1andVx2connection = ((CAN_RX.Error_Imd >> 4) & 01);   // 0 - correct 1 - reverse
                Vx1 = ((CAN_RX.Error_Imd >> 6) & 01); // 0 - good 1 - Broken
                Vx2 = ((CAN_RX.Error_Imd >> 7) & 01); // 0 - good 1 - Broken

               CAN_RX.Electricl_Isolation = (set_parameter.IsolationFault_ED == true) ? ((frame.data[2] << 8) | (frame.data[3])) : 1000;
               bool EM_Switch = ((frame.data[4] >> 0) & 1);
                CAN_RX.Dlk1_sensor = (set_parameter.DoorlOCK_ED == true) ? ((frame.data[4] >> 1) & 1) : false;               
               bool Reset_Key = (set_parameter.DoorlOCK_ED == true) ? ((frame.data[4] >> 3) & 1) : false;
                //Reset_Key = ((frame.data[4] >> 3) & 1);
               CAN_RX.AC_Main_Contactor_res = (frame.data[4] >> 4) & 1;
               CAN_RX.RCD_Detect = ((frame.data[4] >> 6) & 01);

               CCS.Tempreture_exhaust = frame.data[5];
               CCS.Tempreture_dcP = frame.data[6];
               CCS.Tempreture_dcN = frame.data[7];

            //   qDebug()<<"tempreture : "<<CCS.Tempreture_exhaust <<endl;

               if(CCS.voltage_L1 < set_parameter.Under_Voltage || CCS.voltage_L2 < set_parameter.Under_Voltage || CCS.voltage_L3 < set_parameter.Under_Voltage)
               {
                    if(CCS.voltage_L1 == -1 && CCS.voltage_L2 == -1 && CCS.voltage_L3 == -1)
                    {
                         if(CAN_RX.AC_Main_Contactor_res == false)
                         {
                               PowerLoss_ccs1 = true;
                            CCS2.Error =  CCS.Error = M_PowerSwitchFailure;
                            CCS2.Reson =  CCS.Reson = PowerLoss;
                             MeterFailure_ccs1 = false;
                         }
                         else
                         {
                             MeterFailure_ccs1 = true;
                             CCS2.Error = CCS.Error = PowerMeterFailure;
                             CCS2.Reson =CCS.Reson = Local;
                         }
                    }
                    else
                    {
                        UnderVoltage_ccs1 = true;
                        CCS2.Error = CCS.Error = UnderVoltage;
                        CCS2.Reson = CCS.Reson = Local;
                    }
               }
               else if(CCS.Error == PowerMeterFailure || CCS.Error == M_PowerSwitchFailure || CCS.Error == UnderVoltage)
               {
                   MeterFailure_ccs1 = false;
                   PowerLoss_ccs1 = false;
                   UnderVoltage_ccs1 = false;
               }

               if(CCS.Reson != PowerLoss)
               {
                    if(CAN_RX.RCD_Detect == 1)
                    {
                        printf("RCD detect...\r\n");
                        CCS2.Error =  CCS.Error = InternalError;
                        CCS2.Reson= CCS.Reson = Other;
                    }
                    if(EM_Switch == 1)
                    {
                         CCS2.Error = CCS.Error = InternalError;
                         CCS2.Reson =  CCS.Reson = EmergencyStop;
                         CAN_RX.Em_switch = 1;
                    }
                    else
                    {
                       CAN_RX.Em_switch = 0;
                    }

                    if(CAN_RX.Dlk1_sensor == true)
                    {
                        CCS2.Error = CCS.Error = InternalError;
                    }

                   if(Reset_Key == 1 )
                   {
                      CCS2.Error =  CCS.Error = InternalError;
                      CCS2.Reson =  CCS.Reson = HardReset;
                       CAN_RX.Reset_Key = 1;
                   }
                   else if(CAN_RX.Reset_Key == 1)
                   {
                       CAN_RX.Reset_Key = 0;
                   }
                   if(chasis_connection)
                   {
                  //      printf("chasis connection Broken: \r\n");
                     CCS2.Reson = CCS.Reson = Local;
                      CCS2.Error =  CCS.Error = GroundFailure;
                       chasis_connection = 1;
                   }
                   if(CCS.voltage_L1 > set_parameter.Over_Voltage || CCS.voltage_L2 > set_parameter.Over_Voltage || CCS.voltage_L3 > set_parameter.Over_Voltage)
                   {
                       printf("Over Voltage L1 : %f - L2 : %f - L3 : %f \r\n",CCS.voltage_L1 ,CCS.voltage_L2,CCS.voltage_L3);                     
                       OverVoltage_ccs1 = true;
                      CCS2.Error =  CCS.Error = OverVoltage;
                      CCS2.Reson =  CCS.Reson = Local;
                   }
                   else 
                   {
                       OverVoltage_ccs1 = false;
                   }
                   if(CCS.current_L1 > set_parameter.Over_Current_ccs || CCS.current_L2 > set_parameter.Over_Current_ccs || CCS.current_L3 > set_parameter.Over_Voltage)
                   {
                       printf("Over Current L1 : %f - L2 : %f - L3 : %f \r\n",CCS.voltage_L1 ,CCS.voltage_L2,CCS.voltage_L3);
                       OverCurrentFailure_ccs1 = true;
                      CCS2.Error =  CCS.Error = OverCurrentFailure;
                   }
                   else
                   {                      
                       OverCurrentFailure_ccs1 = false;
                   }
              }
               if(EM_Switch || CAN_RX.Dlk1_sensor || CAN_RX.RCD_Detect || Reset_Key || chasis_connection || CAN_RX.AC_Main_Contactor_res == false || MeterFailure_ccs1 || PowerLoss_ccs1 || OverCurrentFailure_ccs1 || OverVoltage_ccs1 || UnderVoltage_ccs1)
               {
                   if((EM_Switch == true) && last_signal != I_O_EMPress)
                   {
                       send_signal(I_O_EMPress);
                       last_signal = I_O_EMPress;
                   }
                   if(((EM_Switch == false) && (CAN_RX.AC_Main_Contactor_res == false) ) && last_signal != I_O_WaitForACMains)
                   {
                       send_signal(I_O_WaitForACMains);
                       last_signal = I_O_WaitForACMains;
                   }
                   else if((CAN_RX.Dlk1_sensor == true) && last_signal != I_O_DoorLock)
                   {
                       send_signal(I_O_DoorLock);
                       last_signal = I_O_DoorLock;
                   }
                   else if((Reset_Key == true) && last_signal != I_O_ResetKey)
                   {
                       send_signal(I_O_ResetKey);
                       last_signal = I_O_ResetKey;
                   }
                   else if((chasis_connection == true) && last_signal != I_O_GNDFalut)
                   {
                       send_signal(I_O_GNDFalut);
                       last_signal = I_O_GNDFalut;
                       CAN_TX.Dc_main =0;
                       CAN_TX.Precharge =0;
                       can_module.enqueue(Io_Card);
                       can_module.enqueue(Pm_Off);
                   }
                   else if((MeterFailure_ccs1 == true) && last_signal != M_MeterFailure)
                   {
                       send_signal(M_MeterFailure);
                       last_signal = M_MeterFailure;
                   }
                   else if((PowerLoss_ccs1 == true) && last_signal != M_PowerSwitchFailure)
                   {
                       send_signal(M_PowerSwitchFailure);
                       last_signal = M_PowerSwitchFailure;
                   }
                   else if((UnderVoltage_ccs1 == true) && last_signal != M_Under_Voltage)
                   {
                       send_signal(M_Under_Voltage);
                       last_signal = M_Under_Voltage;
                   }
                   else if((OverCurrentFailure_ccs1 == true) && last_signal != M_Over_Current)
                   {
                       send_signal(M_Over_Current);
                       last_signal = M_Over_Current;
                   }
                   else if((OverVoltage_ccs1 == true) && last_signal != M_Over_Voltage)
                   {
                       send_signal(M_Over_Voltage);
                       last_signal = M_Over_Voltage;
                   }
                   else if((CAN_RX.RCD_Detect == 1) && last_signal != I_O_RCDdetect)
                   {
                       send_signal(I_O_RCDdetect);
                       last_signal = I_O_RCDdetect;
                   }
               }
               else
               {
                    OverVoltage_ccs1 = OverCurrentFailure_ccs1 = UnderVoltage_ccs1 = PowerLoss_ccs1 = MeterFailure_ccs1 = false;
                    chasis_connection = Reset_Key = CAN_RX.Dlk1_sensor = EM_Switch = false;
                    if(last_signal != I_O_NoError)
                    {
                        send_signal(I_O_NoError);
                        last_signal = I_O_NoError;
                        CCS2.Error =  CCS.Error = NoError;
                        CCS2.Reson =  CCS.Reson = Other;
                    }                
               }
          }
        }
 next :
        if(rfidfd > 0)
        {
            if(rfid_read_ready(rfidfd) == 1)
             {
               if(ptr_rf->readrfid_COM(rfidfd) ==  -1)
               {
                   CCS.SCAN_TAGID = -1;
                   rfidfd = -1;
               }
             }
        }
#ifdef NO_PLC_THREAD
        ret =  (tty_fd_PLC == -1) ?  -1: tty_read_ready(tty_fd_PLC);
        if(ret == 1)
        {
            int bytes = tty_read(tty_fd_PLC, frame_232);
            if(bytes < 0)
            {
                tty_fd_PLC = -1;
                perror("232 0 Read Error");
                rcvData.clear();
                can_module.enqueue( RS232_ReadError_1);
goto next_2;
            }
#ifdef PLC_DEBUG
            qDebug()<<"Revieve Byte GQ : "<< bytes<<endl;
#endif
            databuf = QByteArray(reinterpret_cast<char*>(frame_232), bytes);
            rcvData.append( databuf );
            if(rcvData.size() > 4)
            {
                size = rcvData.size();
                if(size > 4 && rcvData.at(0) == 'G' && rcvData.at(1) == 'Q')
                {                     
                    if( size >= rcvData.at(3) + 8)
                    {
                        length = rcvData.at(3);
                        if(set_parameter.TestMode_ED == false)
                        {
                            ptr_ccs->recieveData(rcvData.mid(0, length + 8),tty_fd_PLC);
                        }
                        rcvData.remove(0, length+8);
                    }                   
                      /*    else
                        {
                            break;
                        }
                     */
                }
                else if(size > 4)
                {
                    rcvData.clear();
                }
            }
        }
 next_2 :
#endif
/******************************************************************************************/
#ifdef NO_PLC_THREAD
        ret =  (tty2_fd_PLC == -1) ?  -1: tty_read_ready(tty2_fd_PLC);
        if(ret == 1)
        {
            int bytes = tty_read(tty2_fd_PLC, frame_232);
#ifdef PLC_DEBUG
            qDebug()<<"Revieve Byte GQ : "<< bytes<<endl;
#endif
            if(bytes < 0)
            {
                tty2_fd_PLC = -1;
                perror("232 0 Read Error");
                rcvData_2.clear();
                can_module.enqueue( RS232_ReadError_2);
goto next_4;
            }
            databuf_2 = QByteArray(reinterpret_cast<char*>(frame_232), bytes);
            rcvData_2.append( databuf_2 );
            if(rcvData_2.size() > 4)
            {
                size_2 = rcvData_2.size();
                if(size_2 > 4 && rcvData_2.at(0) == 'G' && rcvData_2.at(1) == 'Q')
                {
                    if( size_2 >= rcvData_2.at(3) + 8)
                    {
                        length = rcvData_2.at(3);

                        ptr2_ccs->recieveData(rcvData_2.mid(0, length + 8),tty2_fd_PLC);
                        rcvData_2.remove(0, length+8);
                    }
                }
            }
        }
next_4 :
#endif
#ifdef M2
         ret =  (can2_fd == -1) ?  -1: tty_read_ready(can2_fd);
        if(ret == 1)
        {
            nbytes = read(can2_fd,&frame, sizeof(struct can_frame));
            if (nbytes < 0) {
                qDebug()<<"CAN 1 down"<<endl;
                perror("Read");
goto next_3;
            }
            if(frame.can_id == 0x860f8000)
            {
                num_16_high =(frame.data[4]<<8)|(frame.data[5]);
                num_16_low =(frame.data[6]<<8)|(frame.data[7]);
                num = 0;
                num = (num_16_high << 16)|(num_16_low);
                if(frame.data[3] == 0x01)
                {
                    CCS2.DcOutputModule_2 = *((float*)&num);
                    if(CCS2.DcOutputModule_2 < 0)
                    {
                        CCS2.DcOutputModule_2 = -CCS2.DcOutputModule_2;
                    }
                }
                else if(frame.data[3] == 0x02)
                {
                    CCS2.DC_Current_2 = *((float*)&num);
                    if(CCS2.DC_Current_2 < 0)
                    {
                        CCS2.DC_Current_2 = -CCS2.DC_Current_2;
                    }
#ifdef PLC_DEBUG
                    qDebug()<<"Revieve Current PM2 : "<< CCS2.DC_Current_2 <<endl;
#endif
                }
                else if(frame.data[3] == 0x40)
                {
                    CCS2.PM_Status_2 = num;
                     qDebug()<<"Revieve Status PM2_2 : "<< CCS2.PM_Status <<endl;
                }
            }
            else if(frame.can_id == 0x860F8008)
            {
                num = 0;
                num_16_high =(frame.data[4]<<8)|(frame.data[5]);
                num_16_low =(frame.data[6]<<8)|(frame.data[7]);
                num = (num_16_high << 16)|(num_16_low);

                if(frame.data[3] == 0x01)
                {
                    CCS2.DcOutputModule_1 = *((float*)&num);
                    if( CCS2.DcOutputModule_1 < 0)
                    {
                         CCS2.DcOutputModule_1 = -CCS2.DcOutputModule_1;
                    }
#ifdef PLC_DEBUG
                    qDebug()<<"Revieve Voltage PM1 : "<< CCS2.DC_Voltage_1<<endl;
#endif                  
                }
                else if(frame.data[3] == 0x02)
                {
                    CCS2.DC_Current_1 = *((float*)&num);
                    if(CCS2.DC_Current_1  < 0)
                    {
                        CCS2.DC_Current_1  = -CCS2.DC_Current_1;
                    }
                  //  qDebug()<<"Revieve Current PM1 : "<< CCS2.DC_Current_1 <<endl;
                }
                else if(frame.data[3] == 0x40)
                {
                    CCS2.PM_Status = num;
                     qDebug()<<"Revieve Status PM2_1 : "<< CCS2.PM_Status <<endl;
                }
            }
            else if(frame.can_id == 0x8A100100)
            {
                CAN_RX_2.Status_Imd = frame.data[0];
                Max_Bettery_voltage = ((CAN_RX.Status_Imd >> 3) & 01);
                Isolation_Status = ((CAN_RX.Status_Imd >> 1) & 01) | ((CAN_RX.Status_Imd >> 0) & 01);

                CAN_RX_2.Error_Imd = frame.data[1];
                chasis_connection = ((CAN_RX_2.Error_Imd >> 5) & 01); //0 -good 1- broken
                Powersuppyleval = ((CAN_RX_2.Error_Imd >> 2) & 01); // 0 -good 1 - outof range
                ExitationVoltageLeval = ((CAN_RX_2.Error_Imd >> 3) & 01); // 0 - correct 1 -  outofspec
                Vx1andVx2connection = ((CAN_RX_2.Error_Imd >> 4) & 01); // 0 - correct 1 - reverse
                Vx1 = ((CAN_RX_2.Error_Imd >> 6) & 01); // 0 - good 1 - Broken
                Vx2 = ((CAN_RX_2.Error_Imd >> 7) & 01); // 0 - good 1 - Broken
                CAN_RX_2.Electricl_Isolation = (set_parameter.IsolationFault_ED == true) ? ((frame.data[2] << 8) | (frame.data[3])) : 1000;
                CCS2.Tempreture_exhaust = frame.data[5];
                CCS2.Tempreture_dcP = frame.data[6];
                CCS2.Tempreture_dcN = frame.data[7];
            }
        }
next_3:
#endif
         QThread::msleep(100);
    }
}
