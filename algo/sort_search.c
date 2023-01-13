#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a, int *b)
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr,int arr_size)
{
    int pass=0;
    int index = arr_size-1;
    for(pass = 0; pass < arr_size-1; pass++)
    {
        for (index = arr_size-1; index > pass; index--)
        {
            if(arr[index]<arr[index-1])
                swap(&arr[index],&arr[index-1]);
        }
    }
}

int binary_search(int *arr, int left, int right, int key)
{
    printf("binary_search:\nleft: %d, right: %d, key: %d\ninput array:\n",left,right,key);

    for(int i =0;i<= right;i++)
        printf("%d ",arr[i]);
        
    printf("\n");
    
    int location;
    int middle;
    while(left<=right)
    {
        middle = left + (right-left)/2;
        if(arr[middle]==key)
        {
            return middle;
        }
        else if(key > arr[middle])
        {
            left = middle+1;
        }
        else if(key < arr[middle])
        {
            right = middle-1;
        }
        else
        location = -1;
    }
    return location; 
}

int main()
{
    int arr[]={12,6,3,4,2,9,1};
    
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("un-sorted input array:\n");
    for(int i =0;i< arr_size;i++)
        printf("%d ",arr[i]);
        
    printf("\n");

    printf("size of arr: %d\n",arr_size);
    bubble_sort(arr,arr_size);
    
    printf("sorted array:\n");
    for(int i =0;i< arr_size;i++)
        printf("%d ",arr[i]);
        
    printf("\n");
    int left =0;
    int right = arr_size-1;
    int key = 0;
    printf("Provide key to find");
    scanf("%d",&key);
    int key_location = binary_search(arr,left,right,key);
    if(key_location < 0)
    {
        printf("key not found\n");
    }
    else
    {
        printf("key found @ location: %d\n",key_location);
    }
    return 0;
}

