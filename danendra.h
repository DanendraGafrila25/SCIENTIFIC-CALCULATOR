#ifndef danendra_h
#define danendra_h

#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include "tree.h"

int derajatOperator(infotype oper){
	if(oper == '+' || oper == '-'){
		return 1;
	}else if (oper == '*' || oper == '/'){
		return 2;
	}else if (oper == '^' || oper == 'V'){
		return 3;
	}else if (oper == '(' || oper == ')'){
		return 0;
	}else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
		exit(1);
	}
}

int isOperator(infotype oper){
	if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 'V'){
		return 1;
	}
	return 0;
}

address Create_Tree(Queue Z){
	address P; // variabel untuk menyimpan alamat simpul
	address stack[50]; // array untuk menampung tumpukan sementara
	node Q; // variabel untuk mengiterasi melalui antrian
	int i, len, top = -1; // variabel indeks, panjang antrian, dan indeks puncak tumpukan
	infotype c; // variabel untuk menyimpan operator
	float d; // variabel untuk menyimpan operand
	
	Q = Z.First; // menginisialisasi Q dengan node pertama dalam antrian
	
	while(Q != NULL){
		if(Q->isoperator == 1){
			// Jika node dalam antrian adalah operator, membuat simpul dengan operator sebagai data
			c = Q->oprtr;
			P = CreateNodeOperator(c);
			Rson(P) = stack[top--]; // mengambil simpul anak kanan dari tumpukan
			Lson(P) = stack[top--]; // mengambil simpul anak kiri dari tumpukan
		}else{
			// Jika node dalam antrian adalah operand, membuat simpul dengan operand sebagai data
			d = Q->operand;
			P = CreateNodeOperand(d);
		}
		stack[++top] = P; // memasukkan simpul ke dalam tumpukan
		Q = Q->next; // pindah ke node berikutnya dalam antrian
	}
	
	return stack[0]; // mengembalikan alamat akar pohon yang ada di tumpukan
}

address CreateNodeOperand(float input){
	address P; // variabel untuk menyimpan alamat simpul
	P = (address) malloc(sizeof(Tree)); // mengalokasikan memori untuk simpul baru
	P->operand = input; // menyimpan operand sebagai data pada simpul
	P->isOperator = 0; // menandai simpul sebagai operand (bukan operator)
	P->Lson = NULL; // mengatur anak kiri simpul menjadi NULL
	P->Rson = NULL; // mengatur anak kanan simpul menjadi NULL
	
	return P; // mengembalikan alamat simpul yang telah dibuat
}

address CreateNodeOperator(char input){
	address P; // variabel untuk menyimpan alamat simpul
	P = (address) malloc(sizeof(Tree)); // mengalokasikan memori untuk simpul baru
	P->data = input; // menyimpan operator sebagai data pada simpul
	P->isOperator = 1; // menandai simpul sebagai operator (bukan operand)
	P->Lson = NULL; // mengatur anak kiri simpul menjadi NULL
	P->Rson = NULL; // mengatur anak kanan simpul menjadi NULL
	
	return P; // mengembalikan alamat simpul yang telah dibuat
}

#endif
