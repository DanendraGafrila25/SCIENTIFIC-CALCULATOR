#ifndef danendra_h
#define danendra_h

#include "Aqila.h"
#include "faras.h"
#include "linda.h"
#include "rizki.h"
#include "tree.h"

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

/*void Operasi_hitung(){
	double result = 0;
	for(;;){
    	char ekspresi[100];
		double num2, num1, operand_stack[100];
		operand_stack[0] = 0;
	    int operand_top = -1;
	    char operator_stack[100], operator;
	    int operator_top = -1;
	    int i;
    	system("cls");
	    printf("= %g\n",result );
    	printf("\nekspresi : ");
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
	        
            }else if(ekspresi[i]=='!'){
				int j = i - 1;
				int k;
				char number[100];
				double bil;
				int result;
				int index = 0;
			    while (j >= 0 && isdigit(ekspresi[j])) {
			        j--;
			    }
			    for (k = j + 1; k < i; k++) {
			    	number[index] = ekspresi[k];
			        index++;
			    }
			
			    operand_stack[++operand_top] = atof(number);
				bil = operand_stack[operand_top];
				result = faktorial(bil);
				operand_stack[--operand_top]=(double)result;
				
			}else if (ekspresi[i] == 's' || ekspresi[i] == 'c' || ekspresi[i] == 't'){
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
				number[number_top] = '\0';
				operand_stack[++operand_top] = atof(number);
				bil = operand_stack[operand_top];
				operand_stack[operand_top]=simbol_operasi_trigonometri(bil, trigono);
			}else if (ekspresi[i] == 'l'){
	        	char log[4];
	        	int j=0;
	        	char temp[1], temp2[1];
	        	char number[100];
	        	int number_top = 0;
	        	temp[0] = ekspresi[i-1];
	        	while(ekspresi[i] != ')' && (ekspresi[i] != '+' || ekspresi[i] != '-' || ekspresi[i] != '*' || ekspresi[i] != '/') && ekspresi[i] != ' '){
	        		if(isdigit(ekspresi[i]) || ekspresi[i] == '.'){
	        			number[number_top++] = ekspresi[i++];
					}else {
				        log[j++] = ekspresi[i++];
				        log[4] = '\0';
				    }
				}
				if(strcmp(log, "log(")){
					printf("invalid expression");
				}else{
					if(j!=4){
					printf("Invalid expression ");
					}else{
						operand_stack[++operand_top] = atof(number);
						num2 = operand_stack[operand_top--];
						if(num2 <= 0) {
				            printf("Invalid expression");
				        }
						else if(!isdigit(temp[0]) && !(temp[0] == 'e')){
							operand_stack[++operand_top]=logaritma(num2, 10);
						}else if(temp[0] == 'e'){
							operand_stack[++operand_top]=logaritma(num2, M_E);
						}
						else{
							num1 = operand_stack[operand_top--];
							operand_stack[++operand_top]=logaritma(num2, num1);
						}
					}	
				}
			}else {
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

		result = result + operand_stack[0];
		printf("= %g\n",operand_stack[0] );
		system("pause");
		system("cls");
	}
}*/

#endif
