/*
* 2. There is sparse two-dimensional Matrix with 10 Rows and 15 Columns, the element type is Integer.
* Please write a program to pack it and store it in memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROWS	10
#define COLUMNS	15

/* spare matrix of size 10x15 */
int spare_matrix [ROWS][COLUMNS] = {
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
    {0, 0, 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0},
};

/*
 * get the count of valid elements(greater than 0).
 * returns count of numbers greater than 0
 */
int get_valid_elements_count()
{
    uint8_t r=0,c=0,count=0;
    /* traverse thru the spare matrix and count the number of valid elements (greater than 0) */
    for(r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLUMNS; c++)
        {
            if(spare_matrix[r][c] > 0)
                count++;
        }
    }
    return count;
}

/*
 * store valid elements in a memory location. Used dynamic memory allocation for storing
 * input: memory size to be allocated
 * return the pointer of the memory location where the elements are stored
 */
int *store_valid_elements(uint8_t mem_size)
{
    uint8_t index=0;
    /* allocate memory of size mem_size */
    int *data_ptr = (int *)calloc(mem_size,sizeof(int));
    if(data_ptr == NULL)
    {
        printf("calloc failed\n");
        return NULL;
    }
    uint8_t r=0,c=0;
    /* loop to store the valid elements in the allocated memory location */
    for(r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLUMNS; c++)
        {
            if(spare_matrix[r][c] > 0)
            {
                data_ptr[index] = spare_matrix[r][c];
                index++;
            }
        }
    }
    return data_ptr;
}

int main()
{
	/* get number of elements (greater than 0) to be stored from spare matrix */
    uint8_t valid_count = get_valid_elements_count();
    printf("valid elements count: %d\n", valid_count);

    /* get memory location with valid elements stored */
    int *mem_ptr = store_valid_elements(valid_count);
    uint8_t index = 0;

    /* print valid elements stored in memroy location */
    for(index = 0; index < valid_count; index++)
    {
        printf("%d", mem_ptr[index]);
    }
    printf("\nabove valid elements are stored from spare matrix\n");
    /* free the memory allocated */
    free(mem_ptr);

	return 0;
}