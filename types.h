#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED


/*
custom types CACL_UINT representing unsigned integers
and CALC_SINT signed integers
 */
typedef unsigned int CALC_UINT;



typedef  int CALC_SINT;
typedef double CALC_DOUBLE;
typedef bool CALC_BOOL;
typedef void CALC_VOID;
typedef signed int CALC_FLOAT;
typedef char CALC_CHAR[512];

enum CALC_ERROR{DIVISION_ERROR =1};

#endif // TYPES_H_INCLUDED
