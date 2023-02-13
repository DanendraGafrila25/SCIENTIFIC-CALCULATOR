#include <stdio.h>
#include <math.h>
#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include "modul_operasi_hitung.c"

int main(){
	int tipe_suhu;
	double celsius;
	int pilihMenu;
	printf("Pilih menu di bawah ini\n");
	printf("1. Operasi hitung\n");
	printf("2. Konversi suhu\n");
	printf("3. Matriks\n");
//	printf("4. Statistika\n");
	printf("Input : ");
	scanf("%d", &pilihMenu);
	switch (pilihMenu){
		case 1:
			system("cls");
			Operasi_hitung();
			break;
		case 2:
			system("cls");
			pilih_menu_suhu(&tipe_suhu, &celsius);
			menu_suhu (tipe_suhu, celsius);
			break;
		case 3:
			system("cls");
			menu_matriks();
			break;
//        case 4:
//          system("cls");
//			statistika();
//          break;
		default:
			system("cls");
			main();
	}
	
	return 0;
}
