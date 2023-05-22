#ifndef faras_h
#define faras_h
#include "tree.h"

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
	return  a/b;
}

// Fungsi untuk menghitung nilai ekspresi matematika yang diwakili oleh pohon ekspresi
double kalkulasi(address P){
	// Jika P adalah operator
	if (P->isOperator == 1){
		// Menghitung nilai anak kiri dan anak kanan
		double Lson = kalkulasi(P->Lson);
		double Rson = kalkulasi(P->Rson);

		// Memeriksa jenis operator dan melakukan operasi yang sesuai
		if (P->data == '+'){
			return Lson + Rson;  // Penjumlahan
		}else if(P->data == '-'){
			return Lson - Rson;  // Pengurangan
		}else if(P->data == '*'){
			return Lson * Rson;  // Perkalian
		}else if(P->data == '/'){
			return Lson / Rson;  // Pembagian
		}else if(P->data == '^'){
			return pow(Lson, Rson);  // Pemangkatan
		}else if(P->data == 'V'){
			return pow(Rson, 1 / Lson);  // Pemangkatan
		}
	}	

	// Jika P adalah operand, mengembalikan nilainya
	return P->operand;
}

#endif
