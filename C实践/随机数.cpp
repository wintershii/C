#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a[101];
		int n;
		int change=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		    scanf("%d",&a[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
			   if(a[j]==a[i]){
			   	    a[j]=-1;
			   	    change++;
			   }
		    }
		}
		for(int i=0;i<n-1;i++)
		   for(int j=0;j<n-1-i;j++){
		   	    if(a[j]>a[j+1]){
		   	   	    int temp=a[j];
		   	   	    a[j]=a[j+1];
		   	   	    a[j+1]=temp;
				}
		   }
		   printf("%d\n",n-change);
		for(int i=change;i<n;i++){
			if(i==n-1)
			  printf("%d\n",a[i]);
			else 
			  printf("%d ",a[i]);
		}
		   
	}
	return 0;
}
