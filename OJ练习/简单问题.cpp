#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		int count=0;
		scanf("%d",&x);
		for(int i=1;(i+1)*(i+1)<=x+1;i++)
		        if((x+1)%(i+1)==0)
		           count++;
	   printf("%d\n",count);
	}
	return 0;
}
