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

int derajatOperator(infotype oper){
	if(oper=='+' || oper=='-'){
		return 1;
	} else if(oper=='*' || oper=='/'){
		return 2;
	} else if(oper=='^' || oper=='v'){
		return 3;
	}  else if(oper=='(' || oper==')'){
		return 0;
	}else{
		printf("Error, Operator Tidak Diketahui: %c", oper);
        exit(1);
	}
}

int isOperator(infotype oper){
	if(oper=='+' || oper=='-' || oper=='*' || oper=='/' || oper=='^' || oper=='v'){
		return 1;
	} 
	return 0;
}

address CreateNode(infotype data){
	address P;
	
	P = (address) malloc (sizeof (Tree));
	Data(P)=data;
	Rson(P)=Nil;
	Lson(P)=Nil;
	
	return P;
}

address BuildTree(infotype postfix[]){
	address P;
	address stack[50];
	int i, len, top=-1;
	infotype c;
	
	len=strlen(postfix);
	
	for(i=0;i<len;i++){
		c=postfix[i];
		if(isdigit(c)){
			P=CreateNode(c);
		} else{
			P=CreateNode(c);
			Rson(P)=stack[top--];
			Lson(P)=stack[top--];
		}
		stack[++top]=P;
	}
	return(stack[0]);
}

void PostOrder(address P){
	
	if(P!=Nil){
		PostOrder(Lson(P));
		PostOrder(Rson(P));
		if(P->isOperator==1){
			printf("%c ", P->data);
		}else{
			printf("%g ",P->operand);
		}
	}
}

void PushStack(Stack *First,char item,node *P){
	*P = (node) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{

		(*P)->oprtr=item;
		(*P)->isoperator=1;
		(*P)->next=NULL;
		if(First->Head==NULL){
			(*First).Head=*P;
			(*First).Head->next=NULL;	
		}else{
			(*P)->next=First->Head;
			First->Head=*P;
		}
	
	
}
}

char PopStack(Stack *First){
	node P;
	P=First->Head;
	First->Head=P->next;
	return P->oprtr;
	free(P);
}


void ViewAsc(Queue First){
	node P;
	P=First.First;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->isoperator==1){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
		P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

void ViewAscStack(Stack First){
	node P;
	P=First.Head;
	if(P!=NULL){
		
		while(P!=NULL){
			if(P->isoperator==1){
				printf("%c ",P->oprtr);
			}else{
				printf("%g ",P->operand);
			}
			P=P->next;
		}
	}
	else if(P==NULL){
		printf("list kosong");
	}
}

void EnqueOperator(Queue *First,char item,node *P){
	*P = (address) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->oprtr=item;
		(*P)->next=NULL;
		(*P)->isoperator=1;
		if(First->First==NULL){
			(*First).First=*P;
			(*First).Last=*P;
			(*First).Last->next=NULL;	
		}else{
			(*P)->next=NULL;
			First->Last->next=*P;
			First->Last=*P;
		}
	
}
}

void EnqueOperand(Queue *First,float item,node *P){
	*P = (address) malloc (sizeof (ElmtList));
	if(P==NULL){
		printf("Gagal Alokasi");
	}else{
		(*P)->operand=item;
		(*P)->next=NULL;
		(*P)->isoperator=0;
		if(First->First==NULL){
			(*First).First=*P;
			(*First).Last=*P;
			(*First).Last->next=NULL;	
		}else{
			(*P)->next=NULL;
			First->Last->next=*P;
			First->Last=*P;
		}
	
}
}
//float kalkulasi()
void convertPostfix(Queue *Z,Stack *X,char *input){
	node P;
	char token,c;
	int i,temp;
//	float num=0,num2;
	float angka;
	for(i=0;i<strlen(input);i++){
		token=input[i];
		if(isdigit(token)){
			char num[strlen(input)];
			int j=0;
			while(isdigit(input[i]) || input[i]=='.'){
				num[j++]=input[i];
				i++;
			}
			num[j]='\0';
			angka=strtof(num, NULL);
			EnqueOperand(&*Z,angka,&P);
			i--;
		}else if(isOperator(token)&&X->Head!=NULL&&X->Head->oprtr!='('){
			c=X->Head->oprtr;
			while(derajatOperator(token)<=derajatOperator(c)&&X->Head!=NULL){
				EnqueOperator(&*Z,PopStack(&*X),&P);
			}
			PushStack(&*X,token,&P);
			}else if(token == 'l'){
			char log[10];
			char Num[100];
			float angka;
			float a,hasil;
			int j = 0,x = 0;
			if(isdigit(input[i-1])){
				a=DequeOperand(&*Z);
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						Num[j++]=input[i];
					} else{
						log[x++]=input[i];
					}
					i++;
				}
				Num[j]='\0';
				angka=strtof(Num, NULL);
				hasil=logaritma(a,angka,log);
				EnqueOperand(&*Z, hasil,&P);	
			}else{
				while(input[i]!=')'){
					if(isdigit(input[i]) || input[i]=='.'){
						Num[j++]=input[i];
					} else{
						log[x++]=input[i];
					}
					i++;
				}
				Num[j]='\0';
				angka=strtof(Num, NULL);
				hasil=logaritma(10,angka,log);
				EnqueOperand(&*Z, hasil,&P);	
			}
		}else if(token==')'){
			c=X->Head->oprtr;
			while(c!='('){
				EnqueOperator(&*Z,PopStack(&*X),&P);
				c=X->Head->oprtr;
			}
			PopStack(&*X);
		}else{
			PushStack(&*X,token,&P);
		}
	}
	while(X->Head!=NULL){
		c=PopStack(&*X);
		EnqueOperator(&*Z,c,&P);
	}
	
	
}

