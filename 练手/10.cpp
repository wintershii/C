#include<stdio.h>
#include<string.h>

struct date{
	int year;
	int month;
	int day;
};

struct BOOK{
	int num;
	char name[20];
	char writer[20];
	char publi[40];
	struct date d;
	float price;
}book[21];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&book[i].num);
		scanf("%s",book[i].name);
		scanf("%s",book[i].writer);
		scanf("%s",book[i].publi);
		scanf("%d-%d-%d",&book[i].d.year,&book[i].d.month,&book[i].d.day);
		scanf("%f",&book[i].price);
	}
	
	for(int i = 0; i < n-1; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(book[j].price < book[min].price)
			{
				min = j;
			}
		}
		if(min != i)
		{
			struct BOOK tmp = book[i];
			book[i] = book[min];
			book[min] = tmp;
		}
	}
	printf("��� ���� ���� ������ �������� �۸�\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",book[i].num);
		printf("%s ",book[i].name);
		printf("%s ",book[i].writer);
		printf("%s ",book[i].publi);
		printf("%d��%d��%d�� ",book[i].d.year,book[i].d.month,book[i].d.day);
		printf("%.2f\n",book[i].price);
	}
	return 0;
}





