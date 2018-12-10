#include<stdio.h>

int isrn(int year){
	if(year%400==0)
	   return 1;
	if(year%4==0&&year%100!=0)
	   return 1;
	return 0;
}

int main(){
	int n,sum;
	scanf("%d",&n);
	while(n--){
		int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		sum=0;
		int year,month,day;
		scanf("%d%d%d",&year,&month,&day);
		m[1]+=isrn(year);
		while(month>0){
		    sum+=m[month-2];
		    month--;
		}
		sum+=day;
		printf("%d\n",sum);
		
	}
	return 0;
}
