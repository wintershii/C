#include<stdio.h>

int strlen(char const *string){
	int length;
	for(length = 0;*string++ != '\0';)
		length+=1;
	return length;
}

int main(){
	char string[100];
	scanf("%s",string);
	printf("%d\n",strlen(string));
	return 0;
} 
