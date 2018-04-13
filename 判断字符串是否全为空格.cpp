#include<stdio.h>
#include<string.h>

int _ifblank(char judge[]){
	char ch;
	char true_[20];
	int i,j;
	for(i=0,j=0;i<strlen(judge);i++){
		if(judge[i]==' ')
		 continue;
		else{
		true_[j]=judge[i];
		j++;
	   }
	}
	true_[j]='\0';
	return strlen(true_);
}

int main(){
	int x;
	char a[20];
	gets(a);
	x=_ifblank(a);
	printf("%d",x);
	return 0;
}
