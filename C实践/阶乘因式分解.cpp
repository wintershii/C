#include<stdio.h>
#include<math.h>
int main(){
	int x;
	scanf("%d",&x);
	while(x--){
		int a,b,sum=0;
		scanf("%d%d",&a,&b);
		for(int i=1;;i++){
			if(pow(b,i)<=a)
			  sum+=a/pow(b,i);
			else
			  break;
		}
		printf("%d\n",sum);
	}
	return 0;
} 
