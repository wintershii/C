#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void Circle(int map[][MAX],int m,int n)
{
	int i,j,t;
	int tmp[MAX][MAX];
	 for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            tmp[i][j] = map[j][i];
        }  //×ªÖÃ
        
    for(j = 0; j < m; j++)
    {
         for(i = 0; i < n/2; i++)
         {
                t = tmp[n-i-1][j];
                tmp[n-i-1][j] = tmp[i][j];
                tmp[i][j] = t;
         }
    } // ÄæÖÃ

    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            map[i][j] = tmp[i][j];
        }
        printf("\n");
    }
    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
	}
}

int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    int map[MAX][MAX];
    for(i = 0; i < m; i++)
        for(j = 0;j < n; j++)
            scanf("%d",&map[i][j]);
	Circle(map,m,n);
    Circle(map,m,n);
    Circle(map,m,n);
    Circle(map,m,n);
    return 0;
}
