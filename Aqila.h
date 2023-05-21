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
	        printf("Error: Argumen harus lebih besar dari 0.\n");
	        return -1; // Mengembalikan nilai -1 sebagai tanda kesalahan
	    }
	
	    float epsilon = 1e-10; // Akurasi yang diinginkan
	    float hasil = 0.0;
	    float term = (num - 1) / (num + 1);
	    float current_term = term;
	    int n = 1;
	
	    while (current_term >= epsilon) {
	        hasil += current_term;
	        current_term = current_term * term * term * (2 * n - 1) / (2 * n + 1);
	        n++;
	    }
		return 2 * hasil;
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
