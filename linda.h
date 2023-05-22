#ifndef linda_h
#define linda_h

double eksponen(double base, double exponent){
	double hasil = 1.0;
	int i;
	if(isdigit(exponent)){
		for( i = 1; i <= exponent; i++){
			hasil *= base;
		}
		return hasil;
	}else{
		return hasil = pow(base,exponent);
	}
}

double akar(double x, double y){
    double hasil = 1.0;
    double delta = 0.0001;
    int i;
    
    for(i = 0; i < 10000; i++){
        double akar_baru = (1.0 / x) * ((x - 1) * hasil + y / pow(hasil, x-1));
        if(fabs(akar_baru - hasil) < delta){
            break;
        }
        hasil = akar_baru;
    }
    return hasil;
}

void PushStack(Stack* First, char item, node* P){
	*P = (node) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
	if (P == NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr = item; // Menyimpan nilai operator pada node
		(*P)->isoperator = 1; // Menandai node sebagai operator
		(*P)->next = NULL;
		if(First->Head == NULL){
			(*First).Head = * P; // Jika stack kosong, node baru menjadi Head
			(*First).Head->next = NULL;
		}else{
			(*P)->next = First->Head; // Menyambungkan node baru dengan Head yang lama
			First->Head = *P; // Node baru menjadi Head yang baru
		}
	}
}

char PopStack(Stack* First){
	node P;
	P = First -> Head; // Mengambil node Head saat ini
	First -> Head = P -> next; // Mengatur Head baru menjadi node berikutnya
	char oprtr = P -> oprtr; // Menyimpan nilai operator dari node yang dihapus
	free(P); // Menghapus node yang diambil dari stack
	
	return oprtr; // Mengembalikan nilai operator yang dihapus
}

#endif
