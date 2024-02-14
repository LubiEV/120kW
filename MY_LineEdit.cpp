#include "MY_LineEdit.h"
#include <qlineedit.h>
#include<qdebug.h>
MY_LineEdit::MY_LineEdit(QWidget *parent) : QLineEdit(parent)
{

}
MY_LineEdit::~MY_LineEdit()
{

}
 void MY_LineEdit::focusInEvent(QFocusEvent *e)
 {
   QLineEdit::focusInEvent(e);
   qDebug()<< "Focoused in" << endl;
   emit(focussed(true));
 }

 void MY_LineEdit::focusOutEvent(QFocusEvent *e)
 {
   QLineEdit::focusOutEvent(e);
   qDebug()<< "Focoused out" << endl;
   emit(focussed(false));
 }

// void MY_LineEdit::mousePressEvent(QMouseEvent *evt)
// {
//   qDebug()<< "Press LineEdit" << endl;
//   qDebug() <<"localPos" << evt->localPos() << "screen Pos" << evt->screenPos() << "windowPos" << evt->windowPos() <<endl;
//   //emit(focussed(false));
// }
