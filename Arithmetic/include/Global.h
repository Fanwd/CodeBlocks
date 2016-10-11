#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void swap_int(int*, int*);

int partition(int*, int, int);
void quick_sort(int *, int, int);
void part_by_target(int *, int , int , int );
int getMaxAppNumber(int, int);
int getCountOf1(int);
int Karatsuba(int, int);
int getHeight(int, double);
int getLow(int, double);
void BigRootHeapSort(int*, int);

#endif // GLOBAL_H_INCLUDED
