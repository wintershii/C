#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		if(x>=90&&x<=100)
		   printf("A\n");
		else if(x>=80&&x<=89)
		   printf("B\n");
		else if(x>=70&&x<=79)
		   printf("C\n");
		else if(x>=60&&x<=69)
		   printf("D\n");
		else if(x>=0&&x<=59)
		   printf("E\n");
	}
	return 0;
}
