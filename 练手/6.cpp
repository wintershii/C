#include<stdio.h>

int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int runnian(int x)
{
	if((x % 4 == 0 && x % 100 !=0 )|| (x % 400) == 0)
		return 1;
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int year,month,day;
		int ex;
		scanf("%d-%d-%d %d",&year,&month,&day,&ex);
		while(ex--)
		{
			mon[1] = 28 + runnian(year);
			day++;
			if(day > mon[month-1])
			{
				day = 1;
				month++;
			}
			if(month > 12)
			{
				month = 1;
				year++;
			}
		}
		
		mon[1] = 28;
		int sum = 0;
		for(int i = 1900; i < year; i++)
		{
			if(runnian(i) == 1)
			{
				sum += 366;
				continue;
			}
				
			sum += 365;
		}
		for(int i = 1; i < month ; i++)
		{
			if(i == 2)
			{
				sum += mon[1] + runnian(year);
				continue;
			}
			sum += mon[i-1];
		}
		sum += day - 1;
		int w = sum % 7;
		printf("%d��%02d��%02d�� ",year,month,day);
		switch(w)
		{
			case 0:
				printf("����һ\n");
				break;
			case 1:
				printf("���ڶ�\n");
				break;
			case 2:
				printf("������\n");
				break;
			case 3:
				printf("������\n");
				break;
			case 4:
				printf("������\n");
				break;
			case 5:
				printf("������\n");
				break;
			case 6:
				printf("������\n");
				break;
		}
	}
	return 0;
}
