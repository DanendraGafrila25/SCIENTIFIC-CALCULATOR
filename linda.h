#ifndef linda_h
#define linda_h
#define PI 3.14159265358979323846
#define SUDUT 180.0

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

double eksponen(double base, double exponent) {
double hasil = 1.0;
int i;
	if(isdigit(exponent)){
for ( i = 1; i <= exponent; i++) {
hasil *= base;
}
return hasil;
	} else{
		return hasil = pow(base,exponent);
	}
}

double akar(double x, double y) {
    double hasil = 1.0;
    double delta = 0.0001;
    int i;
    
    for (i = 0; i < 10000; i++) {
        double akar_baru = (1.0 / x) * ((x - 1) * hasil + y / pow(hasil, x-1));
        if (fabs(akar_baru - hasil) < delta) {
            break;
        }
        hasil = akar_baru;
    }
    return hasil;
}

float operasiSinus(float sudut){
	float rad=sudut*(PI/180);
	
	return sin(rad);
}

float operasiCosinus(float sudut){
	float rad=sudut*(PI/180);
	
	return cos(rad);
}

float operasiTangen(float sudut){
	float rad=sudut*(PI/180);
	
	return tan(rad);
}

float operasiCosecan(float sudut){
	return 1/operasiSinus(sudut);
}

float operasiSecan(float sudut){
	return 1/operasiCosinus(sudut);
}

float operasiCotangen(float sudut){
	return 1/operasiTangen(sudut);
}

//fungsi operasi Asin
double operasiAsin(double bilangan){
    if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
        return asin(bilangan)* SUDUT/ PI;
    }
}


//fungsi operasi Acos
double operasiAcos(double bilangan) {
	if(bilangan>1 || bilangan<-1)
    {
        printf("not define\n");
    }
    else
    {
		return acos(bilangan)*SUDUT/ PI;
    }
    
}
//fungsi operasi Atan
double operasiAtan(double bilangan) {
    return atan(bilangan) * SUDUT/ PI;
}


#endif
