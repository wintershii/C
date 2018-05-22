#include<stdio.h>
  int a[10][10];
  int sum=0;
int judge(int r,int c)
  {

    for(int i=0;i<8;i++)
   {
       if(a[i][c])
      return 0;
    }
 for(int i=r,j=c;i>=0&&j>=0;i--,j--)
   {
     if(a[i][j])
     return 0;
   }
   for(int i=r,j=c;i>=0&&j<8;i--,j++)
  {
    if(a[i][j])
    return 0;
   }
     return 1;


 }
 void queen(int r)
  {
    if(r==8)
      {
       sum++;
        return;
      }
    for(int i=0;i<8;i++)
  {
     if(judge(r,i))
    {
     a[r][i]=1;
     queen(r+1);
     a[r][i]=0;
    }
 }


}
int main()
{
    queen(0);
    printf("%d\n",sum);
    return 0;
}
