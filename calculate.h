/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2013  <copyright holder> <email>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef CALCULATE_H
#define CALCULATE_H

#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QVBoxLayout>
#include <qsignalmapper.h>
#include <string>
#include <sstream>


class App : public QMainWindow
{
 
  Q_OBJECT

  
public:
  
  explicit App();
  ~App();
 std::string inTtoString(int);
 
 
private slots:
  void lineUp(QString);
  void clearScreen();
  void operatorCheck(QString);
   
private:
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
  int t1;
  int t2;
};

#endif // CALCULATE_H
