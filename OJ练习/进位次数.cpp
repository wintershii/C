#include<stdio.h>
int main(){
	while(1){
	int m,n;
	scanf("%d%d",&m,&n);
	if(m==0&&n==0)
	   return 0;
	int a[3],b[3];
	int num1,num2;
	int i=2,j=2;
	num1=m;num2=n;
	while(num1){
		a[i]=num1%10;
		num1/=10;
		i--;
	}
	while(num2){
		b[j]=num2%10;
		num2/=10;
		j--;
	}
	int sum=0;
	for(int k=2;k>=0;k--){
		if(a[k]+b[k]>=10){
			sum++;
			a[k-1]+=1;
		}
	}
	printf("%d\n",sum);
    }
	return 0;
	
}
