#include<stdio.h>
#include<math.h>

int main(){
	int m,n;
	while(~scanf("%d%d",&m,&n) && m != 0&&n != 0){
		int num1 = m,num2 = n;
		int a[1001],b[1001];
		int i=0;
		m=0;n=0;
		while(num1){
			a[i] = num1%10;
			num1/=10;
			i++;
		}
		for(int j=0;j<i;j++)
			m+=a[j]*pow(10,i-1-j);
		i=0;	
		while(num2){
			b[i] = num2%10;
			num2/=10;
			i++;
		}
		for(int j=0;j<i;j++)
			m+=b[j]*pow(10,i-1-j);
		printf("%d\n",m+n);
	}
	return 0;
}
