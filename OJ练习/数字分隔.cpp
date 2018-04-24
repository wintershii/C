#include<stdio.h>
#include<string.h>
int main(){
	char a[101];	
	while(~scanf("%s",a)){
		int flag = 1;
		int len = strlen(a);
		if(a[0] == '-')
			   flag++;
		for(int i = 0; i < len; i++){
			if(a[0] == '0')
				for(int j = 0; j < len; j++){
					a[j] = a[j+1];
					len--;
				}
			if(a[i] == '.')
			    flag++;
		}
		if(flag == 1){
			for(int i = len-1; i >=0; i-=3){
				if(i <= 3)
				   break;
				a[i+1] = a[i];
				a[i] = a[i-1];
				a[i-1] = a[i-2];
				a[i-1] = ',';
				len++;
			}
		}
		printf("%s\n",a);
	}
	return 0;
}
