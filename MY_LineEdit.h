#ifndef MY_LINEEDIT_H
#define MY_LINEEDIT_H

#include <QWidget>
#include <qlineedit.h>
#include <QTouchEvent>

class MY_LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MY_LineEdit(QWidget *parent = nullptr);
    ~MY_LineEdit();
signals:
  void focussed(bool hasFocus);

protected:
 //  void mousePressEvent(QMouseEvent* evt);
   void focusOutEvent(QFocusEvent *e);
   void focusInEvent(QFocusEvent *) override;

};

#endif // MY_LINEEDIT_H
