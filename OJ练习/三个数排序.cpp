#include<stdio.h>
int main(){
	int a[3];
	int i,j,temp;
	for(i=0;i<3;i++)
	  scanf("%d",&a[i]);
	for(i=0;i<2;i++)
	  for(j=0;j<2-i;j++)
	     if(a[j]>a[j+1]){
	     	temp=a[j];
	     	a[j]=a[j+1];
	     	a[j+1]=temp;
		 }
	 for(i=0;i<3;i++)
	    printf("%d ",a[i]);
	 	
}
