#ifndef tree_h
#define tree_h
#include <ctype.h>
#define Data(P) (P)->data
#define Rson(P) (P)->Rson
#define Lson(P) (P)->Lson
#define Nil NULL

typedef char infotype;
typedef struct Elemen *address;
typedef struct Elemen{
	address Lson;
	infotype data;
	float operand;
	int isOperator;
	address Rson;
}Tree;

typedef struct Node *node;
typedef struct Node{
	infotype oprtr;
	float operand;
	int isoperator;
	node next;
}ElmtList;

typedef struct{
	node Head;
}Stack;

typedef struct {
	node First;
	node Last;
}Queue;

int derajatOperator(infotype oper);
int isOperator(infotype oper);
void PostOrder(address P);
void EnqueOperand(Queue *First,float item,node *P);
void convertPostfix(Queue *Z,Stack *X,char *input);
void PushStack(Stack *First,char item,node *P);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(float input);
address CreateNodeOperator(char input);
double kalkulasi(address P);
double DequeOperand(Queue *A);

#endif
