#include<stdio.h>
int main(){
	int t,n,a,b,c,i,j;
	scanf("%d",&t);
	while(t--){
		int sum[200]={0};  
		scanf("%d",&n);
		int s=0;
		while(n--){
		  scanf("%d %d %d",&a,&b,&c);
		  for(i=b;i<b+c;i++){ 
		      sum[i]+=a;
		    } 
		    
		  for(j=0;j<200;j++){
		      if(s<sum[j]){
		        s=sum[j];
		       }
		    }
	   }
		printf("%d\n",s);
	}
	return 0;
}
