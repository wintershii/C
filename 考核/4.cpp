#include<stdio.h>
#include<string.h>

int numlist[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
char wordlist[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	char zheti[50];
	char buhui[50];
	int sb1[50];
	int sb2[50];
	gets(zheti);
	gets(buhui);
	int sb[50] = {0};
	char dasb[50];
	int length = 0;
	for(int i =0; i < strlen(zheti); i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(zheti[i] == wordlist[j])
				sb1[i] = numlist[j];
		}
	}
	
	for(int i =0; i < strlen(buhui); i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(buhui[i] == wordlist[j])
				sb2[i] = numlist[j];
		}
	}
	
		for(int i = 0; i < strlen(zheti)/2; i++)
			swap(&sb1[i],&sb1[strlen(zheti)-i-1]);
		for(int i = 0; i < strlen(buhui)/2; i++)
			swap(&sb2[i],&sb2[strlen(buhui)-i-1]);

	int i;
	for(i = 0; i < strlen(zheti) && i < strlen(buhui); i++)
	{
		if(sb1[i] + sb2[i] < 15){
			sb[i] += sb1[i] + sb2[i];
			length++;
		}
		else
		{
			sb[i] += (sb1[i] + sb2[i]) % 16;
			sb[i+1] += (sb1[i] + sb2[i]) / 16;
		}
	}
	
	if(i < strlen(zheti))
	{
		for(int j = i; j < strlen(zheti); j++)
		{
			sb[j] += sb1[j];
		}
	}
	
	else if(i < strlen(buhui))
	{
		for(int j = i; j < strlen(buhui); j++)
		{
			sb[j] += sb2[j];
		}
	}
	
	for(int i =0; i < 50; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if(sb[i] == numlist[j])
				dasb[i] = wordlist[j];
		}
	}
	
	int k;
	for(k = strlen(dasb)-1; k>=0; k--){
		if(dasb[k] != '0')
		break;
		
	}
	for(int j = k; j >= 0; j--)
	{
		printf("%c",dasb[j]);
	}
	return 0;
}

