#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main(){
	FILE *fp;
	int i,j,count1,count;
	char string[101],t,ch;
	fp=fopen("D:\\test\\string1.txt","rt");
	if(fp==NULL){
		printf("不能打开此文件！\n");
	    exit(1); 
	}
	printf("string1.txt中的字符为：\n");
	for(i=0;(ch=fgetc(fp))!=EOF;i++){
		string[i]=ch;
		putchar(string[i]); 
	}
	fclose(fp);
	count1=i;
	fp=fopen("D:\\test\\string2.txt","rt");
	if(fp==NULL){
		printf("不能打开此文件！\n");
	    exit(1); 
	}
	printf("\nstring2.txt中的字符为：\n");
	for(i=count1;(ch=fgetc(fp))!=EOF;i++){
		string[i]=ch;
		putchar(string[i]);
	}
	fclose(fp);
	count=i;
	for(i=0;i<count;i++)
	  for(j=0;j<count-i-1;j++){
	  	if(string[j]>string[j+1]){
	  		t=string[j];
	  		string[j]=string[j+1];
	  		string[j+1]=t;
		  }
	  }
	  printf("\n%s",string);
	  fp=fopen("d:\\test\\string.txt","wt");
	  fputs(string,fp);
	  printf("\n字符已排序并写入string.txt中\n");
	  fclose(fp);
	return 0;
} 
