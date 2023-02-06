#include <stdio.h>

double celsius_kelvin(double celsius) {
  return celsius + 273.15;
}

double celsius_fahrenheit(double celsius) {
  return (celsius * 9.0 / 5.0) + 32;
}

double celsius_reamur(double celsius) {
  return celsius * 0.8;
}

void menu_suhu (int tipe_suhu, double celsius){
	double hasil;
	switch(tipe_suhu){
	    case 1:
	      hasil = celsius_kelvin(celsius);
	      printf("%.2lf Celsius = %.2lf Kelvin\n", celsius, hasil);
	      break;
	    case 2:
	      hasil = celsius_fahrenheit(celsius);
		printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, hasil);
		break;
		case 3:
			hasil = celsius_reamur(celsius);
			printf("%.2lf Celsius = %.2lf Reamur\n", celsius, hasil);
			break;
		default:
			printf("Pilihan tidak valid\n");
	}
}

void pilih_menu_suhu(int *tipe_suhu, double *celsius){
	printf("Masukkan suhu dalam derajat Celsius: ");
	scanf("%lf", celsius);
	printf("Pilih satuan suhu tujuan:\n");
	printf("1. Kelvin\n");
	printf("2. Fahrenheit\n");
	printf("3. Reamur\n");
	printf("Masukkan pilihan: ");
	scanf("%d", tipe_suhu);
}

int main(){
	int tipe_suhu;
	double celsius;
	pilih_menu_suhu(&tipe_suhu, &celsius);
	menu_suhu(tipe_suhu, celsius);
	return 0;
}