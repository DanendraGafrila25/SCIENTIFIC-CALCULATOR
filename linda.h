#ifndef linda_h
#define linda_h
#include <stdio.h>
#include <math.h>

int eksponen(){
    double x, y;
    printf ("Masukkan nilai angka bilangan: ");
    scanf ("%lf", &x);
    printf (" Masukkan nilai pangkat: ");
    scanf ("%lf", &y);

    printf("Eksponen dari %lf pangkat %lf adalah %lf: ", x, y, pow (x, y));
    return 0;
}
#endif