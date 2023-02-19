#ifndef Aqila_h
#define Aqila_h
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

double kelvin_celsius(double kelvin) {
  return kelvin - 273.15;
}

double kelvin_fahrenheit(double kelvin) {
  return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

double kelvin_reamur(double kelvin) {
  return (kelvin - 273.15) * 0.8;
}

double fahrenheit_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheit_kelvin(double fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double fahrenheit_reamur(double fahrenheit) {
  return (fahrenheit - 32) * 4.0 / 9.0;
}

double reamur_celsius(double reamur) {
  return reamur / 0.8;
}

double reamur_kelvin(double reamur) {
  return reamur / 0.8 + 273.15;
}

double reamur_fahrenheit(double reamur) {
  return reamur * 9.0 / 4.0 + 32;
}

int main() {
  double suhu, hasil;
  int pilihan;

  printf("Pilih satuan suhu asal:\n");
  printf("1. Celsius\n");
  printf("2. Kelvin\n");
  printf("3. Fahrenheit\n");
  printf("4. Reamur\n");
  printf("Masukkan pilihan: ");
  scanf("%d", & pilihan);
  printf("Masukkan suhu: ");
  scanf("%lf", & suhu);

  switch (pilihan) {
  case 1:
    printf("Pilih satuan suhu tujuan:\n");
    printf("1. Kelvin\n");
    printf("2. Fahrenheit\n");
    printf("3. Reamur\n");
    printf("Masukkan pilihan: ");
    scanf("%d", & pilihan);

    switch (pilihan) {
    case 1:
      hasil = celsius_kelvin(suhu);
      printf("%g Celsius = %g Kelvin\n", suhu, hasil);
      break;
    case 2:
      hasil = celsius_fahrenheit(suhu);
      printf("%g Celsius = %g Fahrenheit\n", suhu, hasil);
      break;
    case 3:
      hasil = celsius_reamur(suhu);
      printf("%g Celsius = %g Reamur\n", suhu, hasil);
      break;
    default:
      printf("Pilihan tidak valid\n");
    }
    break;
  case 2:
    printf("Pilih satuan suhu tujuan:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Reamur\n");
    printf("Masukkan pilihan: ");
    scanf("%d", & pilihan);
    switch (pilihan) {
    case 1:
      hasil = kelvin_celsius(suhu);
      printf("%g Kelvin = %g Celsius\n", suhu, hasil);
      break;
    case 2:
      hasil = kelvin_fahrenheit(suhu);
      printf("%g Kelvin = %g Fahrenheit\n", suhu, hasil);
      break;
    case 3:
      hasil = kelvin_reamur(suhu);
      printf("%g Kelvin = %g Reamur\n", suhu, hasil);
      break;
    default:
      printf("Pilihan tidak valid\n");
    }
    break;
  case 3:
    printf("Pilih satuan suhu tujuan:\n");
    printf("1. Celsius\n");
    printf("2. Kelvin\n");
    printf("3. Reamur\n");
    printf("Masukkan pilihan: ");
    scanf("%d", & pilihan);

    switch (pilihan) {
    case 1:
      hasil = fahrenheit_celsius(suhu);
      printf("%g Fahrenheit = %g Celsius\n", suhu, hasil);
      break;
    case 2:
      hasil = fahrenheit_kelvin(suhu);
      printf("%g Fahrenheit = %g Kelvin\n", suhu, hasil);
      break;
    case 3:
      hasil = fahrenheit_reamur(suhu);
      printf("%g Fahrenheit = %g Reamur\n", suhu, hasil);
      break;
    default:
      printf("Pilihan tidak valid\n");
    }
    break;
  case 4:
    printf("Pilih satuan suhu tujuan:\n");
    printf("1. Celsius\n");
    printf("2. Kelvin\n");
    printf("3. Fahrenheit\n");
    printf("Masukkan pilihan: ");
    scanf("%d", & pilihan);

    switch (pilihan) {
    case 1:
      hasil = reamur_celsius(suhu);
      printf("%g Reamur =%g Celsius\n", suhu, hasil);
      break;
    case 2:
      hasil = reamur_kelvin(suhu);
      printf("%g Reamur = %g Kelvin\n", suhu, hasil);
      break;
    case 3:
      hasil = reamur_fahrenheit(suhu);
      printf("%g Reamur = %g Fahrenheit\n", suhu, hasil);
      break;
    default:
      printf("Pilihan tidak valid\n");
    }
    break;
  default:
    printf("Pilihan tidak valid\n");
  }
  return 0;
}
#endif