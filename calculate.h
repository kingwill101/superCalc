#ifndef CALCULATE_H
#define CALCULATE_H

#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QIntValidator>
#include <qsignalmapper.h>


class App : public QMainWindow
{
 
  Q_OBJECT
  
public:
  App();
  ~App();

 
private slots:
  void clearScreen();
  void lineUp(QString);
  void operatorCheck(QString);
   
private:
  QIntValidator val;
  QString tmp,ex;
  QSignalMapper *Smap;
  QSignalMapper *Opmap;
  QWidget *widg;
  QLineEdit *line;
  QGridLayout *layout;
  QVBoxLayout *fullLayout;
  QPushButton *but[10];
  QPushButton *clear;
  QPushButton *add;
  QPushButton *subtract;
  QPushButton *divide;
  QPushButton *multiply;
  QPushButton *equals; 
  int mode;
  int t1;
  int t2;
  enum _operatorM{ nullMODE, addMode, MinusMode, divideMode, multiplyMode};
  
};

#endif // CALCULATE_H
