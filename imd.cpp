#include "imd.h"
#include <QDebug>

static double buffer=0,t=0,x=0;
static int volt_buffer=0;
static int y[31];
static int num;
static float f;
int g=1;
int check=1;
static bool fl=0;
static double ch=0,ch2=0;
static int ret = 0;
static int ret1 = 0;
static int  i;
static int nbytes;
static struct sockaddr_can addr;
static struct ifreq ifr;
static struct can_frame frame;
unsigned int volt=82;
double current2=15;

double split=0;

//#define IMD_Debug 1
uint16_t rfilter=0;


unsigned int Voltage[8];
unsigned int isolation[8];
unsigned int battery[8];
unsigned int Resistance[8];
unsigned int Error[8];
//unsigned int hex=0,result2=0;
unsigned int hex_error=0,result_error=0;


/////////////////////////////////IMD////////////////////

uint16_t result;
long int num1  = 0;
char * str ;
int para1=0;
//int ret1 = 0;
unsigned long int can_baudrate_imd = 125000;
const char* dev_name_imd="can0";

int s2;
int nbytes2;
unsigned int vp,vn,vb,rp,rm,iso_value;
double rm_float,rp_float;



Imd::Imd(QObject *parent) : QObject(parent)
{

}

void Imd::delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);

}

int Imd::can_setting_imd(const char* can, const int bitrate, int enable) //call in declaration
{
    int ret = 0;
    char cmdline[128] = { '\0' };

    if(enable == 1){
        sprintf(cmdline,
                "ip link set %s type can bitrate %ld triple-sampling on; ifconfig %s up",
                dev_name_imd, can_baudrate_imd, dev_name_imd);
    }

    ret = system(cmdline);
    sleep(1);
    return WEXITSTATUS(ret);
}
int Imd::Ethernet_connection(void) //call in declaration
{
    int ret = 0;
    char cmdline[128] = { '\0' };

    sprintf(cmdline,"ifconfig eth0 172.16.3.239 netmask 255.255.252.0");
    ret = system(cmdline);

    sprintf(cmdline,"route add default gw 172.16.1.1 eth0");
    ret = system(cmdline);

    return WEXITSTATUS(ret);
}
//////////////imd_test/////////////////

int Imd::VoltageVP(){
    int i;

    unsigned int hex=0,result2=0;
    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;


    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE3;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if(nbytes < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }
    /*
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
    */

    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Read");
        return 1;
    }
