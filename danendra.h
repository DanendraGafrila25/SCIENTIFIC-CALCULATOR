#ifndef danendra_h
#define danendra_h

#include "Aqila.h"
#include "faras.h"
#include "linda.h"

int prioritas(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^' || operator == 'L' || operator == '!' || operator == 'V' || operator == 'C' || operator == 'P')
        return 3;
    else if (operator == '(' || operator == ')')
        return 0; 
    else
        return -1;
        exit(1);
}

double operasi_trigonometri(double sudut, char op[]) {
	sudut = (sudut * M_PI)/180;
    if (strcmp(op, "sec(") == 0) {
		return 1.0 / cos(sudut);
    } else if (strcmp(op, "csc(") == 0) {
		return 1.0 / sin(sudut);
    } else if (strcmp(op, "cot(") == 0) {
		return 1.0 / tan(sudut);
    } else if (strcmp(op, "sin(") == 0) {
    	return sin(sudut);
    } else if (strcmp(op, "cos(") == 0) {
        return cos(sudut);
    } else if (strcmp(op, "tan(") == 0) {
        return tan(sudut);
    } else {
        return 0;
    }
}

double simbol_operasi(double num1, double num2, char operator) {
    switch (operator) {
    	case 'C' :
    		return combination((int)num1,(int)num2);  
    	case 'P' :
    		return permutation((int)num1, (int)num2);
    	case 'V' :
    		return akar(num1,num2);
    	case 'L' :
    		return logaritma(num1);
    	case '!' :
    		return faktorial((int)num1);
        case '^':
            return eksponen(num1, num2);
        case '*':
            return perkalian(num1,num2);
        case '/':
            return pembagian(num1,num2);
        case '+':
            return penjumlahan(num1, num2);
        case '-':
            return pengurangan(num1, num2);
        default:
            printf("Invalid operator: %c", operator);
            return 0;
    }
}

void Operasi_hitung(){
	double hasil = 0;
	
	for(;;){
		printf("%g\n", hasil);
    	char ekspresi[100];
		double num2, num1, operand_stack[100];
	    int operand_top = -1;
	    char operator_stack[100], operator;
	    int operator_top = -1;
	    int i;
    	printf("ekspresi : ");
	    scanf("%s", ekspresi);
	    for (i = 0; ekspresi[i]; i++) {
	        if (isdigit(ekspresi[i])) {
	            char number[100];
	            int number_top = 0;
	            while (isdigit(ekspresi[i]) || ekspresi[i] == '.') {
					number[number_top++] = ekspresi[i++];
	            }
	            number[number_top] = '\0';
	            operand_stack[++operand_top] = atof(number);
	            i--;
	        } else if (ekspresi[i] == '(') {
	            operator_stack[++operator_top] = ekspresi[i];
	        } else if (ekspresi[i] == ')') {
	            while (operator_stack[operator_top] != '(') {
	                num2 = operand_stack[operand_top--];
	                num1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = simbol_operasi(num1, num2, operator);
	            }
	            operator_top--;
	        } else if (ekspresi[i] == '[') {
                i++;
                char number[100];
                int number_top = 0;
                while (ekspresi[i] != ']') {
                    number[number_top++] = ekspresi[i++];
                }
                number[number_top] = '\0';
                operand_stack[++operand_top] = atof(number);
                operand_stack[operand_top] = operand_stack[operand_top];
            } else if (ekspresi[i] == 's' || ekspresi[i] == 'c' || ekspresi[i] == 't'){
            	char trigono[6];
            	int j=0;
            	char number[100];
            	int bil;
            	int number_top = 0;
            	while(ekspresi[i]!=')'){
            		if(isdigit(ekspresi[i]) || ekspresi[i] == '.'){
            			number[number_top++] = ekspresi[i++];
					}else {
				        // menyimpan operator trigonometri
				        trigono[j++] = ekspresi[i++];
				        trigono[6] = '\0';
				    }
				}
				operand_stack[++operand_top] = atof(number);
				bil = operand_stack[operand_top];
				operand_stack[operand_top]=operasi_trigonometri(bil, trigono);
			}  else {
	            while (operator_top >= 0 && prioritas(operator_stack[operator_top]) >= prioritas(ekspresi[i])) {
	                num2 = operand_stack[operand_top--];
	                num1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = simbol_operasi(num1, num2, operator);
	            }
	            operator_stack[++operator_top] = ekspresi[i];
			}
		}
		while (operator_top >= 0) {
		    num2 = operand_stack[operand_top--];
		    num1 = operand_stack[operand_top--];
		    operator = operator_stack[operator_top--];
		    operand_stack[++operand_top] = simbol_operasi(num1, num2, operator);
		}
		hasil += operand_stack[0];
		printf("Result: %g\n", operand_stack[0]);
		system("pause");
		system("cls");
	}
}

#endif
