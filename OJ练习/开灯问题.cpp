#include<stdio.h>
int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		int a[1001]={0};
		int num=k;
		while(num--){
			int t=k-num;
			if(t==1){
				for(int i=0;i<n;i++)
				  a[i]=1;
			}
			
			else{
				for(int i=0;i<n;i++){
				   if((i+1)%t==0&&a[i]==1&&(i+1)>=t){
                        a[i]=0;
                        continue;
                    }
				   if((i+1)%t==0&&a[i]==0&&(i+1)>=t){  
						a[i]=1;
				        continue;
				    }
			    }
			}
		}
		for(int i=0;i<n;i++)
		   if(a[i]==1)
		      printf("%d ",i+1);    
		printf("\n");
	}
	return 0;
}
