#include<stdio.h>
#include<string.h>

char word[10] = {'0','1','2','3','4','5','6','7','8','9'};

char re[40][33];
char de[40][33];

void nizhi(int m[],int n)
{
	for(int i = 0; i < n/2; i++)
	{
		int tmp = m[i];
		m[i] = m[n-i-1];
		m[n-i-1] = tmp;
	}
}

int max(int x,int y)
{
	if(x >= y)
		return x;
	return y;
}

int main()
{
	int ni;
	scanf("%d",&ni);
	int ti = ni;
	while(ti--)
	{
		char m[31];
		char n[31];
		scanf("%s",m);
		scanf("%s",n);
		int m1[31] = {0};
		int n1[31] = {0};
		for(int i = 0; i < strlen(m); i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if(m[i] == word[j])
					m1[i] = j;
			}
		}
		
		for(int i = 0; i < strlen(n); i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if(n[i] == word[j])
					n1[i] = j;
			}
		}
		nizhi(m1,strlen(m));
		nizhi(n1,strlen(n));
		int k = 0;
		int result[33] = {0};
		while(k < strlen(m) && k < strlen(n))
		{
			int t = result[k] + m1[k] + n1[k];
			if(t <= 9)
				result[k] = t;
			else
			{
				result[k] = t % 10;
				result[k+1]++;
			}
			k++;
		}
		if(k < strlen(m))
		{
			for(int q = k; q < strlen(m); q++)
			{
				result[q] += m1[q];
				if(result[q] >= 10)
				{
					result[q] = result[q] % 10;
					result[q+1]++;
				}
			}
		}
		if(k < strlen(n))
		{
			for(int q = k; q < strlen(n); q++)
			{
				result[q] += n1[q];
				if(result[q] >= 10)
				{
					result[q] = result[q] % 10;
					result[q+1]++;
				}
			}
		}
		int bit;
		for(bit = max(strlen(m),strlen(n)); ;bit++)
		{
			if(result[bit] == 0)
				break;
		}
		nizhi(result,bit);
		int i;
		for(i = 0; i < bit; i++)
		{
			re[ni-ti-1][i] = word[result[i]];
		}
		re[ni-ti-1][i] = '\0';
		
		int p = 0;
		int result2[33] = {0};
		
		while(p < strlen(m)) 
		{
			int t = m1[p] - n1[p];
			if(t >= 0)
				result2[p] += t;
			else
			{
				result2[p] += 10 + m1[p] - n1[p];
				result2[p+1] -= 1;
			}
			if(result2[p] == -1)
			{
				result2[p] += 10;
				result2[p+1] += -1;
			}
			p++;
		}
		
		int bit2;
		for(bit2 = strlen(m); ;bit2--)
		{
			if(result2[bit2] != 0)
				break;
		}
		bit2++;
		nizhi(result2,bit2);
		int j;
		for(j = 0; j < bit2; j++)
		{
			de[ni-ti-1][j] = word[result2[j]];
		}
		de[ni-ti-1][j] = '\0';
	}
	for(int i = 0; i < ni; i++)
		printf("%s\n",re[i]);
	for(int i = 0; i < ni; i++)
	{
		if(de[i][0] != '\0') 
			printf("%s\n",de[i]);
		else
			printf("0\n");
	}
	return 0;
}

