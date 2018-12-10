#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c,d,e,f;
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=x;i<=y;i++){
        	f=i/100000;e=i%100000/10000;d=i%10000/1000;c=i%1000/100;b=i%100/10;a=i%10;
        	if(a>6||b>6||c>6||d>6||e>6||f>6||f==e&&d==e||e==d&&c==d||d==c&&b==c||c==b&&b==a||a-b>4||b-a>4||
			   b-c>4||c-b>4||c-d>4||d-c>4||d-e>4||e-d>4||e-f>4||f-e>4)
			     continue;
			else
			   printf("%06d\n",i);
		}
	}
	return 0;
}
