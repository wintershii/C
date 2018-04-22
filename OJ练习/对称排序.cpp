#include<stdio.h>
#include<string.h>

int main(){
	int m;
	int index=1;
	while(~scanf("%d",&m)&&m!=0){
		char a[20][30];
		int b[20];
		char temp[30];
		for(int i=0;i<m;i++)
		   scanf("%s",a[i]);
		for(int i=0;i<m;i++)
		    b[i]=strlen(a[i]);
		
		for(int i=0;i<m/2;i++){
			int min1=i,min2=i;
		    for(int j=i+1;j<m;j++)	
			   if(b[min1]>b[j])
			      min1=j;
			for(int j=i+1;j<m;j++)
			    if(b[min2]>b[j]&&b[j]>b[min1])
				   min2=j;
		    strcpy(temp,a[min1]);
		    strcpy(a[min1],a[i]);
		    strcpy(a[i],temp);
			strcpy(temp,a[min2]);
		    strcpy(a[min2],a[m-i-1]);
		    strcpy(a[m-i-1],temp);
		}
		printf("SET %d\n",index++);
		for(int i=0;i<m;i++)
		   printf("%s\n",a[i]);
	}
	return 0;
}
