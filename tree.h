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
	infotype data;
	float operand;
	address Rson;
	address Lson;
	int isOperator;
}Tree;

typedef struct Node *node;
typedef struct Node{
	node next;
	infotype oprtr;
	float operand;
	int isoperator;
}ElmtList;

typedef struct{
node Head;
}Stack;

typedef struct {
node First;
node Last;
}Queue;


<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> e584fc6b30d1a8ca0958659c6738002b5c918d3b
void InfixToPostfix(infotype* input, infotype postfix[]);
int derajatOperator(infotype oper);
int isOperator(infotype oper);
address CreateNode(infotype data);
address BuildTree(infotype postfix[]);
void PostOrder(address P);
void ViewAsc(Queue First);
void EnqueOperand(Queue *First,float item,node *P);
void convertPostfix(Queue *Z,Stack *X,char *input);
void ViewAscStack(Stack First);
void PushStack(Stack *First,char item,node *P);
char PopStack(Stack *First);
address Create_Tree(Queue Z);
address CreateNodeOperand(float input);
address CreateNodeOperator(char input);
double kalkulasi(address P);
<<<<<<< HEAD

=======
float DequeOperand(Queue *A);
=======
>>>>>>> c32adeca7a6f8ae709672a37f03c9eebbae5aa32
>>>>>>> e584fc6b30d1a8ca0958659c6738002b5c918d3b


#endif


<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> c32adeca7a6f8ae709672a37f03c9eebbae5aa32
>>>>>>> e584fc6b30d1a8ca0958659c6738002b5c918d3b
