#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
	printf("Value of a is %d\n", a); 
} 


void add(int a, int b)
{
	printf("%d\n",(a+b));
}

void sub(int a, int b)
{
	printf("%d\n",(a-b));
}

void multi(int a, int b)
{
	printf("%d\n",(a*b));
}

int main() 
{ 
	// fun_ptr is a pointer to function fun() 
	void (*fun_ptr)(int) = &fun; 

	/* The above line is equivalent of following two 
	void (*fun_ptr)(int); 
	fun_ptr = &fun; 
	*/

	// Invoking fun() using fun_ptr 
	(*fun_ptr)(10); 

	////////////below code is for array of fun pointer///////////////
	int option;

	void (*func_ptr[3])(int a, int b) = {add, sub, multi};
    printf("\nEnter function number you want");
    printf("\n0 for ADD\n1 for SUBSTRACT\n2 for MULTIPLY\n");
    scanf("%d",&option);

    if((option>=0)&&(option<=2))
    { 
        (*func_ptr[option])(7,4);
    }
	return 0; 
}