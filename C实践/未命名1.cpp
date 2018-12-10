#include<stdio.h>
#include<string.h>

struct person{
	char name[20];
	int count;
};

int main() {
	struct person leader[3]={"fu",0,"lu",0,"shou",0},temp;
	int i,j,k;
	int n=3,m;
	char name[20];
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		printf("NO.%d: ",i);
		scanf("%s",name);
		for(j=0;j<3;j++)
			if(strcmp(name,leader[j].name)==0)
			  leader[j].count++;
	}
	
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++)
		  if(leader[k].count<leader[j].count)
		    k=j;
		if(k!=i){
			temp=leader[k];
			leader[k]=leader[i];
			leader[i]=temp;
		}
	}
	
	for(i=0;i<3;i++){
		printf("%s   %d\n",leader[i].name,leader[i].count);
	}
	return 0;
}
