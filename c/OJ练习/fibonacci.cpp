#include<stdio.h>

int fibonacci(int x){
	int num;
	if(x==1||x==2)
	    num=1;
	else num=fibonacci(x-1)+fibonacci(x-2);
	return num;
}

int main(){
	int n,x,num;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		num=fibonacci(x);
		printf("%d\n",num);
	}
	return 0;
}
