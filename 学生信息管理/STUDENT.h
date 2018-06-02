#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct infomation{                                                   //学生学籍信息的结构体 
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
};

struct grade{                                                       //学生成绩信息结构体 
	int math;
	int english;
	int c;
}; 

struct student{                                                      //学生信息结构体 
	struct infomation stu;
	struct grade gra;
	struct student *next;
};

struct teacher{                                                      // 教师用户名与密码 
	char user[20];
	char key[20];
	struct teacher *next;
};
typedef struct teacher *node;                                         //自定义类型：指向教师结构体类型的指针类型 

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
void delete_tea();
int now_tea();
void changeteakey();
node read_t();
void save_t(node pHead);
void changemkey();
void gotoxy(int x, int y);
void moveselect();
void s_gets(char *word); 
void m_gets(char word[]);

