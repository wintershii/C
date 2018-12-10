#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		int n,m,flag=1;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++){
			if(2*i+4*(n-i)==m){
				printf("%d %d\n",i,n-i);
				flag=0;
			}
		}
		  if(flag)
			printf("No answer\n");
	}
	return 0;
}
