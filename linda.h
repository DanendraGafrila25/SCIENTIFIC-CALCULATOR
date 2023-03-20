#ifndef linda_h
#define linda_h

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

int eksponen(int base, int exponent) {
  int result = 1;
  
  for (int i = 1; i <= exponent; i++) {
    result *= base;
  }

  return result;
}

double akar(double x, double y){
	return  pow(y, 1/x);
}

#endif
