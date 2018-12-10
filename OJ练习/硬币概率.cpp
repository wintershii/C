#include<stdio.h>
#include<string.h>
int main(){
	int n,i;
	scanf("%d",&n);
	getchar();
	char word[65536];
	for(i=0;i<n;i++)
	  word[i]=getchar();
	  int u=0,d=0,s=0;
	for(i=0;i<n;i++){
		if(word[i]=='U')
		   u++;
		else if(word[i]=='D')
		   d++;
		else if(word[i]=='S')
		   s++;
	}
	if(s>0){
	   printf("Bingo\n");
	   return 0;
     }
    float p=1.0*u/(u+d);
    if(p>=0.497&&p<=0.503)
       printf("1/2\n");
    else
       printf("Fail\n");
    	
	return 0;
}
