#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include "tree.h"
#include "build_tree.h"


int main(){
	float hasil;
	char input[100],temp;
	address P;
	Stack X;
	Queue Z;
	node Q;
	Z.First=NULL;
	Z.Last=NULL;
	X.Head=NULL;
	printf("Masukkan Ekspresi:");
	scanf("%s",&input);fflush(stdin);
	convertPostfix(&Z,&X,input);
	P=Create_Tree(Z);
	hasil=kalkulasi(P);
	printf("hasilnya adalah %g\n",hasil);
	printf("PostOrder: ");
	PostOrder(P);
//	Operasi_hitung();
	return 0;
}
