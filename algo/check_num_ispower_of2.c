#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int is_power_of_two(int value)
{
	if(value == 0)
		return 0;

	while(value!=1)
	{
		if( (value % 2) != 0)
			return 0;

		value = value/2;
	}
}
int main()
{
	is_power_of_two(31) ? printf("Yes\n") : printf("No\n");
	is_power_of_two(64) ? printf("Yes\n") : printf("No\n");
	return 0;
}