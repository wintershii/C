#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char a,b;
		getchar();
		scanf("%c %c",&a,&b);
		if(a<b)
		  printf("%c>%c\n",a,b);
		else if(a==b)
		  printf("%c=%c\n",a,b);
		else if(a>b)
		  printf("%c<%c\n",a,b);
	}
	return 0;
}
