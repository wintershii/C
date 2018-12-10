#include<stdio.h>
int main(){
	int n;
	while(~scanf("%d",&n)){
		int a[10000],b[4000];
		int max,min; 
		for(int i=0;i<n;i++)
		    scanf("%d",&a[i]);  
		for(int i=1;i<=n/3;i++){
			if(i%2==1){
				max=(i-1)*3;
				for(int j=max;j<i*3;j++)
				    if(a[max]<a[j])
				       max=j;
				b[i]=a[max];
			}
			else{
				min=(i-1)*3;
				for(int j=(i-1)*3;j<i*3;j++)
				    if(a[min]>a[j])
				       min=j;
				b[i]=a[min];
			}
		}
		max=0;
		for(int i=1;i<=n/3;i++)
		    if(b[max]<b[i])
		       max=i;
		printf("%d\n",b[max]);
	}
	return 0;
}
