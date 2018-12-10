#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char a[50];
		gets(a);
		int len=strlen(a);
		for(int i=len-1;i>=0;i--)
		   if(a[i]>='a'&&a[i]<='z')
		     printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
