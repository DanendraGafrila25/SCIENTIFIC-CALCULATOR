#ifndef penjumlahan_h
#define penjumlahan_h
#include <stdio.h>

double penjumlahan(double a, double b){
    return a + b;
}

double pengurangan(double a, double b){
    return a - b;
}

double perkalian(double a, double b){
    return a * b;
}

double pembagian(double a, double b){
    return a / b;
}

int faktorial(int angka){
	double result = 1;
	if(angka >= 0){
		int i;
		for (i = 2; i <= angka; i++) {
	        result *= i;
	    }
		return result;	
	}else{
		printf("Anda memasukkan angka negatif!");
		return -1;
	}
}

#endif
