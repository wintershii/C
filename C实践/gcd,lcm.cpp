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
	printf("������������:");
	scanf("%d %d",&a,&b);
	printf("���Լ��Ϊ��%d",gcd(a,b));
	printf("��С������Ϊ��%d",lcm(a,b));
}
