#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		double b;
		scanf("%lf",&b);
		double r;
		r=(1.0*sqrt(3)*b/2.0)*(2.0/3.0);
		double sq=1.0*PI*r*r;
		printf("%.2lf\n",sq);
	}
	return 0;
}
