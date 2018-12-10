#include<stdio.h>
int main(){
	int x,a[3],i,num;
	while(scanf("%d",&x)!=EOF&&x!=0){
		i=2;num=x;
		while(num){
			a[i]=num%10;
			num/=10;
			i--;
		}
	  if(x>=100&&x<1000){
		 if(x==a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2])
		   printf("Yes\n");
		 else
		   printf("No\n");
	  }
	} 
	return 0;
}
