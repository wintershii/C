#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		int sum=1;
		scanf("%d",&m);
		for(int i=m;i>=1;i--){
			sum=(1+sum)*2;
		}
		
		printf("%d\n",sum);
	}
	return 0;
}
