#include<stdio.h>
#include<math.h>

int prime(int x)
{
	if(x == 1)
		return 0;
	for(int i = 2; i <= sqrt(x); i++)
	{
		if(x % i == 0)
			return 0;
	}
	return 1;
}

int niprime(int x)
{
	int a[100];
	int n = 0;
	int num = x;
	while(num)
	{
		a[n] = num%10;
		num /= 10;
		n++;
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i] * pow(10,n-i-1);
	}
	if(prime(x) == 1 && prime(sum) == 1)
		return 2;
	if(prime(x) == 0)
		return 0;
	if(prime(x) == 1 && prime(sum) == 0)
		return 1;
}

int main()
{
	int n;
	int num[11] = {0};
	int i;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&num[i]);
	i = 0;
	while(i < n)
	{
		if(niprime(num[i]) == 2)
			printf("%d是可逆素数\n",num[i]);
		if(niprime(num[i]) == 1)
			printf("%d是素数，但不是可逆素数\n",num[i]);
		if(niprime(num[i]) == 0)
			printf("%d不是素数\n",num[i]);
		i++;
	}
	
	return 0;
}
