#include<stdio.h>
int main(){
	int a[5],max,min,i;
	for(i=0;i<5;i++)
	   scanf("%d",&a[i]); 
	max=a[0];min=a[0];
	for(i=1;i<5;i++){
		if(a[i]>max)
		  max=a[i];
		if(a[i]<min)
		  min=a[i];
	}
	printf("%d %d\n",min,max);
	return 0;
}
