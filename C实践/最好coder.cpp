#include<stdio.h>
int main(){
	int n;
	int a[1001],b[1001],c[1001];
	while(~scanf("%d",&n)&&n != 0){
	   for(int i = 0; i < n; i++){
	      scanf("%d%d",&a[i],&b[i]);
	        c[i] = a[i] + b[i];
        }
        int max = 0;
        for(int i = 0; i < n; i++)
            if(c[max]<c[i])
               max=i;
        printf("%d\n",c[max]);

    }
    	return 0;
}