address Create_Tree(Queue Z){
	
	address P;
	address stack[50];
	node Q;
	int i, len, top=-1;
	infotype c;
	float d;
	
	Q=Z.First;
	
	while(Q!=NULL){
		if(Q->isoperator==1){
			c=Q->oprtr;
			P=CreateNodeOperator(c);
			Rson(P)=stack[top--];
			Lson(P)=stack[top--];
		}else{
			d=Q->operand;
			P=CreateNodeOperand(d);
		}
		stack[++top]=P;
		Q=Q->next;
	}
	return(stack[0]);
}

address CreateNodeOperand(float input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->operand=input;
	P->isOperator=0;
	P->Lson=NULL;
	P->Rson=NULL;
	return P;
	
}

address CreateNodeOperator(char input){
	address P;
	P = (address) malloc (sizeof (Tree));
	P->data=input;
	P->isOperator=1;
	P->Lson=NULL;
	P->Rson=NULL;
	return P;
	
}

double kalkulasi(address P){
	if(P->isOperator==1){
		double Lson= kalkulasi(P->Lson),Rson= kalkulasi(P->Rson);
		if(P->data=='+'){
			return kalkulasi(P->Lson) + kalkulasi(P->Rson);
		}else if(P->data=='-'){
			return kalkulasi(P->Lson) - kalkulasi(P->Rson);
		}else if(P->data=='-'){
			return kalkulasi(P->Lson) - kalkulasi(P->Rson);
		}else if(P->data=='/'){
			return kalkulasi(P->Lson) / kalkulasi(P->Rson);
		}else if(P->data=='*'){
			return kalkulasi(P->Lson) * kalkulasi(P->Rson);
		}else if(P->data=='^'){
			return pow(kalkulasi(P->Lson) , kalkulasi(P->Rson));
		}
	}
	
	return P->operand;
}

float DequeOperand(Queue *A){
	float q;
	node First,Last,Throw;
	First=A->First;
	Last=A->Last;
	if(First==NULL){
		printf("Queue Empty");
	}else{
		if(First!=Last){
			while(First->next!=Last){
				First=First->next;
			}
			Throw=Last;
			q=Last->operand;
			A->Last=First;
			A->Last->next=NULL;
			free(Throw);
			return q;
		}else{
			Throw=Last;
			q=Last->operand;
			A->Last=NULL;
			A->First=NULL;
			free(Throw);
			return q;
		}
		
	}
}

double simbol_operasi_trigonometri(double sudut, char operator[]){
	if(strcmp(operator,"sin(")==0){
		return operasiSinus(sudut);
	}
	else if(strcmp(operator,"cos(")==0){
		return operasiCosinus(sudut);
	}else if(strcmp(operator,"tan(")==0){
		return operasiTangen(sudut);
	}else if(strcmp(operator,"asin(")==0){
		return operasiAsin(sudut);
	}else if(strcmp(operator,"acos(")==0){
		return operasiAcos(sudut);
	}else if(strcmp(operator,"atan(")==0){
		return operasiAtan(sudut);
	}else if(strcmp(operator,"csc(")==0){
		return operasiCosecan(sudut);
	}else if(strcmp(operator,"sec(")==0){
		return operasiSecan(sudut);
	}else if(strcmp(operator,"cot(")==0){
		return operasiCotangen(sudut);
	}
	else{
		if(strcmp(operator,"SIN")==0||strcmp(operator,"SIN(")==0||strcmp(operator,"sin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sin(...), contoh sin(60)", operator);
		}else if(strcmp(operator,"COS")==0||strcmp(operator,"COS(")==0||strcmp(operator,"cos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya cos(...), contoh cos(45)", operator);
		}else if(strcmp(operator,"TAN")==0||strcmp(operator,"TAN(")==0||strcmp(operator,"tan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya tan(...), contoh tan(30)", operator);
		}else if(strcmp(operator,"ASIN")==0||strcmp(operator,"ASIN(")==0||strcmp(operator,"asin")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya asin(...), contoh asin(0.5)", operator);
		}else if(strcmp(operator,"ACOS")==0||strcmp(operator,"ACOS(")==0||strcmp(operator,"acos")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya acos(...), contoh acos(0.5)", operator);
		}else if(strcmp(operator,"ATAN")==0||strcmp(operator,"ATAN(")==0||strcmp(operator,"atan")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya atan(...), contoh atan(0.5)", operator);
		}else if(strcmp(operator,"CSC")==0||strcmp(operator,"CSC(")==0||strcmp(operator,"csc")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya csc(...), contoh csc(40)", operator);
		}else if(strcmp(operator,"SEC")==0||strcmp(operator,"SEC(")==0||strcmp(operator,"sec")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya sec(...), contoh sec(0.5)", operator);
		}else if(strcmp(operator,"COT")==0||strcmp(operator,"COT(")==0||strcmp(operator,"cot")==0){
			printf("Error, operator yang anda masukkan: %s, seharusnya COT(...), contoh cot(0.5)", operator);
		}else{
			printf("Operator Tidak Diketahui sin: %s", operator);
		}
        exit(1);
	}
}

#endif
