#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m,count=0;
		int t;
		float sum=0;
		char a[10];
		scanf("%d",&m);
		while(m--){
			scanf("%s",a);
				if(a[0]=='I')
					count++;
			else if(a[0]=='S'){
				scanf("%d",&t);
				sum+=1.0*t/pow(20,count);
			}
				else 
				     count--;
		}
		sum*=60.0;
		printf("%.0f\n",sum);
	}
	return 0;
}
