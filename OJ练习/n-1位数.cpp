#include<stdio.h>
#include<math.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		int num=x;
		int count=0;
		int a[10];
		int i=0;
		while(num){
			a[i]=num%10;
			num/=10;
			i++;
		}
		count = i-1;
		
		int end=0;
		for(int j=count-1;j>=0;j--)
			end+=a[j]*pow(10,j);
		
		printf("%d\n",end);
	}
	return 0;
}
