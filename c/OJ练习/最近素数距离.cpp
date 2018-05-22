#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int main(){
	int n,x;
	int i,j;
	scanf("%d",&n);
	while(n--){
		int dis1,dis2;
		int x1,x2,k;
		scanf("%d",&x);
		for(i=2;i<=sqrt(x);i++)
			if(x%i==0)
			   break;
		if(x==1){
		  printf("2 1\n");
			continue;
		}
		if(i>sqrt(x)){
		   printf("%d 0\n",x);
			  continue;
		    }
		
		
		for(i=x-1;i>=2;i--){
			for(j=2;j<=sqrt(i);j++)
				if(i%j==0)
				   break;
				if(j>sqrt(i)){
			       x1=i;
			       break;
			    }
		}
		
		for(i=x+1;;i++){
			for(j=2;j<=sqrt(i);j++)
				if(i%j==0)
				   break;
				if(j>sqrt(i)){
					x2=i;
				   break;
			     }
		}
		k=((x-x1)<=(x2-x))?x1:x2;
		printf("%d %.0f\n",k,fabs(x-k));
	}
	   return 0;
}
