#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char a[1001];
		gets(a);
		int len=strlen(a);
		int count=0;
		for(int i=0;i<len;i++)
		    if(a[i]>='a'&&a[i]<='z')
		       count++;
		int c=count%26;
		if(c>=1&&c<=25)
		   printf("%c\n",'a'+c-1);
		else if(c==0)
		   printf("z\n");
	}
	return 0;
}
