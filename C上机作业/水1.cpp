#include<stdio.h>

int howmany(int a[],int n){
	int sum=0,count=0;
	float aver;
	for(int i=0;i<n;i++)
	  sum+=a[i];
	  aver=sum*1.0/n*1.0;
	  for(int i=0;i<n;i++)
	  if(a[i]*1.0>aver)
	    count++;
	return count;
}

int main(){
	int a[100],n,count;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	  count = howmany(a,n);
	  printf("%d",count);
	return 0;
} 
