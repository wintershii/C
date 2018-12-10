#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x,y,sum=0;
		scanf("%d%d",&x,&y);
		while(x>=y){
			sum+=y;
			x-=y;
			x++;
		}
		sum+=x;
		printf("%d\n",sum);
	}
	return 0;
} 
