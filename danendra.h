#ifndef trigonometri_h
#define trigonometri_h

#include <math.h>
#include <stdio.h>

int trigonometri()
{   
    double x, result;
    int pilihan_convert;
    printf("1. sin \n");
    printf("2. cos \n");
    printf("3. tan \n");
    printf("pilihan trigonometri : ");
    scanf("%d",&pilihan_convert);

    swich(pilihan_convert){
        case 1 :
    printf("Masukkan nilai sudut dalam radian: ");
    scanf("%lf", &x);
    result = sin(x);
    printf("Hasil sin: %lf\n", result);
    return result;
    break ;

        case 2 :
    printf("Masukkan nilai sudut dalam radian: ");
    scanf("%lf", &x);
    result = cos(x);
    printf("Hasil cos: %lf\n", result);
    return result;
    break ;  

         case 3 :
    printf("Masukkan nilai sudut dalam radian: ");
    scanf("%lf", &x);
    result = tan(x);
    printf("Hasil tan: %lf\n", result);
    return result;
    break ;
        
        default :
        printf("pilihan tidak valid !");


    }


#endif