#ifdef MD_Debug
    cout<<"\n";
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
#endif
    ///////	/////////////////////////////////////////////////////////////////
    if(frame.data[0]==0xe3){
#ifdef IMD_Debug
        printf("Voltage= ");
#endif
        for(int i=0;i<frame.can_dlc;i++){
            Voltage[i]=frame.data[i];
#ifdef IMD_Debug
            printf(" 0x%x  ",Voltage[i]);
#endif
        }

        vp=0;
        vn=0;
        vp=(Voltage[2]<<8)|(Voltage[3]);
        vn=(Voltage[5]<<8)|(Voltage[6]);


        int total=vp+vn;
#ifdef IMD_Debug
        printf(" vp=%d  vn=%d total=%d \n",vp,vn,total);
#endif
        total=0;
    }
    /////////////////////////////isolation////////////////////////////

    else if(frame.data[0]==0xe0){
#ifdef IMD_Debug
        printf("Isolation= ");
#endif
        for(int i=0;i<frame.can_dlc;i++){
            isolation[i]=frame.data[i];
#ifdef IMD_Debug
            printf(" 0x%x  ",isolation[i]);
#endif
        }

        iso_value=(isolation[2]<<8)|(isolation[3]);
        double g=iso_value*0.001;
#ifdef IMD_Debug
        printf("isolation value= %2f\n",g);
#endif

        ////status bit error///////////////
        hex=(isolation[1]);


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
    ////////////////////////battery/////////////////////////////////////
    else if(frame.data[0]==0xe4){
        printf("Battery= ");
        for(int i=0;i<frame.can_dlc;i++){
            battery[i]=frame.data[i];
#ifdef IMD_Debug
            printf(" 0x%x  ",battery[i]);
#endif
        }

        vb=(battery[2]<<8)|(battery[3]);
#ifdef IMD_Debug
        printf(" battery voltage= %d volt \n",vb);
#endif
    }


    //////////////////////////Error check///////////////////////////////////////////////////////////////////



    else if(frame.data[0]==0xe5){        
        printf("Error check= ");

        for(int i=0;i<frame.can_dlc;i++){
            Error[i]=frame.data[i];
            printf(" 0x%x ",frame.data[i]);
        }

        hex_error=(Error[2]);
        result_error=((hex_error>>7)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Vx2 connection is broken......\n");
        }

        result_error=((hex_error>>6)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Vx1 connection is broken.....\n");
        }


        result_error=((hex_error>>5)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("chasis is broken.......\n");
        }


        result_error=((hex_error>>4)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("power rail reverse connection..........\n");
        }


        result_error=((hex_error>>3)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Excitation voltage is out-off range........\n");
        }


        result_error=((hex_error>>2)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("SIM100 power supply is out-off range.......\n");
        }

    }
    /////////////////////////////////////////////////Resistance///////////////////////////////////////
    else if(frame.data[0]==0xe1){
        printf("Resistance= ");
        for(int i=0;i<frame.can_dlc;i++){
            Resistance[i]=frame.data[i];
            printf(" 0x%x ",Resistance[i]);}

        rp=(Resistance[2]<<8)|(Resistance[3]);
        rp_float=rp*0.001;
        printf("RP= %2f\n",rp_float);

        rm=(Resistance[5]<<8)|(Resistance[6]);
        rm_float =rm*0.001;
        printf("RM= %2f",rm_float);
    }
#ifdef MD_Debug
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    fflush(stdout);

    return 0;
}
///Resistance//...............
int Imd::Resistance_func(){
    int i;
    unsigned int hex=0,result2=0;
    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;

    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE1;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }
    /*
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
*/


    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Read");
        return 1;
    }
#ifdef MD_Debug
    cout<<"\n";
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
#endif
    /////////////////////////////////////////////////Resistance///////////////////////////////////////
    if(frame.data[0]==0xe1){
        printf("Resistance= ");
        for(int i=0;i<frame.can_dlc;i++){
            Resistance[i]=frame.data[i];
            printf(" 0x%x ",Resistance[i]);}

        rp=(Resistance[2]<<8)|(Resistance[3]);
        rp_float=rp*0.001;
        printf("RP= %2f\n",rp_float);

        rm=(Resistance[5]<<8)|(Resistance[6]);
        rm_float =rm*0.001;
        printf("RM= %2f",rm_float);
    }
    ///////	/////////////////////////////////////////////////////////////////voltage////////////////////////
    else if(frame.data[0]==0xe3){
        printf("Voltage= ");
        for(int i=0;i<frame.can_dlc;i++){
            Voltage[i]=frame.data[i];
            printf(" 0x%x  ",Voltage[i]);
        }

        vp=0;
        vn=0;
        vp=(Voltage[2]<<8)|(Voltage[3]);
        vn=(Voltage[5]<<8)|(Voltage[6]);


        int total=vp+vn;
        printf(" vp=%d  vn=%d total=%d \n",vp,vn,total);
        total=0;
    }
    /////////////////////////////isolation////////////////////////////

    else if(frame.data[0]==0xe0){
        printf("Isolation= ");
        for(int i=0;i<frame.can_dlc;i++){
            isolation[i]=frame.data[i];
            printf(" 0x%x  ",isolation[i]);
        }

        iso_value=(isolation[2]<<8)|(isolation[3]);
        double g=iso_value*0.001;
        printf("isolation value= %2f\n",g);


        ////status bit error///////////////
        hex=(isolation[1]);


        result=((hex>>7)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Hardware Error occur\n");
        }

        result=((hex>>6)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("No Estimate Error occur\n");
        }


        result=((hex>>5)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High Uncertanity occur\n");
        }


        result=((hex>>4)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("reserve bit\n");
        }


        result=((hex>>3)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High voltage occur\n");
        }

        result=((hex>>2)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Low volatge error occur\n");
        }


        result=((hex>>1)&01);
        printf("result8=%d\n",result);

        result2=(hex&01);
        printf("result9=%d\n",result);

        if(result & result2)
            printf("isolation fault\n");
        else if(result | result2)
            printf("isolation status warning\n");;

    }
    ////////////////////////battery/////////////////////////////////////
    else if(frame.data[0]==0xe4){
        printf("Battery voltage= ");
        for(int i=0;i<frame.can_dlc;i++){
            battery[i]=frame.data[i];
            printf(" 0x%x  ",battery[i]);
        }


        vb=(battery[2]<<8)|(battery[3]);
        printf(" battery voltage= %d volt \n",vb);

    }
    //////////////////////////Error check///////////////////////////////////////////////////////////////////


    else if(frame.data[0]==0xe5){
        printf("Error check= ");
        for(int i=0;i<frame.can_dlc;i++){
            Error[i]=frame.data[i];
            printf(" 0x%x ",frame.data[i]);}

        hex_error=(Error[2]);


        result_error=((hex_error>>7)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Vx2 connection is broken......\n");
        }

        result_error=((hex_error>>6)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Vx1 connection is broken.....\n");
        }


        result_error=((hex_error>>5)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("chasis is broken.......\n");
        }


        result_error=((hex_error>>4)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("power rail reverse connection..........\n");
        }


        result_error=((hex_error>>3)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Excitation voltage is out-off range........\n");
        }


        result_error=((hex_error>>2)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("SIM100 power supply is out-off range.......\n");
        }

    }
