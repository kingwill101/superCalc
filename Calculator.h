#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "types.h"

#define RESET 0

class Calculator
{
    public:
        Calculator();
        virtual ~Calculator();
        CALC_FLOAT getTotal();
        CALC_FLOAT add(CALC_FLOAT, CALC_FLOAT);
        CALC_FLOAT subtract(CALC_FLOAT, CALC_FLOAT);
        CALC_FLOAT multiply(CALC_FLOAT, CALC_FLOAT);
        CALC_FLOAT divide(CALC_FLOAT, CALC_FLOAT);
        CALC_FLOAT Sqrt (CALC_FLOAT);
        CALC_VOID clear();

    protected:
        CALC_FLOAT tmpTotal;
        CALC_FLOAT total;
    private:
        CALC_VOID setTotal(CALC_FLOAT);
        CALC_VOID memClear();
};

#endif // CALCULATOR_H
