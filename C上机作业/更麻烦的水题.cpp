 #include<stdio.h>

void hindle(int a[][5]){
    int max,min1,min2,min3,min4;
	int xmax=0,ymax=0,xmin1=0,ymin1=0,xmin2=0,ymin2=0,xmin3=0,ymin3=0,xmin4=0,ymin4=0;
	int b[25];
	int i,j,temp;
     for(i=0;i<5;i++)
		 for(j=0;j<5;j++)
			 b[5*i+j]=a[i][j];
 
	for(i=0;i<25;i++)
		for(j=0;j<24-i;j++)
			if(b[j]<b[j+1]){
			  temp=b[j];
			  b[j]=b[j+1];
			  b[j+1]=temp;
			}


	max=b[0];
	min1=b[24];min2=b[23];min4=b[22];min4=b[21];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++){
			if(max==a[i][j]){
			  xmax=i;
			  ymax=j;
			}
			if(min1==a[i][j]){
			  xmin1=i;
			  ymin1=j;
			}
			if(min2==a[i][j]){
			  xmin2=i;
			  ymin2=j;
			}
			if(min3==a[i][j]){
			  xmin3=i;
			  ymin3=j;
			}
			if(min4==a[i][j]){
			  xmin4=i;
			  ymin4=j;
			}
		}

		 a[2][2]=max;
		 a[4][4]=min4;
		 a[0][4]=min2;
		 a[4][0]=min2;
		 a[0][0]=min1;
}

int main(){
   int i,j,a[5][5];
   for(i=0;i<5;i++)
	   for(j=0;j<5;j++)
		   scanf("%d",&a[i][j]);
    hindle(a);
    printf("\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
		   printf("%d ",a[i][j]);
	      printf("\n");
	}
  return 0;
}

