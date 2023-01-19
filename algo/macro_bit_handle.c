#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

int main()
{
	uint8_t byte= 0xff;
	printf("%d\n", (bitset(byte,1)));
	printf("%d\n", (bitclear(byte,2)));
	printf("%d\n", (bitflip(byte,3)));
	printf("%d\n", (bitcheck(byte,4)));
	return 0;
}