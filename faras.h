#ifndef faras_h
#define faras_h

double penjumlahan(double a, double b){
    return a + b;
}

double pengurangan(double a, double b){
    return a - b;
}

double perkalian(double a, double b){
	int i;
	double hasil = 0;
	
	for(i = 1; i <= b; i++){
		hasil = penjumlahan(hasil, a);
	}
	
    return hasil;
}

double pembagian(double a, double b){
    return a / b;
}

#endif
