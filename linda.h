#ifndef linda_h
#define linda_h
#include <stdio.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}
float hitungRataRata(float bilangan[], int jumlahBilangan) {
        int i;
        float total = 0;

        for (i = 0; i < jumlahBilangan; i++) {
            total += bilangan[i];
        }

        return total / jumlahBilangan;
    }

float hitungMedian(float bilangan[], int jumlahBilangan) {
        float median;

        qsort(bilangan, jumlahBilangan, sizeof(float), compare);

        if (jumlahBilangan % 2 == 0) {
            median = (bilangan[jumlahBilangan / 2 - 1] + bilangan[jumlahBilangan / 2]) / 2;
        } else {
            median = bilangan[jumlahBilangan / 2];
        }

        return median;
    }

float hitungModus(float bilangan[], int jumlahBilangan) {
        int i, j, count;
        float maxCount = 0, maxValue, modus;

        for (i = 0; i < jumlahBilangan; i++) {
            count = 1;
            for (j = i + 1; j < jumlahBilangan; j++) {
                if (bilangan[i] == bilangan[j]) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxValue = bilangan[i];
            }
        }

        modus = maxValue;

        return modus;
    }



double statistika()
{
        int jumlahBilangan, i, pilihan;
        float bilangan[100], rataRata, median, modus;
        // Meminta pengguna untuk memasukkan jumlah bilangan
        printf("Masukkan jumlah bilangan: ");
        scanf("%d", &jumlahBilangan);

        // Meminta pengguna untuk memasukkan bilangan
        for (i = 0; i < jumlahBilangan; i++) {
            printf("Masukkan bilangan ke-%d: ", i + 1);
            scanf("%f", &bilangan[i]);
        }
        printf("akan dihitung dalam bentuk apa bilangan tersebut :\n");
        printf("1. Rata-Rata\n");
        printf("2. Median\n");
        printf("3. Modus\n");
        printf("masukkan pilihan :");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1 :
                rataRata = hitungRataRata(bilangan, jumlahBilangan);
                printf("rata-rata dari %d bilangan adalah: %.2f\n", jumlahBilangan, rataRata);
                 break ;
            case 2 :
                median = hitungMedian(bilangan, jumlahBilangan);
                printf("median dari %d bilangan adalah: %.2f\n", jumlahBilangan, median);
               	break ;
            case 3 :
                modus = hitungModus(bilangan, jumlahBilangan);
                printf("modus dari %d bilangan adalah: %.2f\n", jumlahBilangan, modus);
                 break ;
            default :
                printf("pilihan tidak valid !");
        }
}

double eksponen(double a,double b){
   return pow(a,b);
}

double logaritma(double x) {
  return log10(x);
}

double akar(double x, double y){
	return  pow(y, 1/x);
}



#endif
