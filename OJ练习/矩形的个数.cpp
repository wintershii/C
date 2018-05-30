#include<stdio.h>
int main(){
	long long a,b;
	while(~scanf("%lld%lld",&a,&b)){
		long long  count=0;
		 count=a*b*(a+1)*(b+1)/4;
		 printf("%lld\n",count);
		
	}
	return 0;
}
