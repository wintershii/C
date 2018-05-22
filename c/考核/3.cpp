#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 10

int main(int argc,char **argv)
{
	char name1[20],name2[20];
	char c;
	gets(name1);
	gets(name2);
	FILE *fp,*ft;
	fp = fopen(name1,"rt");
	ft = fopen(name2,"wt+");
	while(fscanf(fp,"%c",&c) != EOF)
	{
		fprintf(ft,"%c",c);
	}
	fclose(fp);
	fclose(ft);
	return 0;
}

