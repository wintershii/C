#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct clock{                                                     // �ṹ��Ķ��� 
	int hours;
	int minutes;
	int seconds;
};

void display(struct clock t){                                     //��ʾ��ǰʱ�� 
	printf("\r%02d:",t.hours);
	printf("%02d:",t.minutes);
	printf("%02d",t.seconds);
}

struct clock update(struct clock t){                              //����ʱ�䣬60���1�֣�60�ֽ�1ʱ��24ʱ����� 
   t.seconds++;
	if(t.seconds==60){
		t.minutes++;
		t.seconds=0;
	}
	if(t.seconds==60){
		t.hours++;
		t.minutes=0;
	}
	if(t.hours==24)
	    t.hours=0;
   Sleep(1000);                                                    //���ߺ���   ������1000��������ʱ��Ϊ1000ms ��1�� 
   return t;
}

int main(){
	struct clock cl={0,0,0};
	char ch;
	printf("��E��ʼ��ʱ\n");
	printf("��Sֹͣ��ʱ\n");
	display(cl);
	ch=getch();
	while(1){
		if(ch=='e'||ch=='E'){
			cl=update(cl);
			display(cl);
			if(kbhit()){                                           //�ж��Ƿ��м���¼��ĺ��������У��򷵻�1��û�з���0�� 
				ch=getch();
				if(ch=='s'||ch=='S')
				 break;
			}
	    }
		 else if(ch=='s'||ch=='S')
		   break;
		 else
		     ch=getch();
	}
	return 0;
}
