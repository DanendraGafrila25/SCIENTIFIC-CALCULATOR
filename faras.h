#ifndef penjumlahan_h
#define penjumlahan_h
#include <stdio.h>

int penjumlahan(int a, int b)
{
	int hasil;
    return hasil = a + b;
}

void inputAngka(){
	
    int a, b, hasil;
    
    printf("Masukan angka yang ingin dijumlahkan : ");
    scanf("%d", &a);
    printf("Masukan angka yang ingin dijumlahkan : ");
    scanf("%d", &b);
    hasil = penjumlahan (a, b);
	printf("Hasil Penjumlahan : %d", hasil);
}

int main (){
	inputAngka();
	
	return 0;
}
#endif