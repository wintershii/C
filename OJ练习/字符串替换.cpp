#include<stdio.h>
#include<string.h>
int main(){
	char a[1001];
	while((gets(a))!=NULL){
		for(int i=1;i<strlen(a);i++){
			if(a[i-1]=='y'&&a[i]=='o'&&a[i+1]=='u'){
				a[i-1]='w';a[i]='e';
				for(int j=i+1;j<strlen(a);j++)
				     a[j]=a[j+1];
			}
		}
		printf("%s\n",a);
	}
	return 0;
} 
