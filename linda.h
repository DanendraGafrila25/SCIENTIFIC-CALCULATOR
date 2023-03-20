#ifndef linda_h
#define linda_h

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


#endif