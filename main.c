#include <stdio.h>
#include <math.h>
#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"

int main(){
	int tipe_suhu;
	double celsius;
	int pilihMenu;
	printf("Pilih menu di bawah ini\n");
	printf("1. Trigonometri\n");
	printf("2. Konversi suhu\n");
	printf("3. Penjumlahan\n");
	printf("4. Eksponen\n");
    printf("5. Logaritma\n\n");
	printf("Input : ");
	scanf("%d", &pilihMenu);
	switch (pilihMenu){
		case 1:
			system("cls");
			trigonometri();
			break;
		case 2:
			system("cls");
			pilih_menu_suhu(&tipe_suhu, &celsius);
			menu_suhu (tipe_suhu, celsius);
			break;
		case 3:
			system("cls");
			inputAngka();
			break;
		case 4:
			system("cls");
			eksponen();
			break;
        case 5:
            system("cls");
			logaritma();
            break;
		default:
			system("cls");
			main();
	}
	
	return 0;
}
