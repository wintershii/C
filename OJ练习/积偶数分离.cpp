#include<stdio.h>
int main(){
	int n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		for(int i=1;i<=x;i++)
			if(i%2!=0)
			  printf("%d ",i);
		printf("\n");
		for(int i=1;i<=x;i++)
			if(i%2==0)
			  printf("%d ",i);
	}
	return 0;
}
