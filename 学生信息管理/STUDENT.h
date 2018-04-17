#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int now1_student();
struct student *read();
void save(struct student *pHead);
int _ifblank(char judge[]);
struct student *Creat();
void print();
void Insert();
void Delete();
void seek();
int start(); 
int checkkey(char key[]);
void secretword(char key[]);
