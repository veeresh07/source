#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[]="aabbccdd";

	int i=0,j=0,k=0;
	int index=0;
	int len = strlen(str);

	printf("line: %d, after: %s\n",__LINE__,str);

	for(i = 0; i < strlen(str); i++)
	{
		for(j = i + 1; str[j] != '\0'; j++)
		{
			if(str[j] == str[i])  
			{
				for(k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
			}
		}
	}
	printf("line: %d, after: %s\n",__LINE__,str);

	return 0;
}
