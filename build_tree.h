#ifndef build_tree_h
#define build_tree_h
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <ctype.h>

#include "tree.h"

#include "Aqila.h"

#include "faras.h"

#include "linda.h"

#include "rizki.h"

int derajatOperator(infotype oper) {
  if (oper == '+' || oper == '-') {
    return 1;
  } else if (oper == '*' || oper == '/') {
    return 2;
  } else if (oper == '^' || oper == 'v') {
    return 3;
  } else if (oper == '(' || oper == ')') {
    return 0;
  } else {
    printf("Error, Operator Tidak Diketahui: %c", oper);
    exit(1);
  }
}

int isOperator(infotype oper) {
  if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 'v') {
    return 1;
  }
  return 0;
}

address CreateNode(infotype data) {
  address P;

  P = (address) malloc(sizeof(Tree)); // Mengalokasikan memori untuk node baru dalam pohon (tree)
  Data(P) = data; // Menyimpan data pada node baru
  Rson(P) = Nil; // Menginisialisasi pointer anak kanan dengan nilai Null (kosong)
  Lson(P) = Nil; // Menginisialisasi pointer anak kiri dengan nilai Null (kosong)

  return P; // Mengembalikan alamat node yang baru dibuat
}

address BuildTree(infotype postfix[]) {
  address P;
  address stack[50]; // Array untuk menyimpan node dalam stack
  int i, len, top = -1; // Variabel i untuk iterasi, len untuk panjang postfix, top sebagai indeks stack
  infotype c; // Variabel untuk menyimpan karakter saat ini dari postfix

  len = strlen(postfix); // Menghitung panjang postfix

  for (i = 0; i < len; i++) {
    c = postfix[i]; // Mengambil karakter saat ini dari postfix
    if (isdigit(c)) {
      P = CreateNode(c); // Jika karakter adalah digit, buat node baru dengan data c
    } else {
      P = CreateNode(c); // Jika karakter bukan digit, buat node baru dengan data c
      Rson(P) = stack[top--]; // Ambil node dari stack sebagai anak kanan
      Lson(P) = stack[top--]; // Ambil node dari stack sebagai anak kiri
    }
    stack[++top] = P; // Tambahkan node ke stack
  }
  return stack[0]; // Mengembalikan akar pohon (root)
}

void PostOrder(address P) {
  if (P != Nil) {
    PostOrder(Lson(P)); // Rekursi pada anak kiri
    PostOrder(Rson(P)); // Rekursi pada anak kanan
    if (P -> isOperator == 1) {
      printf("%c ", P -> data); // Jika node adalah operator, cetak karakter operator
    } else {
      printf("%g ", P -> operand); // Jika node adalah operand, cetak nilai operand
    }
  }
}

void PushStack(Stack * First, char item, node * P) {
  * P = (node) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
  if (P == NULL) {
    printf("Gagal Alokasi");
  } else {
    ( * P) -> oprtr = item; // Menyimpan nilai operator pada node
    ( * P) -> isoperator = 1; // Menandai node sebagai operator
    ( * P) -> next = NULL;

    if (First -> Head == NULL) {
      ( * First).Head = * P; // Jika stack kosong, node baru menjadi Head
      ( * First).Head -> next = NULL;
    } else {
      ( * P) -> next = First -> Head; // Menyambungkan node baru dengan Head yang lama
      First -> Head = * P; // Node baru menjadi Head yang baru
    }
  }
}

char PopStack(Stack * First) {
  node P;
  P = First -> Head; // Mengambil node Head saat ini
  First -> Head = P -> next; // Mengatur Head baru menjadi node berikutnya
  char oprtr = P -> oprtr; // Menyimpan nilai operator dari node yang dihapus
  free(P); // Menghapus node yang diambil dari stack
  return oprtr; // Mengembalikan nilai operator yang dihapus
}

void ViewAsc(Queue First) {
  node P;
  P = First.First;
  if (P != NULL) {

    while (P != NULL) {
      if (P -> isoperator == 1) {
        printf("%c ", P -> oprtr);
      } else {
        printf("%g ", P -> operand);
      }
      P = P -> next;
    }
  } else if (P == NULL) {
    printf("list kosong");
  }
}

