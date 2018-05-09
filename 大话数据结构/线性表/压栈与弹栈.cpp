#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	int date[MAX];
	int top;
}SqStack;

SqStack *InitStack(SqStack *stack){
	stack = (SqStack *)malloc(sizeof(SqStack));
	stack->top = -1;
	printf("初始化成功！\n");
	return stack;
}     

void push(SqStack *stack){
	int index = ++stack->top;
	if(index == MAX-1){
		printf("目前栈满！\n");
		return;
	}
	printf("请输入要压栈的数据：");
	scanf("%d",&stack->date[index]);
	printf("压栈成功！\n");
}

void pop(SqStack *stack){
	printf("%d\n",stack->top);
	int index = stack->top;
	if(index == -1){
		printf("目前为空栈!\n");
		return;
	}
	printf("要弹栈的数据为：%d ",stack->date[index]);
	stack->top--;
	printf("弹栈成功！\n");
}

void print_stack(SqStack *stack){
	printf("%d\n",stack->top);
	int index = stack->top;
	if(index == -1 ){
		printf("目前为空栈!\n");
		return;
	}
	for(int i = 0; i <= index; i++){
		printf("第%d个数据为：",i+1);
		printf("%d\n",stack->date[i]);
	}
}

int main(){
	SqStack *stack;
	stack = InitStack(stack);
	int choice = -1;
	while(choice != 0){
		printf("1. 压栈\n");
		printf("2. 弹栈\n");
		printf("3. 输出\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: push(stack);
				break;
			case 2: pop(stack);
				break;
			case 3: print_stack(stack);
				break;
		}
	}
	return 0;
} 
