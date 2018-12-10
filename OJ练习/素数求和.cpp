#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,m,sum;
	int i,j;
	int a[1500];
	scanf("%d",&n);
	while(n--){
		sum=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		    scanf("%d",&a[i]);
		for(i=0;i<m;i++){
			for(j=2;j<=sqrt(a[i]);j++)
			   if(a[i]%j==0)
			      break;
			if(j>sqrt(a[i])&&a[i]!=1)
			   sum+=a[i];
		}
		printf("%d\n",sum);	
	}
	return 0;
}
