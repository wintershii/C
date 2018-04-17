#include<stdio.h>
#include<math.h>
int gcd(int m,int n){
	int q;

	while(n){
		q=m%n;
		m=n;
		n=q;
	}
	return m;
}

int main(){
	int a,b,c,d;
	char m;
	while(~scanf("%d/%d%c%d/%d",&a,&b,&m,&c,&d)){
		a*=d;c*=b;d=b*d;
		if(m=='+')
			a=a+c;
		else if(m=='-')
			a=a-c;
		if(a==0)
			printf("0\n");
			
		else if(a%d==0) 
		  printf("%d\n",a/d);
		else{
			int k=fabs(a);
			c=gcd(k,d);
			printf("%d/%d\n",a/c,d/c);
		}
	}
	return 0;
}
