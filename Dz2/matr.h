#ifndef _MATR_H_
#define _MATR_H_
#include <stdio.h>
double get_elem(double** matr, int row, int col);
void set_elem(double** matr, int row, int col, double elem);
void NormMatr(double** matr,int row,int col);
double** FillMass(double** mass,FILE* ptrfile,int* row,int* col,int* num);
#endif // _MATR_H_
