#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		for(int i = 1; i <= m; i++)
		    for(int j = i;j <= 9; j++){
		        if(j == 9)
		           printf("%d*%d=%d\n",i,j,i*j);
				else
				   printf("%d*%d=%d ",i,j,i*j);
		    }
		printf("\n");
	}
	return 0;
} 
