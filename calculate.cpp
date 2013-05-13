#include "calculate.h"
#include <string>
#include <iostream>

App::App()
{
  
 
  this->setWindowTitle("SuperCALC");
  widg = new QWidget();
  layout = new QGridLayout();
  
  line = new QLineEdit();
  line->setReadOnly(TRUE);
  line->setMinimumHeight(60);
  line->setAlignment(Qt::AlignRight);
  line->setText("0.0");
  line->setFont(QFont("Helvetica", 20, QFont::Normal));
  
  Smap = new QSignalMapper(this);
  Opmap = new QSignalMapper(this);
  //CREATE DIGIT BUTTONS 
  for (int i=0; i < 10; i++){
      QString text = QString::number(i);
      but[i] = new QPushButton(text);
      }
  
  clear = new QPushButton("<-");
  add = new QPushButton("+");
  subtract = new QPushButton("-");
  multiply = new QPushButton("x");
  divide = new QPushButton("/");
  equals = new QPushButton("=");
   
  
  fullLayout = new QVBoxLayout();
  fullLayout->addWidget(line);
  fullLayout->addLayout(layout);

  layout -> addWidget(but[1], 1, 0);
  layout -> addWidget(but[2], 1, 1);
  layout -> addWidget(but[3], 1, 2);
  layout -> addWidget(but[4], 2, 0);
  layout -> addWidget(but[5], 2, 1);
  layout -> addWidget(but[6], 2, 2);
  layout -> addWidget(but[7], 3, 0);
  layout -> addWidget(but[8], 3, 1);
  layout -> addWidget(but[9], 3, 2);
  layout -> addWidget(but[0], 4, 1);
  layout -> addWidget(clear, 4, 2);
  
  layout -> addWidget(add, 1, 4);
  layout -> addWidget(subtract, 2, 4);
  layout -> addWidget(divide, 3, 4);
  layout -> addWidget(multiply, 4, 4);
  layout -> addWidget(equals, 4, 0);
  
 
  for (int i = 0; i < 10; i++){
    
    QObject::connect(but[i], SIGNAL(clicked()), Smap, SLOT(map()) );
    Smap->setMapping(but[i], but[i]->text());
      }
      
   QObject::connect(add, SIGNAL(clicked()), SLOT(map()) );
   QObject::connect(subtract, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(divide, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(multiply, SIGNAL(clicked()), Opmap, SLOT(map()) );
   QObject::connect(equals, SIGNAL(clicked()), Opmap, SLOT(map()) );
   
   Opmap->setMapping(add, add->text() );
   Opmap->setMapping(subtract, subtract->text() );
   Opmap->setMapping(divide, divide->text() );
   Opmap->setMapping(multiply, multiply->text() );
   Opmap->setMapping(divide, divide->text() );
   
   
  QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clearScreen()) );
  QObject::connect(Smap, SIGNAL(mapped(QString)), this, SLOT(lineUp(QString)) );
  QObject::connect(Opmap, SIGNAL(mapped(QString)), this, SLOT(operatorCheck(QString)) );
  widg->setLayout(fullLayout);
  
  this->setCentralWidget(widg);
  
}//App()

 App::~App(){

}//~App()

void App::operatorCheck(QString op){
  
  if (op == "+"){ 
    std::cout<<"+";
	}
   else if (op == "-"){
     std::cout<<"+";

	}
	
   else if (op == "/"){
std::cout<<"+";
	}
	   
   else if (op == "x"){
std::cout<<"+";
	}
	   
   else if (op == "="){
std::cout<<"+";
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
}//clearScreen()
