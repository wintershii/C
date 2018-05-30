#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char a[101];
		scanf("%s",a);
		int count=0;
		int s=strlen(a);
		if(s==2&&a[0]!=a[1]){
			printf("2\n");
			return 0;
		}
		if(s%2!=0){
			printf("%d\n",s);
			return 0;
		}
		while(1){
			s/=2;
			for(int i=0;i<s;i++)
		       if(a[i]!=a[2*s-i-1]){
		       	 count=1;
		       	 break;
			   }
			if(count==1){
				printf("%d\n",2*s);
				break;
			}
		}
	}
	return 0;
}
