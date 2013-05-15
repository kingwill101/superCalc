#include "include/calculate.h"
#include <string>
#include <iostream>



 
 //TODO update display after ex variable is used so current figure is displayed


App::App( QString title)
{
  icon = new QSystemTrayIcon(QIcon(QPixmap("data/icon.png")), this);
  
  
  mode = nullMODE;
  t1 = 0;
  t2 = 0;
  
  this->setWindowTitle(title);
  this->setWindowIcon(QIcon(QPixmap("data/icon.png")));
  
  widg = new QWidget();
  layout = new QGridLayout();
  this->setMaximumHeight(300);
  this->setMaximumWidth(300);
 
  
  line = new QLineEdit();
  line->setReadOnly(TRUE);
  line->setMaximumHeight(70);
  this->line->setMaxLength(15);
  line->setAlignment(Qt::AlignRight);
//   line->setValidator(QDoubleValidator());
  this->line->setText("0.0");
  line->setFont(QFont("Helvetica", 20, QFont::Normal));
  
  Smap = new QSignalMapper(this);
  Opmap = new QSignalMapper(this);
  
  //CREATE DIGIT BUTTONS 
  for (int i=10; i >= 0; i--){
      QString text = QString::number(i);
      but[i] = new QPushButton(text);
      //but[i]->setStyleSheet("height:25");
      but[i]->setShortcut(text);
      }
  
  clear = new QPushButton("C");
  clear->setShortcut(Qt::Key_Delete);
//   clear->setStyleSheet("height:25");
  add = new QPushButton("+");
//   add->setStyleSheet("height:25");
  add->setShortcut(Qt::Key_Plus);
  subtract = new QPushButton("-");
//   subtract->setStyleSheet("height:25");
  subtract->setShortcut(Qt::Key_Minus);
  multiply = new QPushButton("x");
//   multiply->setStyleSheet("height:25");
  multiply->setShortcut(Qt::Key_Asterisk);
  divide = new QPushButton("/");
//   divide->setStyleSheet("height:25");
  divide->setShortcut(Qt::Key_Slash);
  equals = new QPushButton("=");
  //equals->setStyleSheet("height:25");
  equals->setShortcut(Qt::Key_Enter);
   
  
  fullLayout = new QVBoxLayout();
  fullLayout->addWidget(line);
  fullLayout->addLayout(layout);
  fullLayout->setSpacing(1);
  

  //Digit Buttons
  layout -> addWidget(but[9], 0, 0);
  layout -> addWidget(but[8], 0, 1);
  layout -> addWidget(but[7], 0, 2);
  layout -> addWidget(but[6], 1, 0);
  layout -> addWidget(but[5], 1, 1);
  layout -> addWidget(but[4], 1, 2);
  layout -> addWidget(but[3], 2, 0);
  layout -> addWidget(but[2], 2, 1);
  layout -> addWidget(but[1], 2, 2);
  layout -> addWidget(but[0], 3, 1);
  layout -> addWidget(add, 3, 2);
  //Operator Buttons
  layout -> addWidget(clear, 0, 4);
  layout -> addWidget(subtract, 1, 4);
  layout -> addWidget(divide, 2, 4);
  layout -> addWidget(multiply, 3, 4);
  layout -> addWidget(equals, 3, 0);
  layout->setSpacing(2);
  
    
  
  
 
  //connect all digits to a clicked() signal
  for (int i = 0; i < 10; i++){
    
    QObject::connect(but[i], SIGNAL(clicked()), Smap, SLOT(map()) );
    Smap->setMapping(but[i], but[i]->text());
      }
      
   QObject::connect(add, SIGNAL(clicked()),Opmap ,SLOT(map()) );
   QObject::connect(subtract, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(divide, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(multiply, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(equals, SIGNAL(clicked()), Opmap, SLOT(map()) );
   
   Opmap->setMapping(add, add->text() );
   Opmap->setMapping(subtract, subtract->text() );
   Opmap->setMapping(divide, divide->text() );
   Opmap->setMapping(multiply, multiply->text() );
   Opmap->setMapping(divide, divide->text() );
   Opmap->setMapping(equals, equals->text());
   
   
  QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clearScreen()) );
  QObject::connect(Smap, SIGNAL(mapped(QString)), this, SLOT(lineUp(QString)) );
  QObject::connect(Opmap, SIGNAL(mapped(QString)), this, SLOT(operatorCheck(QString)) );
  widg->setLayout(fullLayout);
  
  this->setCentralWidget(widg);
  
}//App()

 App::~App(){

}//~App()


void App::operatorCheck(QString op){
  //operator checking 
  tmp = this->line->text();
  
 
  if (op == "+" && mode != addMode)
    { 
      //update the current mode and converts and sets the value to t1
      //followed by clearing the display
      mode = addMode;
      t1 = tmp.toInt();
      this->line->clear();
      } else if (op == "+" && mode == addMode)
	    {
	
	      /*
	      * way of allowing user to press same operator several times without having to worry about messing up 
	      *the current equation
	      */
	
		{
	
		  /*
		  * knowing that once the operator is clicked the screen gets cleared 
		  * we use an additional variable to store any additional values and add them to t1 if 
		  * the user chooses to continue using the current operator without using the  "=" operator.
		  */
		  
		  ex = this->line->text();
		  t1 += ex.toInt();
		  this->line->clear();
		}
	      }
    
    
  else if (op == "-") {
     if (op == "-" && mode != MinusMode){ 
       if (this->line->text() == ""){
	 tmp = this->line->text();
	 t1 = tmp.toInt();
      }
     mode = MinusMode;
     tmp = this->line->text();
     t1 = tmp.toInt();
     this->line->clear();
  }//end if
     else if (op == "-" && mode == MinusMode){
        { 
	    ex = this->line->text();
	    t1 -= ex.toInt();
	    this->line->clear();
	  } //end else if
	    }//end else if
      }//end else if
	
  
   else if (op == "/"){
     if (op == "/" && mode != divideMode){ 
	mode = divideMode;
	tmp = this->line->text();
	t1 = tmp.toInt();
	this->line->clear();   
      }
     else if (op == "/" && mode == divideMode){
      {
	ex = this->line->text();
	t1 += ex.toInt();
	this->line->clear();

      }//end else if
     } //end else if
  }//end else if
	   
   else if (op == "x"){
     if (op == "x" && mode != multiplyMode){ 
     mode = multiplyMode;
     tmp = this->line->text();
     t1 = tmp.toInt();
     this->line->clear();   
    
    } else if (op == "*" && mode == multiplyMode){
	{
	  ex = this->line->text();
	  t1 += ex.toInt();
	  this->line->clear();
	}//else if
    }//end else if
    }//end else if
   
   
   else if (op == "="){
     
     /*
      * simple way of checking which operator was used before the "=" operator was clicked
      * by checking the current mode defined in _operatorM and assigned to the variable mode
      
      */
     if (mode == addMode){
       
       tmp = this->line->text();
       t2 = tmp.toInt();
       QString ans = QString::number(t1+t2);
       mode =nullMODE;//sets back to the default mode
       this->line->setText(ans);
       
    }else if (mode == MinusMode){
       tmp = this->line->text();
       t2 = tmp.toInt();
       QString ans = QString::number(t1-t2);
       mode =nullMODE;
       this->line->setText(ans);
       
    }else if (mode == divideMode){
       tmp = this->line->text();
       t2 = tmp.toInt();
       QString ans = QString::number(t1/t2);
       mode =nullMODE;
       this->line->setText(ans);
       
    }if (mode == multiplyMode){
       tmp = this->line->text();
       t2 = tmp.toInt();
       
       QString ans = QString::number(t1*t2);
       mode =nullMODE;
       this->line->setText(ans);
    }
    
	}
	
}//operatorCheck


void App::lineUp(QString b){
  
    if (this->line->text() == "0.0"){
      this->line->clear();
      }
    this->line->setText(this->line->text() + b);
    
}//lineUp()

void App::clearScreen()
{
  this->line->clear();
  //set the screen to its default state
  this->line->setText("0.0");
  mode = nullMODE;
}//clearScreen()
