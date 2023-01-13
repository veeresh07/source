#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_sentence(char *sentence)
{
	int i=0, len = 0;
	printf("%s, line: %d, %s\n",__FUNCTION__,__LINE__,sentence);
	i=0;
	while(*(sentence+i)!='\0') i++;
	len = i;
	printf("%s, line: %d, sentence len: %d\n",__FUNCTION__,__LINE__,len);
	// point start and end to last char of the sentence
	int word_start=len-1;
	int word_end=len-1;

	char reverse[len];
	int index=0;
	/* "ABCD EDFG IJKL MNOP QRST UVWX YZ" */
	/* move till first char */
	while(word_start > 0)
	{
		/* check for word separator (blank space) */
		if(sentence[word_start]==' ')
		{
			/* posistion i to space + 1 to point to first char of the word */
			i=word_start+1;
			/* move till end of the word */
			while(word_end >= i)
			{
				/* copy char by char */
				reverse[index]=sentence[i];
				index++;
				i++;
			}
			/* enter new space btween reversed sentence */
			reverse[index]=' ';
			index++;
			word_end=word_start - 1;
		}
		/* while(word_start>0): move to previous word */
		word_start--;
	}
	/*  lastly add the last word */
	for(i=0;i<=word_end;i++)
	{
		reverse[index]=sentence[i];
		index++;
	}
	printf("%s, line: %d, reversed sentence: %s\n",__FUNCTION__,__LINE__,reverse);
}

int main()
{
	char str1[]="abc";
	char str2[3]="abc";
	char str3[]={'a','b','c','\0'};
	char str4[4]={'a','b','c','\0'};

	//char name[10];
	//name="Veeresh"; /* wrong, cant do this, this can be done using char *str_ptr */
	char name[10]="veeresh";
	//scanf("%s",name);
	printf("line: %d, %s\n",__LINE__,name);

	strcpy(name,"Veeresh");
	printf("line: %d, %s\n",__LINE__,name);

	strcpy(name,str1);
	printf("line: %d, %s\n",__LINE__,name);

	char *name1="VeereshMathapati";
	printf("line: %d, %s\n",__LINE__,name1);

	name1="veeresh_mathapati";
	printf("line: %d, %s\n",__LINE__,name1);

	char *str_ptr1="string1";
	printf("line: %d, %s\n",__LINE__,str_ptr1);
	char *str_ptr2;
	str_ptr2="string2";
	printf("line: %d, %s\n",__LINE__,str_ptr2);


	char full_name[] = "ABCD EFGh IJKL MNOP QRST UVWX YZ";

	reverse_sentence(full_name);
	printf("%s, line: %d, %s\n",__FUNCTION__,__LINE__,full_name);

	return 0;
}
