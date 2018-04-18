#include<stdio.h>

int jj(int k){
	int sum;
	  if(k>1)
	    sum=k+jj(k-1);
	     if(k==1)
	        return 1;
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	int q=n; 
	while(n--){
		int t=0,w,k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
			t+=i*jj(i+1); 
		printf("%d %d %d\n",q-n,k,t);
	}
}
