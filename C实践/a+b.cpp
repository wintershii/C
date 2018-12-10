#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a+b-c>=-0.0001&&a+b-c<=0.0001)
		   printf("Yes\n");
		else
		   printf("No\n");
	}
	return 0;
}
