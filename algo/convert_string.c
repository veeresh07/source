/*
 * There is a string with alphanumeric, you need to write a function which converts every even postioned char to Caps.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* MAX len of string */
#define MAX_STR_LEN 50

/* 
 * input Alphanumeric string & len of the string.
 * conevrt every even postioned char to Caps.
 */
void convert_even_chat_to_uppercase(char *string, uint8_t str_len)
{
	uint8_t index=0;
	/* traverse till end of string  */
	for(index = 0; index < str_len; index++)
	{
		/* check is char is even char */
		if((index%2)==0)
		{
			/* check if the char is in lower case */
			if((string[index] >= 'a') && (string[index] <='z'))
			{
				/* Substract 32 from char value, Difference between 'a' & 'A' is 32 */
				string[index] = string[index] - 32;
			}
		}
	}
}

int main()
{
	char string[MAX_STR_LEN];
	
	printf("Please enter the string:\n");

	/* reads char of MAX_STR_LEN -1 */
	fgets(string,MAX_STR_LEN,stdin);

	/* get string len */
	uint8_t len_of_string = strlen(string);

	/* coneverts the even char to caps */
	convert_even_chat_to_uppercase(string,len_of_string);
	printf("\nConsider first char is stored in 0th location in string array.\nHence 0th location is considered as even.\n");
	printf("str: %s",string);
	
	return 0;
}