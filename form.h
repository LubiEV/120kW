#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "keyboard/widgetKeyBoard.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"

class Tester;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(bool KyeBordType = true,QWidget *parent = 0);
    ~Form();

void setExternalLineEdit(QLineEdit* myExtLineEdit);

QLineEdit* externalLineEditPointer; // external pointer to the main APP

private slots:
    void returnWidgetSignalReceived();
signals:
   void changevalue(QString);

private:
    Ui::Form *ui;
    widgetKeyBoard  *_keyboard;
   // MainWindow *vi;
};

#endif // FORM_H
