#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 	100
#define ELEMENT_SIZE 10

#define STACK_FULL 	-2
#define STACK_EMPTY 	-1
#define NORMAL 		0

int myerror = NORMAL;

void push(double[], 	// input/ouput - the stack
	  double,   	         // input - data being pushed onto the stack
	  int *,   	          // input/output - pointer to the top of stack
	  int);    	     // constant - maximum size of stack

double		   	// output - data being popped out from the stack
     pop(double[],  	// input/output - the stack
	 int *);   	// input/output - pointer to top of stack
	 
void push(double stack[],
	double item,
	int *top,
	int max_size){

	if(*top < max_size-1){
		++(*top);
		stack[*top] = item;
		myerror = NORMAL;
	}
	else
		myerror = STACK_FULL;
}

double pop(double stack[], int *top){

	double item;
	if (*top >= 0){
		item = stack[*top];
		--(*top);
		myerror = NORMAL; 
	}
	else{
			item = STACK_EMPTY; // not used when myerror is not NORMAL
		myerror = STACK_EMPTY;
	}

	return item;
}

int main(){
   	double s[STACK_SIZE];
   	int s_top = STACK_EMPTY;
	int size = STACK_SIZE;
	double input;
	char  operator;
	double op1, op2, final;
	int temp = 3;
	//int x = 0;
	do{
			printf("Press 1 for operand input or 2 for operator input. ");
		temp = getchar();
		if(temp == '1'){
			printf("Enter a number. ");
			scanf(" %lg",&input);
			push(s,input,&s_top,size);
		}//end if
		else if(temp == '2'){
			printf("Enter an operand. Sin = s, log = l");
			scanf(" %c",&operator);
			printf("%c",operator);
			if(operator == 's'){
				op1 = pop(s,&s_top);
				final = sin(op1);
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == 'l'){
				op1 = pop(s,&s_top);
				final = log(op1);
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == '+'){
				op2 = pop(s, &s_top);
				op1 = pop(s, &s_top);
				if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = op1+op2;
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == '-'){
				op2 = pop(s, &s_top);
				op1 = pop(s, &s_top);
				if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = op1-op2;
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == '/'){
				op2 = pop(s, &s_top);
				op1 = pop(s, &s_top);
				if(op2 == 0){
					printf("Division by 0 detected! ");
					break;
				}//end if
				if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = op1/op2;
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == '*'){
				op2 = pop(s, &s_top);
				op1 = pop(s, &s_top);
					if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = op1*op2;
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == '^'){
				op2 = pop(s, &s_top);
				op1 = pop(s, &s_top);
					if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = pow(op1,op2);
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == 'c'){
				op1 = pop(s, &s_top);
					if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = cos(op1);
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else if(operator == 't'){
				op1 = pop(s, &s_top);
					if(myerror == STACK_EMPTY){
					printf("Insufficient opperands! ");
					break;
				}//end if
				final = tan(op1);
				push(s,final,&s_top,size);
				printf("Stack holds : %lg\n", final);
			}else{ 
				printf("Unrecognized operator! ");
			}//end else
		}//end elseif
		//x++;unused
	}while(temp != EOF);
	return 0;
}