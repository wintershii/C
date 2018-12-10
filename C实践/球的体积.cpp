#include<stdio.h>
#define PI 3.1415926
int main(){
	double r,v;
	while(scanf("%lf",&r)!=EOF){
		v=4.0/3*PI*r*r*r;
		   printf("%d\n",int(v+0.5));
	}
	return 0;
} 
