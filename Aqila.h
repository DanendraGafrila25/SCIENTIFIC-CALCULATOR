#ifndef Aqila_h
#define Aqila_h
#include <stdio.h>
#include <string.h>
#include <math.h>

float logaritmaProses(float num1, float num2, char *input);
float logNatural(float num);

	//logaritma
	float logaritmaProses(float num1, float num2, char *input) {
	    float hasil = 0.0;

	    if (strcmp(input, "log(") == 0) {
		if (num2 <= 0 || num1 <= 0) {
		    printf("Invalid input\n");
		    return 0.0 / 0.0;
		} else {
			hasil = logNatural(num2)/logNatural(num1);
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

	float logNatural(float num) {
	    if (num <= 0) {
		printf("Error: Argumen harus lebih besar dari 0.\n"); // Menampilkan pesan kesalahan jika argumen kurang dari atau sama dengan 0
		return -1; // Mengembalikan nilai -1 sebagai tanda kesalahan
	    }

	    float epsilon = 1e-10; // Akurasi yang diinginkan
	    float hasil = 0.0; // Variabel untuk menyimpan hasil logaritma natural
	    float term = (num - 1) / (num + 1); // Menghitung suku pertama dalam deret logaritma natural
	    float current_term = term; // Variabel untuk menyimpan suku saat ini dalam deret
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
