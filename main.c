#include <stdio.h>
#include <math.h>
#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include "operasi_hitung.h"

int main(){
	int tipe_suhu;
	double celsius;
	int pilihMenu;
	printf("Pilih menu di bawah ini\n");
	printf("1. Operasi hitung\n");
	printf("2. Konversi suhu\n");
	printf("3. Matriks\n");
	printf("4. Statistika\n");
	printf("Input : ");
	scanf("%d", &pilihMenu);
	switch (pilihMenu){
		case 1:
			system("cls");
			int Operasi_hitung() {
    char expression[100];
	printf("Enter expression: ");
	scanf("%[^\n]", expression);

	double num;
    double stack_num[100];
    int stack_num_top = -1;
    char stack_op[100];
    int stack_op_top = -1;
    int is_negative = 0;
    int i;
    for (i = 0; expression[i]; i++) {
    	if (expression[i] == ' ') {
        continue;
    }else if (isdigit(expression[i]) || (expression[i] == '-' && isdigit(expression[i+1]))) {
        if (expression[i] == '-') {
            i++;
            is_negative = 1;
        } else {
            is_negative = 0;
        }
        char number[100];
        int number_top = 0;
        while (isdigit(expression[i]) || expression[i] == '.') {
            number[number_top++] = expression[i++];
        }
        number[number_top] = '\0';
        num = strtod(number, NULL);
        if (is_negative) {
            num = -num;
        }
        stack_num[++stack_num_top] = num;
        i--;
	}else if (isdigit(expression[i])) {	
        char number[100];
        int number_top = 0;
        while (isdigit(expression[i]) || expression[i] == '.') {
            number[number_top++] = expression[i++];
        }
        number[number_top] = '\0';
        stack_num[++stack_num_top] = strtod(number, NULL);
        i--;
    } else if (expression[i] == '(') {
        stack_op[++stack_op_top] = expression[i];
    } else if (expression[i] == ')') {
        while (stack_op[stack_op_top] != '(') {
            double num2 = stack_num[stack_num_top--];
            double num1 = stack_num[stack_num_top--];
            char operator = stack_op[stack_op_top--];
            stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
        }
        stack_op_top--;
    } else {
        while (stack_op_top >= 0 && get_priority(stack_op[stack_op_top]) >= get_priority(expression[i])) {
            double num2 = stack_num[stack_num_top--];
            double num1 = stack_num[stack_num_top--];
            char operator = stack_op[stack_op_top--];
            stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
        }
		stack_op[++stack_op_top] = expression[i];
		}
	}
while (stack_op_top >= 0) {
    double num2 = stack_num[stack_num_top--];
    double num1 = stack_num[stack_num_top--];
    char operator = stack_op[stack_op_top--];
    stack_num[++stack_num_top] = perform_operation(num1, num2, operator);
}

printf("Result: %g\n", stack_num[0]);
return 0;
}

			break;
		case 2:
			system("cls");
			menu_suhu (tipe_suhu, celsius);
			break;
		case 3:
			system("cls");
			menu_matriks();
			break;
       case 4:
         system("cls");
		 statistika();
         break;
		default:
			system("cls");
			main();
	}
	
	return 0;
}
