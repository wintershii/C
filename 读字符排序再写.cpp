#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main(){
	FILE *fp;
	int i,j,count1,count;
	char string[101],t,ch;
	fp=fopen("D:\\test\\string1.txt","rt");
	if(fp==NULL){
		printf("���ܴ򿪴��ļ���\n");
	    exit(1); 
	}
	printf("string1.txt�е��ַ�Ϊ��\n");
	for(i=0;(ch=fgetc(fp))!=EOF;i++){
		string[i]=ch;
		putchar(string[i]); 
	}
	fclose(fp);
	count1=i;
	fp=fopen("D:\\test\\string2.txt","rt");
	if(fp==NULL){
		printf("���ܴ򿪴��ļ���\n");
	    exit(1); 
	}
	printf("\nstring2.txt�е��ַ�Ϊ��\n");
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
	  printf("\n�ַ�������д��string.txt��\n");
	  fclose(fp);
	return 0;
} 
