#include <stdio.h>
int main(){
	short num = 0x1122;		//short ռ�����ֽ� 
    char *c;				//char ռһ���ֽ� 
	c = &num;
	if(*c == 0x22)
		printf("this is little end\n");
	else
 		printf("this is big end\n");
    return 0;
}
