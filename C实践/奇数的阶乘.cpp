#include<stdio.h>

int newjc(int n){
	int num=1;
	if(n>=1){
	  if(n%2!=0)
		 num=n*newjc(n-1);
	  else num=newjc(n-1);
    }
	 return num;
}

int main(){
	int a,r;
	scanf("%d",&a);
	while(a--){
		int n;r=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			r+=newjc(i);
		}
		printf("%d\n",r);
	}
	return 0;
}
