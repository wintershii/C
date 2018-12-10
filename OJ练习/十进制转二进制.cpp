#include<stdio.h>
int main(){
	long x;
	while(~scanf("%ld",&x)){
		int a[64];
		int i=0;
		long num=x;
		if(x==0){
			printf("0\n");
			continue;
		}
		while(num){
			a[i]=num%2;
			num/=2;
			i++;
		}
		for(int j=i-1;j>=0;j--)
		   printf("%d",a[j]);
		printf("\n");
	}
	return 0;
}
