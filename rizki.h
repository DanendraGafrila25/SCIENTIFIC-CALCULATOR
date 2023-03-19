#ifndef rizki_h
#define rizki_h

int permutation(int n, int r) {
    return faktorial(n) / faktorial(n-r);	
}

int combination(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n-r));
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
