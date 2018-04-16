#include<stdio.h>

int newjc(int n){
	int num;
	if(n%2!=0)
		num=n*newjc(n-1);
	else num=1;
	return num;
}

int main(){
	int a,r;
	scanf("%d",&a);
	while(a--){
		int n;
		scanf("%d",&n);
		r=newjc(n);
		printf("%d\n",r);
	}
	return 0;
}
