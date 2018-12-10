#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a[4],x,num,i,sum=0;
		int j,k; 
		int q=0;
		scanf("%d",&x);
		num=x;
		while(1){
			if(num!=x)
			num=q;
			i=3;
		  while(num){
			a[i]=num%10;
			num/=10;
			i--;
		  }
		  for(j=0;j<3;j++)
		     for(k=0;k<3-j;k++)
		        if(a[k]<a[k+1]){
		        	int temp=a[k];
		        	a[k]=a[k+1];
		        	a[k+1]=temp;
				}
		    num=a[0]*1000+a[1]*100+a[2]*10+a[3]-a[3]*1000-a[2]*100-a[1]*10-a[0];
		    sum++;
		    if(num==q){
		    	printf("%d\n",sum);
		    	break;
			}
			   q=num;
	   }
	} 
	return 0;
} 