#ifdef MD_Debug
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}
///Error Flag//...............
int Imd::Error_func(){
    int i;
    unsigned int hex=0,result2=0;

    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;


    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE5;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes  < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }
    /*
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
*/


    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Read");
        return 1;
    }
    //////////////////////////Error check///////////////////////////////////////////////////////////////////
#ifdef MD_Debug
    cout<<"\n";
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
#endif

    if(frame.data[0]==0xe5){
        printf("Error check= ");
        for(int i=0;i<frame.can_dlc;i++){
            Error[i]=frame.data[i];
            printf(" 0x%x ",frame.data[i]);}

        hex_error=(Error[2]);

        result_error=((hex_error>>7)&01);
        if(result_error == 1){
            printf("result=%d\n",result_error);
            printf("Vx2 connection is broken......\n");
        }

        result_error=((hex_error>>6)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Vx1 connection is broken.....\n");
        }


        result_error=((hex_error>>5)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("chasis is broken.......\n");
        }


        result_error=((hex_error>>4)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("power rail reverse connection..........\n");
        }


        result_error=((hex_error>>3)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("Excitation voltage is out-off range........\n");
        }


        result_error=((hex_error>>2)&01);
        if(result_error==1){
            printf("result=%d\n",result_error);
            printf("SIM100 power supply is out-off range.......\n");
        }

    }
    /////////////////////////////////////////////////Resistance///////////////////////////////////////
    if(frame.data[0]==0xe1){
        printf("Resistance= ");
        for(int i=0;i<frame.can_dlc;i++){
            Resistance[i]=frame.data[i];
            printf(" 0x%x ",Resistance[i]);}

        rp=(Resistance[2]<<8)|(Resistance[3]);
        rp_float=rp*0.001;
        printf("RP= %2f\n",rp_float);

        rm=(Resistance[5]<<8)|(Resistance[6]);
        rm_float =rm*0.001;
        printf("RM= %2f",rm_float);
    }
    ///////	/////////////////////////////////////////////////////////////////voltage////////////////////////
    if(frame.data[0]==0xe3){
        printf("Voltage= ");

        for(int i=0;i<frame.can_dlc;i++){
            Voltage[i]=frame.data[i];
            printf(" 0x%x  ",Voltage[i]);
        }

        vp=0;
        vn=0;
        vp=(Voltage[2]<<8)|(Voltage[3]);
        vn=(Voltage[5]<<8)|(Voltage[6]);


        int total=vp+vn;
        printf(" vp=%d  vn=%d total=%d \n",vp,vn,total);
        total=0;
    }
    /////////////////////////////isolation////////////////////////////

    else if(frame.data[0]==0xe0){
        printf("Isolation= ");
        for(int i=0;i<frame.can_dlc;i++){
            isolation[i]=frame.data[i];
            printf(" 0x%x  ",isolation[i]);
        }
    }
    iso_value=(isolation[2]<<8)|(isolation[3]);
    double g=iso_value*0.001;
    printf("isolation value= %2f\n",g);


    ////status bit error///////////////
    hex=(isolation[1]);


    result=((hex>>7)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("Hardware Error occur\n");
    }

    result=((hex>>6)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("No Estimate Error occur\n");
    }


    result=((hex>>5)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("High Uncertanity occur\n");
    }


    result=((hex>>4)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("reserve bit\n");
    }


    result=((hex>>3)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("High voltage occur\n");
    }


    result=((hex>>2)&01);
    if(result==1){
        printf("result=%d\n",result);
        printf("Low volatge error occur\n");
    }


    result=((hex>>1)&01);
    printf("result8=%d\n",result);

    result2=(hex&01);
    printf("result9=%d\n",result);

    if(result & result2)
        printf("isolation fault\n");
    else if(result | result2)
        printf("isolation status warning\n");;


    ////////////////////////battery/////////////////////////////////////
    if(frame.data[0]==0xe4){
        printf("Battery= ");
        for(int i=0;i<frame.can_dlc;i++){
            battery[i]=frame.data[i];
            printf(" 0x%x  ",battery[i]);
        }
    }

    vb=(battery[2]<<8)|(battery[3]);
    printf(" battery voltage= %d volt \n",vb);


    ////////////////////////////////////////////////////////////////


