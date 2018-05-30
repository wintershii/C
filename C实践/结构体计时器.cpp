#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct clock{                                                     // 结构体的定义 
	int hours;
	int minutes;
	int seconds;
};

void display(struct clock t){                                     //显示当前时间 
	printf("\r%02d:",t.hours);
	printf("%02d:",t.minutes);
	printf("%02d",t.seconds);
}

struct clock update(struct clock t){                              //更新时间，60秒进1分，60分进1时，24时后归零 
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
   Sleep(1000);                                                    //休眠函数   括号内1000代表休眠时间为1000ms 即1秒 
   return t;
}

int main(){
	struct clock cl={0,0,0};
	char ch;
	printf("按E开始计时\n");
	printf("按S停止计时\n");
	display(cl);
	ch=getch();
	while(1){
		if(ch=='e'||ch=='E'){
			cl=update(cl);
			display(cl);
			if(kbhit()){                                           //判断是否有键盘录入的函数，若有，则返回1，没有返回0； 
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
