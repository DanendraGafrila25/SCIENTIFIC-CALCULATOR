#ifndef build_tree_h
#define build_tree_h

// Fungsi untuk mengonversi ekspresi infix menjadi postfix
void convertPostfix(Queue* Z, Stack* X, char* input) {
	node P;
	char token, c;
	int i, temp;
	double angka;

	for(i = 0; i < strlen(input); i++){
		token = input[i];

		if(isdigit(token) || (input[i] == '-' && !isdigit(input[i-1]) && isdigit(input[i+1]) && i == 0)){
			// Jika token adalah digit, maka membaca angka dan menambahkannya ke antrian operand
			char num[strlen(input)];
			int j = 0;

			while(isdigit(input[i]) || input[i] == '.' || (input[i] == '-' && i == 0)){
				num[j++] = input[i];
				i++;
			}

			num[j] = '\0';
			angka = strtod(num, NULL);
			EnqueOperand(&*Z, angka, &P);
			i--;
		}else if(isOperator(token) && X->Head != NULL && X->Head->oprtr != '('){
			// Jika token adalah operator dan tumpukan operator tidak kosong serta operator di atas tumpukan bukan '(',
			// maka melakukan pemindahan operator dari tumpukan ke antrian berdasarkan prioritas operator
			c = X->Head->oprtr;

			while(derajatOperator(token) <= derajatOperator(c) && X->Head != NULL){
				EnqueOperator(&*Z, PopStack(&*X), &P);
			}

			PushStack(&*X, token, &P);
		}else if (token == 'l'){
			// Jika token adalah 'l' (untuk logaritma), melakukan operasi khusus untuk logaritma
			char log[4];
			char Num[10];
			double numerus, basis, hasil;
			int j = 0, k, y, x = 0;

			if(isdigit(input[i - 1])){
				// Jika sebelum 'l' terdapat angka, maka mengambil angka tersebut dan membaca angka yang menjadi argumen logaritma
				basis = DequeOperand(&*Z);
				while(input[i] != ')'){
					if (isdigit(input[i]) || input[i] == '.') {
						Num[j++] = input[i];
					} else {
						log[x++] = input[i];
					}
					i++;
				}
				Num[j] = '\0';
				numerus = strtof(Num, NULL);
				hasil = logaritmaProses(basis, numerus, log);
				EnqueOperand(&*Z, hasil, &P);
			}else{
				// Jika tidak terdapat angka sebelum 'l', maka membaca angka yang menjadi argumen logaritma
				while(input[i] != ')'){
					if(isdigit(input[i]) || input[i] == '.'){
						Num[j++] = input[i];
					}else{
						log[x++] = input[i];
					}
					i++;
				}

				for(k = x ; k < 4; k++){ // menghapus karakter tidak penting
					log[k] = '\0';
				}

				for(y = j ; y < 10; y++){ // menghapus karakter tidak penting
					Num[y] = '\0';
				}

				numerus = strtof(Num, NULL);
				hasil = logaritmaProses(10, numerus, log);
				EnqueOperand(&*Z, hasil, &P);
			}       
		}else if(input[i] == '|'){ // nilai mutlak
			int j = 0;
			double angka, hasil;
			char* number = malloc (16 * sizeof(char));
			while(isdigit(input[i+1]) || input[i+1] == '.' || input[i+1] == '-'){
				number[j++] = input[++i];
			}
			angka = strtod(number, NULL);
			hasil = fabs(angka);
			EnqueOperand(&*Z, hasil, &P);
			i++;
		}else if(input[i] == 'C' || input[i] == 'P'){
			int temp = i;
			char number[2];
			int j, n, r, hasil;
			if(isdigit(input[i-1])){
				n = DequeOperand(&*Z);
			}
			for(j = 0; j < 3; j++){
				if(isdigit(input[i+j+1])){
					number[j] = input[i+j+1];
					i++;
				}
			}
			r = atoi(number);
			hasil = menuKombinatorial(n, r, input[temp]);
			EnqueOperand(&*Z, hasil, &P);
		}else if(input[i] == 's' || input[i] == 'c' || input[i] == 't' || input[i] == 'a'){
			// jika trigonometri
			int j = 0, k = 0, l;
			double number;
			char trigono[7], angka[10];
			bool negatif = false;

			while(!isdigit(input[i]) && input[i] != '-'){
				trigono[j] = input[i];
				j++;
				i++;
			}

			for(l = j; l < 9; l++){ // menghapus karakter tidak penting
				trigono[l] = '\0';
			}

			while(isdigit(input[i]) || input[i] == '.' || input[i] == '-'){
				if(input[i] == '-'){
					negatif = true;
				}
				angka[k] = input[i];
				k++;
				i++;
			}
			number = strtod(angka, NULL);
			if(negatif == true){
				number = 360 - (-number);
			}
			number = simbol_operasi_trigonometri(number, trigono);
			EnqueOperand(&*Z, number, &P);
		}else if(token == 'm'){
			int dividen, divisor, j = 0;
			char* number = malloc (16 * sizeof(char));
			
			if(isdigit(input[i-1])){
				dividen = DequeOperand(&*Z);
			}
			while(input[i] != ')'){
				if(isdigit(input[i]) || input[i] == '.' || input[i] == '-'){
					number[j++] = input[i];
				}
				i++;
			}
			divisor = strtod(number, NULL);
			dividen = modulus(dividen, divisor);
			EnqueOperand(&*Z, dividen, &P);
		}else if(token == '!'){
			double a;
			if(isdigit(input[i-1])){
				a = DequeOperand(&*Z);
			}
			a = faktorial(a);
			EnqueOperand(&*Z, a, &P);
		}else if (token == ')'){
			// Jika token adalah ')', melakukan pemindahan operator dari tumpukan ke antrian hingga ditemukan '('
			c = X->Head->oprtr;

			while(c != '('){
				EnqueOperator(&*Z, PopStack(&*X), &P);
				c = X->Head->oprtr;
			}

			PopStack(&*X);
		}else{
			// Jika token bukan digit, operator, atau ')', maka menambahkannya ke tumpukan operator
			PushStack(&*X, token, &P);
		}
	}

	while (X -> Head != NULL){
		// Setelah selesai membaca semua token, memindahkan operator yang tersisa dari tumpukan ke antrian
		c = PopStack(&*X);
		EnqueOperator(&*Z, c, &P);
	}
}

#endif
