#include <stdio.h>
#include <math.h>

int main(){
    double x, y;
    printf ("Masukkan nilai angka bilangan: ");
    scanf ("%lf", &x);
    printf (" Masukkan nilai pangkat: ");
    scanf ("%lf", &y);

    printf("Eksponen dari %lf pangkat %lf adalah %lf: ", x, y, pow (x, y));
    return 0;
}