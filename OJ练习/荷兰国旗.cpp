#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char a[1001];
		int j,k,q;
		gets(a);
		int len=strlen(a);
		int r=0,w=0,b=0;
		for(int i=0;i<len;i++){
			if(a[i]=='R')
			   r++;
			if(a[i]=='W')
			   w++;
			if(a[i]=='B')
			   b++;
		}
		for(j=0;j<r;j++)
		   a[j]='R';
		for(k=r;k<r+w;k++)
		   a[k]='W';
		for(q=r+w;q<r+w+b;q++)
		   a[q]='B';
		for(int i=0;i<len;i++)
		   printf("%c",a[i]);
		printf("\n");
	}
	return 0;
} 
