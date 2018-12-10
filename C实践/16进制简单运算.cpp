#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		char c;
		scanf("%x%c%x",&a,&c,&b);
		int sum;
		if(c=='+')
		   sum=a+b;
		else if(c=='-')
		   sum=a-b;
		printf("%o\n",sum);
	}
	return 0;
}
