#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		int a[1001],b[1001];
		long c[1001]; 
		for(int i=0;i<m;i++)
		    scanf("%d%d%ld",&a[i],&b[i],&c[i]);
		int longest=0;
		for(int i=1;i<m;i++){
			if(a[longest]<a[i])
			    longest=i;
			if(a[longest]==a[i]){
				if(b[longest]>b[i])
				   longest=i;
				else if(b[longest]==b[i]){
					if(c[longest]<c[i])
					   longest=i;
				}
			}
		}
		printf("%ld\n",c[longest]);
	}
	return 0;
}
