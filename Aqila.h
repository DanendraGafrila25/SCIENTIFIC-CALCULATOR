#ifndef koversi_suhu_h
#define konversi_suhu_h
#include <stdio.h>

void print_menu() {
  printf("Pilih suhu yang ingin dikonversi:\n");
  printf("1. Celcius\n");
  printf("2. Fahrenheit\n");
  printf("3. Kelvin\n");
  printf("4. Reamur\n");
}

float to_celcius(float suhu, int from) {
  switch (from) {
  case 1: // suhu dalam celcius
    return suhu;
  case 2: // suhu dalam fahrenheit
    return (suhu - 32) * 5 / 9;
  case 3: // suhu dalam kelvin
    return suhu - 273.15;
  case 4: // suhu dalam reamur
    return suhu * 5 / 4;
  default:
    printf("Masukan tidak valid\n");
    return 0;
  }
}

float to_fahrenheit(float suhu, int from) {
  switch (from) {
  case 1: // suhu dalam celcius
    return suhu * 9 / 5 + 32;
  case 2: // suhu dalam fahrenheit
    return suhu;
  case 3: // suhu dalam kelvin
    return (suhu - 273.15) * 9 / 5 + 32;
  case 4: // suhu dalam reamur
    return suhu * 9 / 4 + 32;
  default:
    printf("Masukan tidak valid\n");
    return 0;
  }
}

float to_kelvin(float suhu, int from) {
  switch (from) {
  case 1: // suhu dalam celcius
    return suhu + 273.15;
  case 2: // suhu dalam fahrenheit
    return (suhu + 459.67) * 5 / 9;
  case 3: // suhu dalam kelvin
    return suhu;
  case 4: // suhu dalam reamur
    return suhu * 5 / 4 + 273.15;
  default:
    printf("Masukan tidak valid\n");
    return 0;
  }
}

float to_reamur(float suhu, int from) {
  switch (from) {
  case 1: // suhu dalam celcius
    return suhu * 4 / 5;
  case 2: // suhu dalam fahrenheit
    return (suhu - 32) * 4 / 9;
  case 3: // suhu dalam kelvin
    return (suhu - 273.15) * 4 / 5;
  case 4: // suhu dalam reamur
    return suhu;
  default:
    printf("Masukan tidak valid\n");
    return 0;
  }
}

<<<<<<< HEAD
void menu_suhu(int pilihan, double suhu) {
  double hasil;
=======
int main() {
  float suhu;
  int from, to;

  print_menu();
  printf("Dari: ");
  scanf("%d", & from);
>>>>>>> 5eaaf469a942dc6d9a36fefb01105c418fc6e47e

  printf("Masukkan suhu: ");
  scanf("%f", & suhu);

  printf("Ke: ");
  scanf("%d", & to);

  switch (to) {
  case 1:
    printf("%g = %g C\n", suhu, to_celcius(to_fahrenheit(suhu, from), 2));
    break;
  case 2:
    printf("%g = %g F\n", suhu, to_fahrenheit(suhu, from));
    break;
  case 3:
    printf("%g = %g K\n", suhu, to_kelvin(to_celcius(suhu, from), 1));
    break;
  case 4:
    printf("%g = %g R\n", suhu, to_reamur(suhu, from));
    break;
  default:
    printf("Masukan tidak valid\n");
    break;
  }
}
#endif