#ifdef MD_Debug
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}



///Capacitance//...............
int Imd::Capacitance(){
    int i;

    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;


    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE2;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes  < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes  < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }
    //printf("wrote =%x",nbytes);
    usleep(10000);

    //cout<<"0x%03X [%d]"<<frame.can_id<<frame.can_dlc;
    /*	//cout<<"0x%x"<<frame.data[i];
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
*/



    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes  < 0) {
        perror("Read");
        return 1;
    }
#ifdef MD_Debug
    cout<<"\n";
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    printf("Capacitance= ");
    for(int i=0;i<frame.can_dlc;i++)
        printf(" 0x%x ",frame.data[i]);
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }    
    return 0;
}
///isolation//...............
int Imd::isolation_func(){
    int i;
    unsigned int hex=0,result2=0;
    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;

    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE0;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes  < 0) {
        perror("can raw socket write\r\n");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes  < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }
    /*
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
*/



    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Read");
        return 1;
    }



    /////////////////////////////isolation////////////////////////////

    if(frame.data[0]==0xe0){
 #ifdef IMD_debug
        printf("Isolation= ");
#endif
        for(int i=0;i<frame.can_dlc;i++){
            isolation[i]=frame.data[i];
#ifdef MD_Debug
            printf(" 0x%x  ",isolation[i]);
#endif
        }

        iso_value=(isolation[2]<<8)|(isolation[3]);
        double g=iso_value*0.001;
#ifdef MD_Debug
        printf("isolation value= %2f\n",g);
#endif

        ////status bit error///////////////
        hex=(isolation[1]);

        result=((hex>>7)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Hardware Error occur\n");
        }

        result=((hex>>6)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("No Estimate Error occur\n");
        }

        result=((hex>>5)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High Uncertanity occur\n");
        }

        result=((hex>>4)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("reserve bit\n");
        }

        result=((hex>>3)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High voltage occur\n");
        }


        result=((hex>>2)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Low volatge error occur\n");
        }

        result=((hex>>1)&01);
        printf("result8=%d\n",result);

        result2=(hex&01);
        printf("result9=%d\n",result);

        if(result & result2)
            printf("isolation fault\n");
        else if(result | result2)
            printf("isolation status warning\n");

    }

    ////////////////////////battery/////////////////////////////////////
    else if(frame.data[0]==0xe4){
        printf("Battery voltage= ");
        for(int i=0;i<frame.can_dlc;i++){
            battery[i]=frame.data[i];
            printf(" 0x%x  ",battery[i]);
        }


        vb=(battery[2]<<8)|(battery[3]);
        printf(" battery voltage= %d volt \n",vb);

    }
    /////////////////////////////////////////////////Resistance///////////////////////////////////////
    else if(frame.data[0]==0xe1){
        printf("Resistance= ");
        for(int i=0;i<frame.can_dlc;i++){
            Resistance[i]=frame.data[i];
            printf(" 0x%x ",Resistance[i]);}

        rp=(Resistance[2]<<8)|(Resistance[3]);
        rp_float=rp*0.001;
        printf("RP= %2f\n",rp_float);

        rm=(Resistance[5]<<8)|(Resistance[6]);
        rm_float =rm*0.001;
        printf("RM= %2f",rm_float);
    }
    ///////	/////////////////////////////////////////////////////////////////voltage////////////////////////
    else if(frame.data[0]==0xe3){
        printf("Voltage= ");

        for(int i=0;i<frame.can_dlc;i++){
            Voltage[i]=frame.data[i];
            printf(" 0x%x  ",Voltage[i]);
        }

        vp=0;
        vn=0;
        vp=(Voltage[2]<<8)|(Voltage[3]);
        vn=(Voltage[5]<<8)|(Voltage[6]);


        int total=vp+vn;
        printf(" vp=%d  vn=%d total=%d \n",vp,vn,total);
        total=0;
    }

    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}
