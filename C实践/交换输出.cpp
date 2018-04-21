#include<stdio.h>
int main(){
	int a[101];
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++)
		    scanf("%d",&a[i]);
		int min=0;
	    for(int i=0;i<n;i++)
	        if(a[min]>a[i])
	           min=i;
	    int temp=a[min];
	    a[min]=a[0];
	    a[0]=temp;
	    for(int i=0;i<n;i++){
	      if(i==n-1)
	         printf("%d\n",a[i]);
		   else printf("%d ",a[i]);
	      }
	}
	return 0;
}
