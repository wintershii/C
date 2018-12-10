#include<stdio.h>
#include<string.h>
int main(){
	char a[4];
	int index=1;
	while(~scanf("%s",a)){
		printf("Case %d: ",index++);
			 if(strcmp(a,"I")==0)printf("1\n");
			if(strcmp(a,"II")==0)printf("2\n");
			if(strcmp(a,"III")==0)printf("3\n");
			if(strcmp(a,"IV")==0)printf("4\n");
			if(strcmp(a,"V")==0)printf("5\n");
			if(strcmp(a,"VI")==0)printf("6\n");
			if(strcmp(a,"VII")==0)printf("7\n");
			if(strcmp(a,"VIII")==0)printf("8\n");
			if(strcmp(a,"IX")==0)printf("9\n");
			if(strcmp(a,"X")==0)printf("10\n");
		    if(strcmp(a,"XI")==0)printf("11\n");
			if(strcmp(a,"XII")==0)printf("12\n");        
		}
		return 0;
	}
	
