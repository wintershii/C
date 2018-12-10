#include<stdio.h>
int main(){
   int n;
   int i,j,k;
   char a[3],temp;
    scanf("%d",&n);
    getchar();
    while(n--){
    	scanf("%s",a);
    	for(int i=0;i<2;i++)
    	   for(int j=0;j<2-i;j++)
    	      if(a[j]>a[j+1]){
    	      	temp=a[j];
    	      	a[j]=a[j+1];
    	      	a[j+1]=temp;
			  }
			  
		for(int i=0;i<3;i++)
		   printf("%c ",a[i]);
		printf("\n");
	}
    return 0;
}
