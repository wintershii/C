#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		int num=x;
		int sum=0;
		int t;
		while(num){
			t=num%2;
			num/=2;
			if(t==1)
			  sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
