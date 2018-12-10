#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char a[101];
		scanf("%s",a);
		for(int i = 0; i < strlen(a); i++)
		    if(a[i] >= 'a'&&a[i] <= 'z')
		        a[i] -= 32;
		    else if(a[i]>='A'&&a[i]<='Z')
		        a[i] += 32;
		printf("%s\n",a);
	}
	return 0;
}
