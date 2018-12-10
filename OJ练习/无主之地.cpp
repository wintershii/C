#include<stdio.h>
int main(){
	int m,n;
	int a[101]={0};
	int mark[101]={0};
	int k=0;
	
	while(scanf("%d%d",&m,&n)&&m!=0&&n!=0){
		int flag=1;
		for(int j=0;j<=k;j++)
		   if(mark[j] == m)
		      flag=0;
		if(flag){
		    mark[k]=m;
		    k++;
		}
		a[m]+=n;
	}
	for(int i=0;i<k;i++){
	    if(a[mark[i]]!=0){
	    	printf("%d %d\n",mark[i],a[mark[i]]);
		}
	}
	return 0;
}
