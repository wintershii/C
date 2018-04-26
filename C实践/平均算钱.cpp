#include<stdio.h>
int main(){
	int n = 12;
	double x,sum=0;
	while(n--){
		scanf("%lf",&x);
		sum+=x;
	}
	printf("%.2lf\n",sum/12);
	return 0;
}
