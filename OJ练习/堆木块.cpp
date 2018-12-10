#include<stdio.h>

int f(int x){
	int sum;
	if(x==1)
	   sum=1;
	else 
	   sum=x+f(x-1);
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x,sum=0;
		scanf("%d",&x);
		for(int i=1;i<=x;i++)
		    sum+=f(i);
		printf("%d\n",sum);
	}
	return 0;
} 
