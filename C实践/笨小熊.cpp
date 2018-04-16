#include<stdio.h>
#include<string.h>

int iszs(int x){                       //质数就是素数！！！ 
	if(x==2)
	    return 1;
	for(int i=2;i<x;i++){
		if(x%i==0)
		   break;
		return 1;
	}
	 return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char a[101];
		int b[26]={0};
		int c[26];
		int maxn,minn;
		scanf("%s",a);
		int len=strlen(a);
		for(int i=0;i<len;i++){
			int t=a[i]-'a';
			    b[t]++;
		}
		  int	k=0;
		for(int i=0;i<26;i++){
		    if(b[i]>0){
				c[k]=b[i];
		    	k++;
			}
			
		}
		maxn=c[0];minn=c[0];
		for(int i=0;i<k;i++){
			if(c[i]>maxn)  maxn=c[i];
		    if(c[i]<minn&&b[i]!=0)  minn=c[i];
		}
		    if(iszs(maxn-minn)){
		    	printf("Lucky Word\n");
		    	printf("%d\n",maxn-minn);
			}
			else{
				printf("No Answer\n");
				printf("0\n");
			}
	}
	return 0;
}
