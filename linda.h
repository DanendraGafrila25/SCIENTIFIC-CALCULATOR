#ifndef linda_h
#define linda_h

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
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
