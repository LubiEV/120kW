#include "form.h"
#include "ui_form.h"
//#include "ui_mainwindow.h"

Form::Form(bool KeyBoardType,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("Virtual Keyboard");
    if(KeyBoardType == true)
    {
        _keyboard = new widgetKeyBoard(false, this, false, ui->frame);

        QRect Ascii_frame(12,200,771,261);
        QRect Ascii_line(12,170,771,31);
        ui->frame->setGeometry(Ascii_frame);
        ui->lineEdit_4->setGeometry(Ascii_line);
    }
    else
    {
         _keyboard = new widgetKeyBoard(false, this, true, ui->frame);

         QRect NumericFrame(280,200,180,251);
         QRect Numeric_line(280,170,180,31);
         ui->frame->setGeometry(NumericFrame);
         ui->lineEdit_4->setGeometry(Numeric_line);
    }
 //   _keyboard = new widgetKeyBoard(false, this, false, ui->frame);
    _keyboard->enableSwitchingEcho(true);
    _keyboard->createKeyboard();
    _keyboard->show(this);
    connect(_keyboard,SIGNAL(keySignalReceived()),this,SLOT(returnWidgetSignalReceived()));
    externalLineEditPointer = nullptr;
}
Form::~Form()
{
    delete ui;
}
void Form::returnWidgetSignalReceived()
{
   QLineEdit* currentQLineEdit = _keyboard->currentTextBox();
   QString currentText = currentQLineEdit->text();
    emit changevalue(currentText);
   hide();

  //vi = new Tester(this);
  //  externalLineEditPointer = (vi->lineEdit);
  // Ui::Tester::lineEdit::(currentQLineEdit);
/*   if(externalLineEditPointer != nullptr)
   {
        externalLineEditPointer->setText(currentText);
   }*/
  // this->vi->WidgetSignalReceived(currentText);
}

void Form::setExternalLineEdit(QLineEdit* myExtLineEdit)
{
    externalLineEditPointer = myExtLineEdit;
    QLineEdit* currentQLineEdit = _keyboard->currentTextBox();
    currentQLineEdit->setText((myExtLineEdit->text()));
}
