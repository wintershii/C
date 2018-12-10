#include<stdio.h>

struct student{
	char name[20];
	int grade;
	int clas;
	char gap;
	char west;
	int number;
	int sum=0;
}stu[101];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		int ojbk=0;
		scanf("%d",&x);
		for(int i = 0; i < x; i++){
			scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].grade,&stu[i].clas,&stu[i].gap,&stu[i].west,&stu[i].number);
		}
		for(int i = 0; i < x; i++){
			if(stu[i].grade > 80 && stu[i].number >= 1)
			   stu[i].sum+=8000;
			if(stu[i].grade > 85 && stu[i].clas > 80)
			   stu[i].sum+=4000;
			if(stu[i].grade > 90)
			   stu[i].sum+=2000;
			if(stu[i].grade > 85 && stu[i].west == 'Y')
			   stu[i].sum+=1000;
			if(stu[i].clas > 80 && stu[i].gap == 'Y')
			   stu[i].sum+=850;
			   ojbk+=stu[i].sum;
		}
		int max=0;
		for(int i = 1; i < x; i++){
			if(stu[i].sum > stu[max].sum)
			   max=i;
		}
		printf("%s\n",stu[max].name);
		printf("%d\n",stu[max].sum);
		printf("%d\n",ojbk);
	}
	return 0;
}
