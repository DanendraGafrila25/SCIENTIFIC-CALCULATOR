#ifndef Aqila_h
#define Aqila_h
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tree.h"

double logaritmaProses(double num1, double num2, char *input);
double logNatural(double num);

double DequeOperand(Queue* A) {
	double q; // variabel untuk menyimpan nilai operand yang di-dequeue
	node First, Last, Throw; // variabel untuk menyimpan penunjuk pada simpul pertama, terakhir, dan simpul yang akan dihapus
	
	First = A->First; // mengambil penunjuk pada simpul pertama
	Last = A->Last; // mengambil penunjuk pada simpul terakhir
	
	if (First == NULL){
		printf("Queue Empty"); // jika antrian kosong, cetak pesan "Queue Empty"
	}else{
		if (First != Last){
			while(First -> next != Last){
				First = First->next; // mencari simpul sebelum simpul terakhir
			}
			Throw = Last; // menyimpan penunjuk pada simpul terakhir
			q = Last->operand; // menyimpan nilai operand pada simpul terakhir
			A->Last = First; // mengatur penunjuk simpul terakhir menjadi simpul sebelum simpul terakhir
			A->Last->next = NULL; // mengatur penunjuk next simpul terakhir menjadi NULL
			free(Throw); // menghapus simpul terakhir
			return q; // mengembalikan nilai operand yang di-dequeue
		}else{
			Throw = Last; // menyimpan penunjuk pada simpul terakhir
			q = Last->operand; // menyimpan nilai operand pada simpul terakhir
			A->Last = NULL; // mengatur penunjuk simpul terakhir menjadi NULL
			A->First = NULL; // mengatur penunjuk simpul pertama menjadi NULL
			free(Throw); // menghapus simpul terakhir
			return q; // mengembalikan nilai operand yang di-dequeue
		}
	}
}

void EnqueOperator(Queue* First, char item, node* P){
	*P = (address) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
	if(P == NULL){
		printf("Gagal Alokasi"); // Jika alokasi gagal, cetak pesan "Gagal Alokasi"
	}else{
		(*P)->oprtr = item; // Menyimpan karakter operator pada node baru
		(*P)->next = NULL; // Mengatur pointer next pada node baru menjadi NULL
		(*P)->isoperator = 1; // Menandai bahwa node baru adalah operator
		if(First -> First == NULL){
			(*First).First = *P; // Jika antrian kosong, node baru menjadi elemen pertama
			(*First).Last = *P; // Jika antrian kosong, node baru menjadi elemen terakhir
			(*First).Last->next = NULL; // Mengatur pointer next pada elemen terakhir menjadi NULL
		}else{
			(*P)->next = NULL; // Mengatur pointer next pada node baru menjadi NULL
			First->Last->next = *P; // Mengatur pointer next pada elemen terakhir menjadi node baru
			First->Last = *P; // Mengubah elemen terakhir menjadi node baru
		}
	}
}

void EnqueOperand(Queue* First, float item, node* P){
	*P = (address) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
	if (P == NULL){
		printf("Gagal Alokasi"); // Jika alokasi gagal, cetak pesan "Gagal Alokasi"
	}else{
		(*P)->operand = item; // Menyimpan nilai operand pada node baru
		(*P)->next = NULL; // Mengatur pointer next pada node baru menjadi NULL
		(*P)->isoperator = 0; // Menandai bahwa node baru bukan operator
		if(First->First == NULL){
			(*First).First = *P; // Jika antrian kosong, node baru menjadi elemen pertama
			(*First).Last = *P; // Jika antrian kosong, node baru menjadi elemen terakhir
			(*First).Last->next = NULL; // Mengatur pointer next pada elemen terakhir menjadi NULL
		}else{
			(*P)->next = NULL; // Mengatur pointer next pada node baru menjadi NULL
			First->Last->next = *P; // Mengatur pointer next pada elemen terakhir menjadi node baru
			First->Last = *P; // Mengubah elemen terakhir menjadi node baru
		}
	}
}

//logaritma
double logaritmaProses(double num1, double num2, char *input) {
	double hasil = 0.0;
	
	if (strcmp(input, "log(") == 0) {
		if (num2 <= 0 || num1 <= 0) {
			printf("Invalid input\n");
			return 0.0 / 0.0;
		} else {
			hasil = logNatural(num2)/logNatural(num1); //Rumus untuk mengonversi logartima (log(e) = ln(base) / ln(e))
			return hasil;
		}
	} else if (strcmp(input, "ln(") == 0) {
		if (num2 <= 0) {
			printf("Invalid input\n");
			return 0.0 / 0.0;
		} else {
			hasil = logNatural(num2); // Menggunakan logaritma natural dengan basis e
			return hasil;
		}
	}
}

double logNatural(double num) {
	if (num <= 0) {
		printf("Error: Argumen harus lebih besar dari 0.\n"); // Menampilkan pesan kesalahan jika argumen kurang dari atau sama dengan 0
		return -1; // Mengembalikan nilai -1 sebagai tanda kesalahan
	}
	
	double epsilon = 1e-13; // Akurasi yang diinginkan
	double hasil = 0.0; // Variabel untuk menyimpan hasil logaritma natural
	double term = (num - 1) / (num + 1); // Menghitung suku pertama dalam deret logaritma natural
	double current_term = term; // Variabel untuk menyimpan suku saat ini dalam deret
	int n = 1; // Variabel untuk menghitung jumlah suku dalam deret
	
	while (current_term >= epsilon) { // Melakukan perulangan hingga suku saat ini tidak lagi memenuhi akurasi yang diinginkan
		hasil += current_term; // Menambahkan suku saat ini ke dalam hasil logaritma natural
		current_term = current_term * term * term * (2 * n - 1) / (2 * n + 1); // Menghitung suku berikutnya dalam deret
		n++; // Meningkatkan jumlah suku dalam deret
	}
	
	return 2 * hasil; // Mengembalikan hasil logaritma natural (hasil dikalikan dengan 2 karena rumus logaritma natural asli hanya menghitung separuh dari hasil yang dihasilkan oleh deret Taylor ini)
}


void PrintFromFile(const char* location){
	FILE *read;
	char c;
	
	read=fopen(location, "rt");
	while((c=fgetc(read))!=EOF){
		printf("%c", c);
	}
	
	fclose(read);
}

#endif
