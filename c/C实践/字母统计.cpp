#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a[26]={0};
		char word[1011];
		getchar();
		scanf("%s",word);
		for(int i=0;i<strlen(word);i++){
			int q=word[i]-'a';
			a[q]++;
		}
		int max=0;
		for(int i=0;i<26;i++){
			if(a[max]<a[i])
			   max=i;
			}
			printf("%c\n",'a'+max);
		}
			return 0;
}

