#include<stdio.h>
int main(){
	int n,i,j,k;
	int a[101][101];
    int index=1; 
	scanf("%d",&n);
	for(i=1,k=0;i<n;i++,k++){
		for(j=k;j<n-k&&index<=n*n;j++)
			a[j][n-k-1]=index++;
		for(j=n-k-2;j>=k&&index<=n*n;j--)
			a[n-k-1][j]=index++;
		for(j=n-k-2;j>=k&&index<=n*n;j--)
			a[j][k]=index++;
		for(j=k+1;j<n-k-1&&index<=n*n;j++)
			a[k][j]=index++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		    printf("%d ",a[i][j]);
		printf("\n");
	}
}
