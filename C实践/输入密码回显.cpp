#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void secretword(char key[]){
	unsigned char c;
	int i=0;
	while((c=getch())!='\r'){
		if(i<20&&isprint(c)){
			key[i]=c;
			i++;
			putchar('*');
		}
		else if(i>0&&c=='\b'){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	printf("\n");
	key[i]='\0';
} 

int main(){
	printf("ÇëÊäÈëÃÜÂë£º");
	char key[20];
	secretword(key);
	printf("\nÃÜÂëÊÇ£º");
	printf("%s",key);
}
