#include<stdio.h>
#include<math.h>
#define MAX 8

int queen[MAX];
int sum = 0;

void print_queen(){
	int row;
	printf("解法%d:",sum+1);
	for(row = 0; row < MAX; row++){
		printf("(%d %d) ",row,queen[row]);
	}
	printf("\n");
	sum++;
}

int check(int n){
	int row;
	for(row = 0; row < n; row++){
		if(queen[row] == queen[n] || abs(queen[row] - queen[n]) == (n-row))
			return 1;
	}
	return 0;
}

int solve(int n){
	int col;
	for(col = 0; col < MAX; col++){
		queen[n] = col;
		if(!check(n)){
			if(n == MAX - 1)
				print_queen();
			else
				solve(n+1);
		}
	}
}

int main(){
	solve(0);
	printf("共有%d种解法\n",sum);
	return 0;
} 
