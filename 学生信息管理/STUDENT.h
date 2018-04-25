#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int now1_student();
int now2_student();
struct student *read();
struct student *read_score();
void save(struct student *pHead);
void save_score(struct student *pHead);
int _ifblank(char judge[]);
struct student *Creat();
void print();
void Insert();
void Delete();
void seek();
void stu_seek();
void student_();
int start(); 
int checkkey(char user[],char key[]);
void secretword(char key[]);
void enter();
int manager();
void tea_enter();
void teacher(); 
int t_checkkey(char user[],char key[]);
void new_teacher();
void print_tea();
struct student *scanf_score();
void print_score();
void change_score();
void sort_score();
void score_seek(); 

struct infomation{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
};

struct grade{
	int math;
	int english;
	int c;
};     

struct student{
	struct infomation stu;
	struct grade gra;
	struct student *next;
};

