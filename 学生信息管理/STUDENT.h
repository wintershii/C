#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct infomation{                                                   //ѧ��ѧ����Ϣ�Ľṹ�� 
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
};

struct grade{                                                       //ѧ���ɼ���Ϣ�ṹ�� 
	int math;
	int english;
	int c;
}; 

struct student{                                                      //ѧ����Ϣ�ṹ�� 
	struct infomation stu;
	struct grade gra;
	struct student *next;
};

struct teacher{                                                      // ��ʦ�û��������� 
	char user[20];
	char key[20];
	struct teacher *next;
};
typedef struct teacher *node;                                         //�Զ������ͣ�ָ���ʦ�ṹ�����͵�ָ������ 

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

