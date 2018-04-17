#include<stdio.h>
#include<math.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		 float x1,y1,x2,y2,d;
		 scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
		 d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		 printf("%.2f\n",d);
	}
	return 0;
} 
