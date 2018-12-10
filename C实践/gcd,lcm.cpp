#include<stdio.h>

int gcd(int a,int b)
{
	return a%b ? gcd(b,a%b):b;
} 

int lcm(int a,int b)
{
	return a * b/gcd(a,b);
} 

int main()
{
	int a,b;
	printf("请输入两个数:");
	scanf("%d %d",&a,&b);
	printf("最大公约数为：%d",gcd(a,b));
	printf("最小公倍数为：%d",lcm(a,b));
}