void ViewAscStack(Stack First) {
  node P;
  P = First.Head; // Mengambil node pertama dari tumpukan
  if (P != NULL) {
    // Jika tumpukan tidak kosong
    while (P != NULL) {
      if (P -> isoperator == 1) {
        printf("%c ", P -> oprtr); // Mencetak karakter operator dari node saat ini
      } else {
        printf("%g ", P -> operand); // Mencetak angka operan dari node saat ini
      }
      P = P -> next; // Pindah ke node berikutnya
    }
  } else if (P == NULL) {
    printf("list kosong"); // Jika tumpukan kosong, cetak pesan "list kosong"
  }
}

void EnqueOperator(Queue * First, char item, node * P) {
  * P = (address) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
  if (P == NULL) {
    printf("Gagal Alokasi"); // Jika alokasi gagal, cetak pesan "Gagal Alokasi"
  } else {
    ( * P) -> oprtr = item; // Menyimpan karakter operator pada node baru
    ( * P) -> next = NULL; // Mengatur pointer next pada node baru menjadi NULL
    ( * P) -> isoperator = 1; // Menandai bahwa node baru adalah operator

    if (First -> First == NULL) {
      ( * First).First = * P; // Jika antrian kosong, node baru menjadi elemen pertama
      ( * First).Last = * P; // Jika antrian kosong, node baru menjadi elemen terakhir
      ( * First).Last -> next = NULL; // Mengatur pointer next pada elemen terakhir menjadi NULL
    } else {
      ( * P) -> next = NULL; // Mengatur pointer next pada node baru menjadi NULL
      First -> Last -> next = * P; // Mengatur pointer next pada elemen terakhir menjadi node baru
      First -> Last = * P; // Mengubah elemen terakhir menjadi node baru
    }
  }
}

void EnqueOperand(Queue * First, float item, node * P) {
  * P = (address) malloc(sizeof(ElmtList)); // Mengalokasikan memori untuk node baru
  if (P == NULL) {
    printf("Gagal Alokasi"); // Jika alokasi gagal, cetak pesan "Gagal Alokasi"
  } else {
    ( * P) -> operand = item; // Menyimpan nilai operand pada node baru
    ( * P) -> next = NULL; // Mengatur pointer next pada node baru menjadi NULL
    ( * P) -> isoperator = 0; // Menandai bahwa node baru bukan operator

    if (First -> First == NULL) {
      ( * First).First = * P; // Jika antrian kosong, node baru menjadi elemen pertama
      ( * First).Last = * P; // Jika antrian kosong, node baru menjadi elemen terakhir
      ( * First).Last -> next = NULL; // Mengatur pointer next pada elemen terakhir menjadi NULL
    } else {
      ( * P) -> next = NULL; // Mengatur pointer next pada node baru menjadi NULL
      First -> Last -> next = * P; // Mengatur pointer next pada elemen terakhir menjadi node baru
      First -> Last = * P; // Mengubah elemen terakhir menjadi node baru
    }
  }
}


