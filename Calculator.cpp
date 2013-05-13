#include <exception>
#include "Calculator.h"
#include <iostream>
#include <cmath>


Calculator::Calculator()
{

      }

Calculator::~Calculator()
{
    //dtor
}

CALC_VOID Calculator::clear(){
    this->memClear();
}

CALC_FLOAT Calculator::getTotal(){
    return this->total;
}

CALC_VOID  Calculator::setTotal(CALC_FLOAT num){
    this->total = num;
}

CALC_VOID Calculator::memClear(){
    this->total = RESET;
}
CALC_FLOAT Calculator::add(CALC_FLOAT x, CALC_FLOAT y){

    tmpTotal = x+y;
    setTotal(tmpTotal);
    return tmpTotal;

}

CALC_FLOAT Calculator::subtract(CALC_FLOAT x, CALC_FLOAT y){

    tmpTotal = x-y;
    this->setTotal(this->total -= tmpTotal);
    return tmpTotal;
    }

CALC_FLOAT Calculator::multiply(CALC_FLOAT x, CALC_FLOAT y){

    tmpTotal = x*y;
    return tmpTotal;
    }

CALC_FLOAT Calculator::divide(CALC_FLOAT x, CALC_FLOAT y){


    if (y == 0){
        std::cout<<"zero division error cannot divide " <<x<<" by "<<y<<"\nerror: ";
        return 1;
        }
    tmpTotal = x/y;
    return tmpTotal;
    }

CALC_FLOAT Calculator::Sqrt (CALC_FLOAT num){
    return  sqrt(num);
}
