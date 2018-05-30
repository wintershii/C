#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		char num[1001][6];
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		   scanf("%s",num[i]);
	    
		int min=0;
		for(int i=0;i<m;i++)
		    if(strcmp(num[min],num[i])>0)
		       min=i;
		printf("%s\n",num[min]);
	}
	return 0;
}
