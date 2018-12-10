#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		float m,x,y,z;
		float l;
		scanf("%f%f%f%f",&m,&x,&y,&z);
		l=(z*x*m)/(y-x);
		printf("%.2f\n",l);
	}
	return 0;
}
