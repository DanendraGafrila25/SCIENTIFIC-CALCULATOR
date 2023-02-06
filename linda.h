#ifndef linda_h
#define linda_h
#include <stdio.h>
#include <math.h>

int eksponen(){
    int x, y;
    printf ("Masukkan nilai angka bilangan: ");
    scanf ("%d", &x);
    printf (" Masukkan nilai pangkat: ");
    scanf ("%d", &y);

    printf("Eksponen dari %d pangkat %d adalah %d: ", x, y, pow (x, y));
    return 0;
}

int logaritma() {
  double x;
  printf("Masukkan nilai x: ");
  scanf("%lf", &x);

  printf("Logaritma natural dari %lf adalah %lf\n", x, log(x));

  return 0;
}
#endif
