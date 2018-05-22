#include <stdio.h>

void binary_to_ascii( unsigned int value){
	unsigned int quotient;
	quotient = value/10;
	if( quotient != 0)
		binary_to_ascii(quotient);
	putchar(value %10 + '0');
}

int main(){
	int x;
	scanf("%d",&x);
	binary_to_ascii(x);
	return 0;
} 
