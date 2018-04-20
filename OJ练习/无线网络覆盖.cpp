#include<stdio.h>
#include<math.h>
int main(){
	int n,k;
	scanf("%d",&n);
	while(n--){
		float l,d,r,n;
		scanf("%f%f%f",&l,&d,&r);
	    n=l/sqrt(4*r*r-d*d);
	    if(r<=d/2){
	    	printf("impossible\n");
	    	continue;
		}
	    if(n==(int)n)
	        k=n;
	    else k=(int)n+1;
	    printf("%d\n",k);
	    
	}
	return 0;
}
