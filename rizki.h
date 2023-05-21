#ifndef rizki_h
#define rizki_h
#include <windows.h>

//trigonometri
double simbol_operasi_trigonometri(double sudut, char op[]) {
	if (strcmp(op, "cos(") == 0 && sudut == 90){
		return 0;
	}
	
    if(strcmp(op, "sin(") == 0){
    	sudut = (sudut * M_PI)/180;
    	return sin(sudut);
    }else if(strcmp(op, "cos(") == 0) {
    	sudut = (sudut * M_PI)/180;
		return cos(sudut);  
    }else if(strcmp(op, "tan(") == 0) {
    	sudut = (sudut * M_PI)/180;
        return tan(sudut);
    }else if(strcmp(op, "csc(") == 0) {
    	sudut = (sudut * M_PI)/180;
		return 1.0 / sin(sudut);
    }else if(strcmp(op, "sec(") == 0) {
    	sudut = (sudut * M_PI)/180;
		return 1.0 / cos(sudut);
    }else if(strcmp(op, "cot(") == 0) {
    	sudut = (sudut * M_PI)/180;
		return 1.0 / tan(sudut);
    }else if(strcmp(op, "arcsin(") == 0){
    	sudut = asin(sudut);
		return sudut * (180 / M_PI);
	}else if(strcmp(op, "arccos(") == 0){
    	sudut = acos(sudut);
		return sudut * (180 / M_PI);
	}else if(strcmp(op, "arctan(") == 0){
    	sudut = atan(sudut);
		return sudut * (180 / M_PI);
	}else if(strcmp(op, "arccsc(") == 0){
    	sudut = asin(1 / sudut);
		return sudut * (180 / M_PI);
	}else if(strcmp(op, "arcsec(") == 0){
    	sudut = acos(1 / sudut);
		return sudut * (180 / M_PI);
	}else if(strcmp(op, "arccot(") == 0){
    	sudut = atan(1 / sudut);
		return sudut * (180 / M_PI);
	}else{
        return 0;
	}
}

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int permutation(int n, int r) {
    return faktorial(n) / faktorial(n-r);	
}

int combination(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n-r));
}

int menuKombinatorial(int n, int r, char input){
	if(input == 'C'){
		return combination(n, r);
	}else{
		return permutation(n, r);
	}
}

int faktorial(int angka){
	int result = 1;
	if(angka >= 0){
		int i;
		for (i = 2; i <= angka; i++) {
	        result *= i;
	    }
		return result;	
	}else{
		printf("Anda memasukkan angka negatif!");
		return 0;
	}
}

#endif
