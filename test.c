#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 	10

#define STACK_FULL 	-2
#define STACK_EMPTY 	-1
#define NORMAL 		0

int myerror = NORMAL;

void push(double [], 	// input/ouput - the stack
	  double,   	// input - data being pushed onto the stack
	  int *,   	// input/output - pointer to the top of stack
	  int);    	// constant - maximum size of stack

double		   	// output - data being popped out from the stack
     pop(double [],  	// input/output - the stack
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

double pop(double stack[],
	int *top){

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

        srand(time(NULL));

        // (Using a loop) Keep pushing doubles equivalent to chars randomly picked between '!'(33) and '~'(126) to the stack
        // until it is full.
        // Print each double before each pushing.

        double temp = (double)33; //'!'
        do{
                double c = (double)(temp+rand()%94);
                printf("Push: %lf\n", c);
                push(s, c, &s_top, STACK_SIZE);
        } while(myerror != STACK_FULL);

        printf("--------------Last item didn't get pushed into the stack because it was full.-----------\n");

        // (Using a loop) Keep popping out doubles from the stack until it is empty
        // Print each double after each popping.
        double t;
        do{
                t=pop(s, &s_top);
                if(myerror!=STACK_EMPTY)
                        printf("Pop: %lf\n", t);
        }while(myerror!=STACK_EMPTY);

        return 0;
}
