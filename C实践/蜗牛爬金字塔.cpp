#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int h,i;
		int sum=0;
		scanf("%d",&h);
		for(i=1;;i++){
			sum+=10;
			if(sum>=h){
				printf("%d\n",i);
				break;
			}
			sum-=5;
		}
	}
	return 0;
}
