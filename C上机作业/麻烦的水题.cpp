#include<stdio.h>

void endscore(int a[][100],int m,int n,float b[100]){ 
	int xmax,ymax,xmin,ymin;
	int max,min;
	int i,j,sum;
	int x=n-2;
	for(i=0;i<m;i++){
		xmax=i;ymax=0;xmin=i;ymin=0;
		max=a[i][0];
		min=a[i][0];
	  for(j=1;j<n;j++){
	  	  if(a[i][j]>max){
	  	  	  max=a[i][j];
	  	  	  xmax=i;ymax=j;
			}
		  if(a[i][j]<min){
		  	  min=a[i][j];
		  	  xmin=i;ymin=j;
		  }
	  }
	  a[xmax][ymax]=0;
	  a[xmin][ymin]=0;
    }
    
    for(i=0;i<m;i++){
    	sum=0;
    	for(j=0;j<n;j++)
    	   sum+=a[i][j];
    	b[i]=(sum*1.0)/(x*1.0);
	}
}

void sort(float b[],int m){
	for(int i=0;i<m;i++)
	  for(int j=0;j<m-1-i;j++){
	  	if(b[j]<b[j+1]){
	  		float temp=b[j];
	  		b[j]=b[j+1];
	  		b[j+1]=temp;
		  }
	  }
}

int main(){
	int a[100][100];
	float b[100];
	int m,n;
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		printf("第%d个选手：",i+1);
	   for(j=0;j<n;j++)
	     scanf("%d",&a[i][j]);
	}
	endscore(a,m,n,b);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		 printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	sort(b,m);
	for(i=0;i<m;i++)
	 printf("%.2f ",b[i]);
	return 0;
} 
