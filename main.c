#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


int main(){
	int pilihMenu;
	printf("CALCULATOR-SCIENTIFIC KELOMPOK 4B\n\n");
	printf("Pilih menu di bawah ini\n");
	printf("\n1. Aritmatika\n2. DLL\n");
	printf("Input : ");
	scanf("%d", &pilihMenu);
	switch (pilihMenu){
		case 1:
			system("cls");
			Operasi_hitung();
			break;
		case 2:
			system("cls");
			Hitungan_Lain();
			break;

		default:
			system("cls");
			main();
	}
	
	return 0;
}
