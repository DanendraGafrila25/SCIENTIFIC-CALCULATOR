#ifndef penjumlahan_h
#define penjumlahan_h 
#include <stdio.h>
int penjumlahan()
{
    int a, b, hasil;
    
    printf("Masukan angka yang ingin dijumlahkan : ");
    scanf("%d", &a);
    printf("Masukan angka yang ingin dijumlahkan : ");
    scanf("%d", &b);
    
   hasil = a + b;
    
    printf("Hasil Penjumlahan : %d", hasil);
    
    return 0;
}

#endif