#include <stdio.h>
#include <math.h>
#ifndef linda2_h
#define linda2_h

int logaritma() {
  double x;
  printf("Masukkan nilai x: ");
  scanf("%lf", &x);

  printf("Logaritma natural dari %lf adalah %lf\n", x, log(x));

  return 0;
}