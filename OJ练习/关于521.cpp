#include<stdio.h>
int c[1000000]={0},f[1000000]={0};
int main(){
    int b[100]={0};
    int a,d,i,j,Q,W,E,m,w,x,t=1,s,F,X;
    for(i=100;i<1000000;i++){
        s=i;w=0;
        c[i]=c[i-1];
        f[i]=f[i-1];
       while(s){
        b[w]=s%10;
        s=s/10;
        w++;
       }
       Q=0;W=0;E=0;F=0;
      for(s=0;s<w;s++){
         if(b[s]==5)
            Q++;
         if(b[s]==2)
            W++;
         if(b[s]==1)
            E++;
         if(b[s]==1&&b[s+1]==2&&b[s+2]==5){
            F++;
         }
      }
      if(Q!=0&&W!=0&&E!=0){
         c[i]++;
      }
      if(F!=0){
         f[i]++;
       }
    }
    while(scanf("%d %d",&a,&d)!=EOF){
          printf("Case %d:%d %d\n",t++,c[d]-c[a-1],f[d]-f[a-1]);
}
    return 0;
}
