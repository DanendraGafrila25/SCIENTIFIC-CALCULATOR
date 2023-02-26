#ifndef rizki_h
#define rizki_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define MAX_COLUMN 5

void Hitungan_Lain(){
	int pilihan;
	printf("Hitungan Lain : \n1. Matriks\n2. Koversi Suhu\n3. Statistika\n4. Konversi Waktu\n");
	printf("Pilihan :");
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1 :
			system("cls");
			menu_matriks();
			break;
		case 2 :
			system("cls");
			konversi_suhu();
			break;
		case 3 :
			system("cls");
			statistika();
			break;
		case 4 :
			system("cls");
			konversi_waktu();
			break;
		default :
			system("cls");
			main();
	}
}

void inputMatrix(double matrix[][MAX_COLUMN], int row, int column){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++){
            printf("Masukkan elemen matriks baris ke-%d kolom ke-%d: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void addMatrix(double matrix1[][MAX_COLUMN], double matrix2[][MAX_COLUMN], double result[][MAX_COLUMN], int row, int column){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(double matrix1[][MAX_COLUMN], double matrix2[][MAX_COLUMN], double result[][MAX_COLUMN], int row, int column){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrix(double matrix1[][MAX_COLUMN], double matrix2[][MAX_COLUMN], double result[][MAX_COLUMN], int row1, int column1, int column2){
    int i, j, k;
    for (i = 0; i < row1; i++){
        for (j = 0; j < column2; j++){
            result[i][j] = 0;
            for (k = 0; k < column1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void outputMatrix(double result[][MAX_COLUMN], int row, int column){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++){
            printf("%g\t", result[i][j]);
        }
        printf("\n");
    }
}

void matrixPertama(double matrix1[][MAX_COLUMN], int row1, int column1){
	int i, j;
    for (i = 0; i < row1; i++){
        for (j = 0; j < column1; j++){
            printf("%g\t", matrix1[i][j]);
        }
        printf("\n");
    }
}

void matrixKedua(double matrix2[][MAX_COLUMN], int row2, int column2){
	int i, j;
    for (i = 0; i < row2; i++){
        for (j = 0; j < column2; j++){
            printf("%g\t", matrix2[i][j]);
        }
        printf("\n");
    }
}

void menu_matriks(){
    double matrix1[MAX_ROW][MAX_COLUMN], matrix2[MAX_ROW][MAX_COLUMN], result[MAX_ROW][MAX_COLUMN];
    int row1, column1, row2, column2, choice;

    do{
        printf("Pilih operasi matriks:\n");
        printf("1. Tambah\n");
        printf("2. Kurang\n");
		printf("3. Kali\n");
		printf("4. Home\n");
		printf("Masukkan pilihan Anda: ");
		scanf("%d", &choice);
        if (choice >= 1 && choice <= 3){
            printf("\nMaksimal ordo matriks %d x %d\n\n", MAX_ROW, MAX_COLUMN);
            printf("Masukkan jumlah ordo matriks pertama (baris x kolom): \n");
            printf("Baris: ");
            scanf("%d", &row1);
            printf("Kolom:  ");
            scanf("%d", &column1);
            printf("\nMasukkan jumlah ordo matriks kedua (baris x kolom): \n");
            printf("Baris: ");
            scanf("%d", &row2);
            printf("Kolom: ");
            scanf("%d", &column2);
        
            if ((choice == 1 || choice == 2) && (row1 != row2 || column1 != column2)) {
			    printf("Ordo matriks tidak sesuai untuk melakukan operasi!\n");
			    system("pause");
        		system("cls");
			} else if (choice == 3 && column1 != row2) {
			    printf("Ordo matriks tidak sesuai untuk melakukan operasi!\n");
				system("pause");
        		system("cls");
			} else if(row1 > MAX_ROW || row2 > MAX_ROW || column1 > MAX_COLUMN || column2 > MAX_COLUMN){
				printf("Ordo matriks tidak sesuai untuk melakukan operasi!\n");
				system("pause");
        		system("cls");
			} else {
                printf("\n\nMasukkan elemen matriks pertama:\n");
                inputMatrix(matrix1, row1, column1);
                matrixPertama(matrix1, row1, column1);
                printf("\n\nMasukkan elemen matriks kedua:\n");
                inputMatrix(matrix2, row2, column2);
                matrixKedua(matrix2, row2, column2);
                switch (choice){
                case 1:
                    addMatrix(matrix1, matrix2, result, row1, column1);
                    printf("\nHasil penjumlahan matriks:\n");
                    break;
                case 2:
                    subtractMatrix(matrix1, matrix2, result, row1, column1);
                    printf("\nHasil pengurangan matriks:\n");
                    break;
                case 3:
                    multiplyMatrix(matrix1, matrix2, result, row1, column1, column2);
                    printf("\nHasil perkalian matriks:\n");
                    break;
                }

                outputMatrix(result, row1, column2);
                printf("\n");
                system("pause");
                system("cls");
            }
        }else if(choice == 4){
        	system("pause");
		}else if(!(choice >= 1 && choice <= 3)){
        	printf("\n\nAnda memasukkan input yang salah, silahkan coba lagi!\n");
        	system("pause");
        	system("cls");
		}
    }while (choice != 4);
    system("cls");
    main();
}   

#endif
