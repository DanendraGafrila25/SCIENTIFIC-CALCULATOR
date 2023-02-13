#ifndef linda_h
#define linda_h
#include <stdio.h>
#include <math.h>

double eksponen(double a,double b){
   return pow(a,b);
}

int logaritma() {
  double x;
  printf("Masukkan nilai x: ");
  scanf("%lf", &x);

  printf("Logaritma natural dari %lf adalah %lf\n", x, log(x));

  return 0;
}
#endif
