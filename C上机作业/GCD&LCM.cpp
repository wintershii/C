#include<stdio.h>

int max(int x,int y){
	if(x>y)
	   return x;
	return y;
}

int gcd(int x,int y){                          //求最大公约数 
	int a,temp;
	if(max(x,y)!=x){
		temp=y;
		y=x;
		x=temp;
	}
	while((temp=x%y)!=0){
		x=y;
		y=temp;
	}
	return y;
}

int lcm(int x,int y,int a){
	int b;
	b=x*y/a;
	return b; 
}

int main(){
	int x,y;
	int a,b;
	scanf("%d %d",&x,&y);
	a=gcd(x,y);
	b=lcm(x,y,a);
	printf("最大公约数：%d 最小公倍数： %d",a,b);
	return 0;
} 
