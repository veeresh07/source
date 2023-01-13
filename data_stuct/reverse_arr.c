#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
int * reverse_array(int arr[],int size)
{
	printf("reverse with using second array: uses second array to reverse\n");
	//static int temp_rev_array[10];
	int *temp_rev_array;
	temp_rev_array = (int *)malloc(size * (sizeof(int)));

	int arr_index=0,rev_index;

#if DEBUG
	printf("%d, size of arr: %d\n",__LINE__,size);
	for(arr_index=0; arr_index<size; arr_index++)
	{
		printf("%d\n",arr[arr_index] );
	}
	printf("reversing started\n");
#endif
	arr_index=size-1;//init array index to size of array
	rev_index=0;// init reverse index to zero
	while(arr_index>=0)
	{
		temp_rev_array[rev_index]=arr[arr_index];
		rev_index++;//increment reverse index
		arr_index--;//decrement reverse index
	}
#if DEBUG
	printf("reversing finihed\n");
	for(arr_index=0; arr_index<size; arr_index++)
	{
		printf("%d\n",temp_rev_array[arr_index] );
	}
#endif
	return temp_rev_array;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int size_of_arr=0;
	int *rev_arr_ptr;
	int arr_index=0;
	int rev_index=0;

	size_of_arr= sizeof(arr)/sizeof(arr[0]);

	printf("%d, size of arr: %d\n",__LINE__,size_of_arr);
	rev_arr_ptr = reverse_array(arr,size_of_arr);
	printf("printing reversed array\n");
	arr_index=0;
	for(arr_index=0; arr_index<size_of_arr; arr_index++)
	{
		//printf( "*(rev_arr_ptr + %d) : %d\n", arr_index, *(rev_arr_ptr + arr_index));
		printf("%d\n",*(rev_arr_ptr+arr_index));
	}

	/* reverse without using second array: uses same array to reverse */
	printf("reverse without using second array: uses same array to reverse\n");
	arr_index = size_of_arr-1;//arr_index that moves from size - 1 to 0
	rev_index=0;//rev_index that moves from 0 to size - 1
	int temp;
	/* While swapping array elements do ensure that rev_index must not cross arr_index */
	while(arr_index > rev_index)
	{
		temp = arr[rev_index];
		arr[rev_index] = arr[arr_index];
		arr[arr_index]=temp;
		arr_index--;
		rev_index++;
	}

	printf("printing reversed array\n");
	arr_index=0;
	for(arr_index=0; arr_index<size_of_arr; arr_index++)
	{
		//printf( "*(rev_arr_ptr + %d) : %d\n", arr_index, *(rev_arr_ptr + arr_index));
		printf("%d\n",arr[arr_index]);
	}
	return 0;
}