//float kalkulasi()
void convertPostfix(Queue * Z, Stack * X, char * input) {
  node P;
  char token, c;
  int i, temp;
  float angka;

  for (i = 0; i < strlen(input); i++) {
    token = input[i];

    if (isdigit(token)) {
      // Jika token adalah digit, maka membaca angka dan menambahkannya ke antrian operand
      char num[strlen(input)];
      int j = 0;

      while (isdigit(input[i]) || input[i] == '.') {
        num[j++] = input[i];
        i++;
      }

      num[j] = '\0';
      angka = strtof(num, NULL);
      EnqueOperand( & * Z, angka, & P);
      i--;
    } else if (isOperator(token) && X -> Head != NULL && X -> Head -> oprtr != '(') {
      // Jika token adalah operator dan tumpukan operator tidak kosong serta operator di atas tumpukan bukan '(',
      // maka melakukan pemindahan operator dari tumpukan ke antrian berdasarkan prioritas operator
      c = X -> Head -> oprtr;

      while (derajatOperator(token) <= derajatOperator(c) && X -> Head != NULL) {
        EnqueOperator( & * Z, PopStack( & * X), & P);
      }

      PushStack( & * X, token, & P);
    } else if (token == 'l') {
      // Jika token adalah 'l' (untuk logaritma), melakukan operasi khusus untuk logaritma
      char log[10];
      char Num[100];
      float angka;
      float a, hasil;
      int j = 0, x = 0;

      if (isdigit(input[i - 1])) {
        // Jika sebelum 'l' terdapat angka, maka mengambil angka tersebut dan membaca angka yang menjadi argumen logaritma
        a = DequeOperand( & * Z);

        while (input[i] != ')') {
          if (isdigit(input[i]) || input[i] == '.') {
            Num[j++] = input[i];
          } else {
            log[x++] = input[i];
          }
          i++;
        }

        Num[j] = '\0';
        angka = strtof(Num, NULL);
        hasil = logaritmaProses(a, angka, log);
        EnqueOperand( & * Z, hasil, & P);
      } else {
        // Jika tidak terdapat angka sebelum 'l', maka membaca angka yang menjadi argumen logaritma
        while (input[i] != ')') {
          if (isdigit(input[i]) || input[i] == '.') {
            Num[j++] = input[i];
          } else {
            log[x++] = input[i];
          }
          i++;
        }

        Num[j] = '\0';
        angka = strtof(Num, NULL);
        hasil = logaritmaProses(10, angka, log);
        EnqueOperand( & * Z, hasil, & P);
      }
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
		for(l = j; l < 9; l++){
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
    }else if (token == ')') {
      // Jika token adalah ')', melakukan pemindahan operator dari tumpukan ke antrian hingga ditemukan '('
      c = X -> Head -> oprtr;

      while (c != '(') {
        EnqueOperator( & * Z, PopStack( & * X), & P);
        c = X -> Head -> oprtr;
      }

      PopStack( & * X);
    } else {
      // Jika token bukan digit, operator, atau ')', maka menambahkannya ke tumpukan operator
      PushStack( & * X, token, & P);
    }
  }

  while (X -> Head != NULL) {
    // Setelah selesai membaca semua token, memindahkan operator yang tersisa dari tumpukan ke antrian
    c = PopStack( & * X);
    EnqueOperator( & * Z, c, & P);
  }
}

address Create_Tree(Queue Z) {
  address P; // variabel untuk menyimpan alamat simpul
  address stack[50]; // array untuk menampung tumpukan sementara
  node Q; // variabel untuk mengiterasi melalui antrian
  int i, len, top = -1; // variabel indeks, panjang antrian, dan indeks puncak tumpukan
  infotype c; // variabel untuk menyimpan operator
  float d; // variabel untuk menyimpan operand

  Q = Z.First; // menginisialisasi Q dengan node pertama dalam antrian

  while (Q != NULL) {
    if (Q -> isoperator == 1) {
      // Jika node dalam antrian adalah operator, membuat simpul dengan operator sebagai data
      c = Q -> oprtr;
      P = CreateNodeOperator(c);
      Rson(P) = stack[top--]; // mengambil simpul anak kanan dari tumpukan
      Lson(P) = stack[top--]; // mengambil simpul anak kiri dari tumpukan
    } else {
      // Jika node dalam antrian adalah operand, membuat simpul dengan operand sebagai data
      d = Q -> operand;
      P = CreateNodeOperand(d);
    }
    stack[++top] = P; // memasukkan simpul ke dalam tumpukan
    Q = Q -> next; // pindah ke node berikutnya dalam antrian
  }

  return stack[0]; // mengembalikan alamat akar pohon yang ada di tumpukan
}

address CreateNodeOperand(float input) {
  address P; // variabel untuk menyimpan alamat simpul
  P = (address) malloc(sizeof(Tree)); // mengalokasikan memori untuk simpul baru
  P -> operand = input; // menyimpan operand sebagai data pada simpul
  P -> isOperator = 0; // menandai simpul sebagai operand (bukan operator)
  P -> Lson = NULL; // mengatur anak kiri simpul menjadi NULL
  P -> Rson = NULL; // mengatur anak kanan simpul menjadi NULL
  return P; // mengembalikan alamat simpul yang telah dibuat
}

address CreateNodeOperator(char input) {
  address P; // variabel untuk menyimpan alamat simpul
  P = (address) malloc(sizeof(Tree)); // mengalokasikan memori untuk simpul baru
  P -> data = input; // menyimpan operator sebagai data pada simpul
  P -> isOperator = 1; // menandai simpul sebagai operator (bukan operand)
  P -> Lson = NULL; // mengatur anak kiri simpul menjadi NULL
  P -> Rson = NULL; // mengatur anak kanan simpul menjadi NULL
  return P; // mengembalikan alamat simpul yang telah dibuat
}

double kalkulasi(address P) {
  if (P -> isOperator == 1) {
    double Lson = kalkulasi(P -> Lson), Rson = kalkulasi(P -> Rson);
    if (P -> data == '+') {
      return kalkulasi(P -> Lson) + kalkulasi(P -> Rson);
    } else if (P -> data == '-') {
      return kalkulasi(P -> Lson) - kalkulasi(P -> Rson);
    } else if (P -> data == '-') {
      return kalkulasi(P -> Lson) - kalkulasi(P -> Rson);
    } else if (P -> data == '/') {
      return kalkulasi(P -> Lson) / kalkulasi(P -> Rson);
    } else if (P -> data == '*') {
      return kalkulasi(P -> Lson) * kalkulasi(P -> Rson);
    } else if (P -> data == '^') {
      return pow(kalkulasi(P -> Lson), kalkulasi(P -> Rson));
    }
  }

  return P -> operand;
}

float DequeOperand(Queue * A) {
  float q; // variabel untuk menyimpan nilai operand yang di-dequeue
  node First, Last, Throw; // variabel untuk menyimpan penunjuk pada simpul pertama, terakhir, dan simpul yang akan dihapus

  First = A -> First; // mengambil penunjuk pada simpul pertama
  Last = A -> Last; // mengambil penunjuk pada simpul terakhir

  if (First == NULL) {
    printf("Queue Empty"); // jika antrian kosong, cetak pesan "Queue Empty"
  } else {
    if (First != Last) {
      while (First -> next != Last) {
        First = First -> next; // mencari simpul sebelum simpul terakhir
      }
      Throw = Last; // menyimpan penunjuk pada simpul terakhir
      q = Last -> operand; // menyimpan nilai operand pada simpul terakhir
      A -> Last = First; // mengatur penunjuk simpul terakhir menjadi simpul sebelum simpul terakhir
      A -> Last -> next = NULL; // mengatur penunjuk next simpul terakhir menjadi NULL
      free(Throw); // menghapus simpul terakhir
      return q; // mengembalikan nilai operand yang di-dequeue
    } else {
      Throw = Last; // menyimpan penunjuk pada simpul terakhir
      q = Last -> operand; // menyimpan nilai operand pada simpul terakhir
      A -> Last = NULL; // mengatur penunjuk simpul terakhir menjadi NULL
      A -> First = NULL; // mengatur penunjuk simpul pertama menjadi NULL
      free(Throw); // menghapus simpul terakhir
      return q; // mengembalikan nilai operand yang di-dequeue
    }
  }
}

double simbol_operasi_trigonometri(double sudut, char operator[]) {
  if (strcmp(operator, "sin(") == 0) {
    return operasiSinus(sudut);
  } else if (strcmp(operator, "cos(") == 0) {
    return operasiCosinus(sudut);
  } else if (strcmp(operator, "tan(") == 0) {
    return operasiTangen(sudut);
  } else if (strcmp(operator, "asin(") == 0) {
    return operasiAsin(sudut);
  } else if (strcmp(operator, "acos(") == 0) {
    return operasiAcos(sudut);
  } else if (strcmp(operator, "atan(") == 0) {
    return operasiAtan(sudut);
  } else if (strcmp(operator, "csc(") == 0) {
    return operasiCosecan(sudut);
  } else if (strcmp(operator, "sec(") == 0) {
    return operasiSecan(sudut);
  } else if (strcmp(operator, "cot(") == 0) {
    return operasiCotangen(sudut);
  } else {
    exit(1);
  }
}

#endif
