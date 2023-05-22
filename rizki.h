#ifndef rizki_h
#define rizki_h

#define PI 3.14159265358979323846

void PostOrder(address P){
	if (P != Nil){
	    PostOrder(Lson(P)); // Rekursi pada anak kiri
	    PostOrder(Rson(P)); // Rekursi pada anak kanan
	    if(P -> isOperator == 1){
			printf("%c ", P -> data); // Jika node adalah operator, cetak karakter operator
	    }else{
			printf("%g ", P -> operand); // Jika node adalah operand, cetak nilai operand
	    }
	}
}

int modulus(int dividen, int divisor){
	while(dividen >= divisor){
		dividen -= divisor;
	}
	return dividen;
}

double sinus(double angle) {
	while(angle > 360){
		angle = modulus(angle, 360);
	}
	
    if(angle > 90 && angle <= 180){
    	angle = 180 - angle;
	}else if(angle > 180 && angle <= 270){
		angle = (angle - 180) * -1;
	}else if(angle > 270 && angle <= 360){
		angle = (360 - angle) * -1;
	}
	
	angle = (angle * PI) / 180;
    double result = 0;
    double term = angle;
    double numerator = angle;
    int denominator = 1;
    int sign = 1;
    int i;
    
    for (i = 0; i < 8; i++) {  // Jumlah iterasi dapat disesuaikan
        result += sign * numerator / denominator;
        numerator *= angle * angle;
        denominator *= (2 * i + 2) * (2 * i + 3);
        sign *= -1;
    }

    return result;
}

double cosinus(double angle) {
	boolean isNegatif = false;
    while(angle > 360){
		angle = modulus(angle, 360);
	}
	
    if(angle > 90 && angle <= 180){
    	angle = 180 - angle;
    	isNegatif = true;
	}else if(angle > 180 && angle <= 270){
		angle = angle - 180;
		isNegatif = true;
	}else if(angle > 270 && angle <= 360){
		angle = 360 - angle;
	}
	
	angle = (angle * PI) / 180;
    double result = 0;
    double term = 1;
    double numerator = 1;
    int denominator = 1;
    int sign = 1;
    int i;
    
    for (i = 0; i < 8; i++) {  // Jumlah iterasi dapat disesuaikan
        result += sign * numerator / denominator;
        numerator *= angle * angle;
        denominator *= (2 * i + 1) * (2 * i + 2);
        sign *= -1;
    }
    
	if(isNegatif == true){
		result *= -1;
	}
	
    return result;
}

double tangen(double angle) {
    if (angle == 90) {
        printf("Tangens sudut 90 derajat tidak terdefinisi.\n");
        return 0;
    } else {
        return sinus(angle) / cosinus(angle);
    }
}

// Operasi trigonometri untuk menghitung nilai sin, cos, tan, csc, sec, cot, arcsin, arccos, arctan, arccsc, arcsec, arccot
double simbol_operasi_trigonometri(double sudut, char op[]) {
	if (strcmp(op, "cos(") == 0 && sudut == 90) {
		return 0;
	}
	
	if(strcmp(op, "sin(") == 0) {
		return sinus(sudut);
	} else if(strcmp(op, "cos(") == 0) {
		return cosinus(sudut);  
	} else if(strcmp(op, "tan(") == 0) {
		return tangen(sudut);
	} else if(strcmp(op, "csc(") == 0) {
		return 1.0 / sinus(sudut);
	} else if(strcmp(op, "sec(") == 0) {
		return 1.0 / cosinus(sudut);
	} else if(strcmp(op, "cot(") == 0) {
		return 1.0 / tangen(sudut);
	} else if(strcmp(op, "arcsin(") == 0) {
		sudut = asin(sudut);
		return sudut * (180 / M_PI);
	} else if(strcmp(op, "arccos(") == 0) {
		sudut = acos(sudut);
		return sudut * (180 / M_PI);
	} else if(strcmp(op, "arctan(") == 0) {
		sudut = atan(sudut);
		return sudut * (180 / M_PI);
	} else if(strcmp(op, "arccsc(") == 0) {
		sudut = asin(1 / sudut);
		return sudut * (180 / M_PI);
	} else if(strcmp(op, "arcsec(") == 0) {
		sudut = acos(1 / sudut);
		return sudut * (180 / M_PI);
	} else if(strcmp(op, "arccot(") == 0) {
		sudut = atan(1 / sudut);
		return sudut * (180 / M_PI);
	} else {
		return 0;
	}
}

// Fungsi untuk mengatur posisi kursor pada layar konsol
void gotoxy(int x, int y) {
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Menghitung permutasi
int permutation(int n, int r) {
	return faktorial(n) / faktorial(n-r);	
}

// Menghitung kombinasi
int combination(int n, int r) {
	return faktorial(n) / (faktorial(r) * faktorial(n-r));
}

// masuk ke menu kombinatorial dan mengembalikan hasil
int menuKombinatorial(int n, int r, char input) {
	if(input == 'C') {
		return combination(n, r);
	} else {
		return permutation(n, r);
	}
}

// Menghitung faktorial dari suatu angka
int faktorial(int angka) {
	int result = 1;
	if(angka >= 0) {
		int i;
		for (i = 2; i <= angka; i++) {
			result *= i;
		}
		return result;	
	} else {
		printf("Anda memasukkan angka negatif!");
		return 0;
	}
}

#endif
