#include<stdio.h>
#include<string.h>

int main(){
	int m;
	int i,j;
	int index = 1;
	while(~scanf("%d",&m)&&m != 0){
		char a[20][30],*p[20],*t;
		for( i = 0;i < m ; i++){
		   scanf("%s" , a[i]);
		   p[i] = a[i];
	    }
				
		for( i = 0;i < m-1; i++)
		    for( j = 0;j < m-i-1; j++)
		        if(strlen(p[j]) > strlen(p[j+1])){
		        	t = p[j];
		        	p[j] = p[j+1];
		        	p[j+1] = t;
				}
		printf("SET %d\n",index++);
		for( i = 0;i < m; i+=2)
		    printf("%s\n",p[i]);
		i==m?i--:(i-=3);
		for(i;i>0;i-=2)
		    printf("%s\n",p[i]);
		                
	}                                            
	return 0;
}