///Battery//...............
int Imd::Battery_func(){
    int i;
    unsigned int hex=0,result2=0;

    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 1;


    for(int i=0;i<frame.can_dlc;i++)
        frame.data[0]=0xE4;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes  < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes  < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }

    /*
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    //printf("value= ");
    for(int i=0;i<frame.can_dlc;i++)
    printf("0x%x ",frame.data[i]);
*/

    frame.can_id = 0xA100100 | CAN_EFF_FLAG;
    nbytes = read(s2, &frame, sizeof(struct can_frame));

    if (nbytes  < 0) {
        perror("Read");
        return 1;
    }


    if(frame.data[0]==0xe3){

        for(int i=0;i<frame.can_dlc;i++){
            Voltage[i]=frame.data[i];
#ifdef MD_Debug
            printf(" 0x%x  ",Voltage[i]);
#endif
        }

        vp=0;
        vn=0;
        vp=(Voltage[2]<<8)|(Voltage[3]);
        vn=(Voltage[5]<<8)|(Voltage[6]);


        int total=vp+vn;
        printf(" vp=%d  vn=%d total=%d \n",vp,vn,total);
        total=0;
    }
    /////////////////////////////isolation////////////////////////////

    else if(frame.data[0]==0xe0){
        for(int i=0;i<frame.can_dlc;i++){
            isolation[i]=frame.data[i];
#ifdef MD_Debug
            printf(" 0x%x  ",isolation[i]);
#endif

        }

        iso_value=(isolation[2]<<8)|(isolation[3]);
        double g=iso_value*0.001;
        printf("isolation value= %2f\n",g);


        ////status bit error///////////////
        hex=(isolation[1]);


        result=((hex>>7)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Hardware Error occur\n");
        }

        result=((hex>>6)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("No Estimate Error occur\n");
        }


        result=((hex>>5)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High Uncertanity occur\n");
        }


        result=((hex>>4)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("reserve bit\n");
        }


        result=((hex>>3)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("High voltage occur\n");
        }


        result=((hex>>2)&01);
        if(result==1){
            printf("result=%d\n",result);
            printf("Low volatge error occur\n");
        }


        result=((hex>>1)&01);
        printf("result8=%d\n",result);

        result2=(hex&01);
        printf("result9=%d\n",result);

        if(result & result2)
            printf("isolation fault\n");
        else if(result | result2)
            printf("isolation status warning\n");;

    }
    ////////////////////////battery/////////////////////////////////////
    if(frame.data[0]==0xe4){
        for(int i=0;i<frame.can_dlc;i++){
            battery[i]=frame.data[i];
#ifdef MD_Debug
            printf(" 0x%x  ",battery[i]);
#endif
        }


        vb=(battery[2]<<8)|(battery[3]);
        printf(" battery voltage= %d volt \n",vb);
    }

    ////////////////////////////////////////////////////////////////

    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}




