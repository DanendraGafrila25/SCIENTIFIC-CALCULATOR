#ifndef penjumlahan_h
#define penjumlahan_h

double penjumlahan(double a, double b){
    return a + b;
}

double pengurangan(double a, double b){
    return a - b;
}

double perkalian(double a, double b){
    double hasil = 0;
    int i;
    for (i = 1; i <= b; i++){
        hasil = hasil + a;
    }
    return hasil;
}

double pembagian(double a, double b){
    double hasil = 0;
    int counter = 0;
    while (a >= b) {
        a = pengurangan(a, b);
        counter++;
    }
    if (counter > 0) {
        hasil = counter;
    }
    double bagi = a;
    while (bagi < b) {
        bagi = perkalian(bagi, 10);
        counter--;
    }
    while (counter < 0) {
        bagi = pembagian(bagi, 10);
        counter++;
    }
    return hasil + pembagian(bagi, b);
}

#endif
