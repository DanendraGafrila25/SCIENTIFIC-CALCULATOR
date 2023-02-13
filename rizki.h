#ifndef rizki_h
#define rizki_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10

void inputMatrix(int mat[][MAX_COL], int row, int col){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("Masukkan elemen matriks baris ke-%d kolom ke-%d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void addMatrix(int mat1[][MAX_COL], int mat2[][MAX_COL], int result[][MAX_COL], int row, int col){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrix(int mat1[][MAX_COL], int mat2[][MAX_COL], int result[][MAX_COL], int row, int col){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrix(int mat1[][MAX_COL], int mat2[][MAX_COL], int result[][MAX_COL], int row1, int col1, int col2){
    int i, j, k;
    for (i = 0; i < row1; i++){
        for (j = 0; j < col2; j++){
            result[i][j] = 0;
            for (k = 0; k < col1; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void outputMatrix(int mat[][MAX_COL], int row, int col){
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixPertama(int mat[][MAX_COL], int row, int col){
	int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixKedua(int mat[][MAX_COL], int row, int col){
	int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void menu_matriks(){
    int mat1[MAX_ROW][MAX_COL], mat2[MAX_ROW][MAX_COL], result[MAX_ROW][MAX_COL];
    int row1, col1, row2, col2, choice;

    do{
        printf("Pilih operasi matriks:\n");
        printf("1. Tambah\n");
        printf("2. Kurang\n");
		printf("3. Kali\n");
		printf("4. Home\n");
		printf("Masukkan pilihan Anda: ");
		scanf("%d", &choice);
        if (choice >= 1 && choice <= 3){
            printf("\nMaksimal ordo matriks 10 x 10\n\n");
            printf("Masukkan ordo matriks pertama (baris kolom): \n");
            scanf("%d%d", &row1, &col1);
            printf("Masukkan ordo matriks kedua (baris kolom): \n");
            scanf("%d%d", &row2, &col2);
        
            if (col1 != row2){
                printf("Ordo matriks tidak sesuai untuk melakukan operasi!\n");
            }else{
                printf("Masukkan elemen matriks pertama:\n");
                inputMatrix(mat1, row1, col1);
                matrixPertama(mat1, row1, col1);
                printf("Masukkan elemen matriks kedua:\n");
                inputMatrix(mat2, row2, col2);
                matrixKedua(mat2, row2, col2);
                switch (choice){
                case 1:
                    addMatrix(mat1, mat2, result, row1, col1);
                    printf("Hasil penjumlahan matriks:\n");
                    break;
                case 2:
                    subtractMatrix(mat1, mat2, result, row1, col1);
                    printf("Hasil pengurangan matriks:\n");
                    break;
                case 3:
                    multiplyMatrix(mat1, mat2, result, row1, col1, col2);
                    printf("Hasil perkalian matriks:\n");
                    break;
                }

                outputMatrix(result, row1, col2);
                printf("\n");
                system("pause");
                system("cls");
            }
        }else if(!(choice >= 1 && choice <= 3)){
        	printf("\n\nAnda memasukkan input yang salah, silahkan coba lagi!");
        	system("cls");
		}
    }while (choice != 4);
    system("cls");
    main();
}   

#endif