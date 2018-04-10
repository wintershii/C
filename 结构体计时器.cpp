#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct clock{
	int hours;
	int minutes;
	int seconds;
};

void display(struct clock t){
	printf("\r%02d:",t.hours);
	printf("%02d:",t.minutes);
	printf("%02d",t.seconds);
}

struct clock update(struct clock t){
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
   Sleep(1000);
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
			if(kbhit()){
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
