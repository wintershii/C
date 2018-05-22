#include<stdio.h>
#include<string.h>
int main(){
	int n;
	int a[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	int b[26]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26};
	scanf("%d",&n);
	while(n--){
		char word;
		int num1,num2;
		getchar();
		scanf("%c",&word);
		scanf("%d",&num2);
		if(word>='A'&&word<='Z')
		    num1=a[word-'A'];
		else if(word>='a'&&word<='z')
		    num1=b[word-'a'];
		int sum=num1+num2;
		printf("%d\n",sum);
	}
	return 0;
} 
