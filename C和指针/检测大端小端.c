#include <stdio.h>
int main(){
	short num = 0x1122;		//short 占两个字节 
    char *c;				//char 占一个字节 
	c = &num;
	if(*c == 0x22)
		printf("this is little end\n");
	else
 		printf("this is big end\n");
    return 0;
}
