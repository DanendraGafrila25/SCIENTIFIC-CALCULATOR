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
	for(;;){
		system("cls");
		float hasil;
		char input[100], temp, lagi;
		address P;
		Stack X;
		Queue Z;
		node Q;
		Z.First=NULL;
		Z.Last=NULL;
		X.Head=NULL;
		PrintFromFile("asset.txt");
		gotoxy(22, 1);
		scanf("%s",&input);fflush(stdin);
		convertPostfix(&Z,&X,input);
		P=Create_Tree(Z);
		hasil=kalkulasi(P);
		gotoxy(22, 2);
		printf("= %g",hasil);
		gotoxy(0, 14);
		printf("\n\n\n\n\t\t\tLagi?(y/n)");
		fflush(stdin);
		scanf("%c", &lagi);
		if(lagi=='n'){
			return 0;
		}else{
			P->Lson=NULL;
			P->Rson=NULL;
			free(P);
		}
		gotoxy(0, 20);
	}
}
