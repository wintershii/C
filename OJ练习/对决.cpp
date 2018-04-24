#include<stdio.h>
int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)&&n!=0&&k!=0){
		int sum[10000];
		int flag=0; 
		for(int i = 1;i <= n/2; i++)
		    sum[i] = i*(n-i);
		for(int i = 1;i <= n/2; i++)
		    if(sum[i] == k)
		    	flag=1;
		
		if(flag)
			printf("YES\n");
		else 
		    printf("NO\n");
	}
	return 0;
}
