#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "danendra.h"
#include "Aqila.h"
#include "faras.h"
#include "linda.h"

double perform_operation(double num1, double num2, char operator) {
    switch (operator) {
        case 's':
        case 'c':
		case 't':
      		return trigonometri(num1, operator);
		case '^':
            return pow(num1, num2);
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        default:
            printf("Invalid operator: %c", operator);
            exit(1);
    }
}

int get_priority(char operator) {
    switch (operator) {
    	case 's':
        case 'c':
		case 't':
      		return 4;
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            printf("Invalid operator: %c", operator);
            exit(1);
    }
}

int Operasi_hitung() {
    char expression[100];
    printf("Enter expression: ");
    scanf("%s", expression);

    double stack_num[100];
    int stack_num_top = -1;
    char stack_op[100];
    int stack_op_top = -1;
    int i;
    for (i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
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
