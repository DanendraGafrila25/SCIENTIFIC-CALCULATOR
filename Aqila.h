#ifndef Aqila_h
#define Aqila_h
#include <stdio.h>

//logaritma
double logaritma(double x) {
  return log10(x);
}

//trigonometri
double operasi_trigonometri(double sudut, char op[]) {
	sudut = (sudut * M_PI)/180;
    if (strcmp(op, "sec(") == 0) {
		return 1.0 / cos(sudut);
    } else if (strcmp(op, "csc(") == 0) {
		return 1.0 / sin(sudut);
    } else if (strcmp(op, "cot(") == 0) {
		return 1.0 / tan(sudut);
    } else if (strcmp(op, "sin(") == 0) {
    	return sin(sudut);
    } else if (strcmp(op, "cos(") == 0) {
        return cos(sudut);
    } else if (strcmp(op, "tan(") == 0) {
        return tan(sudut);
    } else {
        return 0;
    }
}

//konversi suhu
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

void konversi_suhu() {
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
		case 1: // Asal suhu Celcius
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
		
		case 2: // Asal suhu Kelvin
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
		
		case 3: // Asal suhu Fahrenheit
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
			
		case 4: // Asal suhu Reamur
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
}
//konversi waktu
double detik_ke_jam(int detik) {
	double jam = (double) detik / 3600;
	return jam;
}

double detik_ke_menit(int detik) {
	double minute = (double) detik / 60;
	return minute;
}

double jam_ke_detik(int jam) {
	double detik = jam * 3600;
	return detik;
}

int jam_ke_menit(int jam) {
	int minute = jam * 60;
	return minute;
}

double menit_ke_jam(int menit) {
	double hour = (double) menit / 60;
	return hour;
}

int menit_ke_detik(int menit) {
	int second = menit * 60;
	return second;
}

void konversi_waktu() {
	int pilihan, hour, menit, second;
	printf("1. Konversi detik ke jam\n");
	printf("2. Konversi detik ke menit\n");
	printf("3. Konversi jam ke detik\n");
	printf("4. Konversi jam ke menit\n");
	printf("5. Konversi menit ke jam\n");
	printf("6. Konversi menit ke detik\n");
	printf("Masukkan pilihan: ");
	scanf("%d", & pilihan);
	
	switch (pilihan) {
		case 1:
			printf("Masukkan detik: ");
			scanf("%d", & second);
			double jam = detik_ke_jam(second);
			printf("%d detik adalah %0.2f jam\n", second, jam);
			break;
		case 2:
			printf("Masukkan detik: ");
			scanf("%d", & second);
			double minute = detik_ke_menit(second);
			printf("%d detik adalah %0.2f menit", second, minute);
			break;
		case 3:
			printf("Masukkan jam: ");
			scanf("%d", & hour);
			double detik = jam_ke_detik(hour);
			printf("%d jam adalah %g detik", hour, detik);
			break;
		case 4:
			printf("Masukkan jam: ");
			scanf("%d", & hour);
			int menit = jam_ke_menit(hour);
			printf("%d jam adalah %d menit", hour, menit);
			break;
		case 5:
			printf("Masukkan menit: ");
			scanf("%d", & menit);
			double hour = menit_ke_jam(menit);
			printf("%d menit adalah %0.2f jam", menit, hour);
			break;
		case 6:
			printf("Masukkan menit: ");
			scanf("%d", & menit);
			int second = menit_ke_detik(menit);
			printf("%d menit adalah %d detik", menit, second);
			break;
		default:
			printf("Pilihan tidak valid\n");
	}
}
#endif
