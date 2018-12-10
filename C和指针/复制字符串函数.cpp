#include<stdio.h>

void strcpy(char *buffer,char const *string){
	while((*buffer++ = *string++) != '\0')
			;
}

int main(){
	char string[10];
	char buffer[10];
	scanf("%s",string);
	strcpy(buffer,string);
	printf("%s",buffer);
	return 0;
} 