int Imd::vbmax(){
    int i;

    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 3;

    for(int i=0;i<frame.can_dlc;i++){
        frame.data[0]=0xF0;
        frame.data[1]=0x02;
        frame.data[2]=0x58;
    } // 2nd and 3rd bit take from BMS ....modification rtequired....

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes  < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    ;
#ifdef MD_Debug
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    printf("sending vbmax voltage from BMS= "); 
    for(int i=0;i<frame.can_dlc;i++)
    {
        printf("0x%x ",frame.data[i]);
    }
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}

int Imd::Restart(){
    int i;

    frame.can_id = 0xA100101 | CAN_EFF_FLAG;
    frame.can_dlc = 5;


  //  for(int i=0;i<frame.can_dlc;i++){}
        frame.data[0]=0xC1;
        frame.data[1]=0x01;
        frame.data[2]=0x23;
        frame.data[3]=0x45;
        frame.data[4]=0x67;

    nbytes = write(s2, &frame, sizeof(struct can_frame));
    if (nbytes < 0) {
        perror("can raw socket write");
        return 1;
    }
    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return 1;
    }

#ifdef MD_Debug
    printf("0x%03X [%d]",frame.can_id,frame.can_dlc);
    printf("Restart command send........ \n");
    for(int i=0;i<frame.can_dlc;i++)
        printf("0x%x ",frame.data[i]);
    cout<<"\n";
#endif
    for(int i=0;i<8;i++)
    {
        frame.data[i]=0;
    }
    return 0;
}
int Imd::imd_test(){		// imd initialization

    cout<<"CAN Socket Receive Demo\r\n";

    if ((s2 = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket");
        return 1;
    }

    strcpy(ifr.ifr_name, "can0" );
    ioctl(s2, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s2, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return 1;
    }

    if( ret1 < 0){
        printf("Set can device %s failed!\r\n",dev_name_imd);
        exit(EXIT_FAILURE);
    }

    ret1 = can_setting_imd(dev_name_imd, can_baudrate_imd, 1);

    struct can_filter rfilter1[1];
    rfilter1[0].can_id  =0xA100100;
    rfilter1[0].can_mask= CAN_EFF_MASK;

    //rfilter[1].can_id  =  0x060F8442;
    //rfilter[1].can_mask= CAN_EFF_MASK;

    //rfilter[2].can_id  =  0x060F8411;
    //rfilter[2].can_mask= CAN_EFF_MASK;

    //rfilter[3].can_id  =  0x060F8005;
    //rfilter[3].can_mask= CAN_EFF_MASK;

    setsockopt(s2, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter1[0], sizeof(rfilter1));
    return 0;

}
int Imd::ImdCalling()
{

    //while(1){
    qDebug()<<"Imd starts";
    if(g==1){
        //dc1();
        delay(100);
        g=2;
    }


   else if(g==2){
        isolation_func();

        delay(100);
        g=4;
    }
    else if(g==4){
        VoltageVP();
        //delay(100);
        g=5;}

    else if(g==5){
        Battery_func();
        //delay(100);
        g=6;
    }

    else if(g==6){
        Resistance_func();
        //delay(100);
        g=7;
    }


    else if(g==7){
        Error_func();
        //delay(100);
        g=8;}

    else if(g==8)
    {
        vbmax();
        g=9;}

    if(g==9)
    {
        Restart();
        sleep(1);
        g=1;
    }

    // }
    return 0;
}


