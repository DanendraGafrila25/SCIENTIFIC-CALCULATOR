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




#endif


