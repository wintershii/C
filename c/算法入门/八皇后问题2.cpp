#include<stdio.h>
#define MAX 8

int sum = 0;
int queen[MAX][MAX];

void print_queen(){
	printf("�ⷨ%d:",++sum);
	for(int row = 0; row < MAX; row++){
		for(int col = 0; col <MAX; col++){
			if(queen[row][col] == 1)
				printf("(%d %d) ",row,col);
		}
	}
	printf("\n");
}

int check(int row ,int col ){
	if(row == 0)
		return 0;
	
	for(int i=0;i<8;i++)				//�ж��ϱ� 
		if(queen[i][col] == 1)
			return 1;
	
	for(int i=row,j=col;i>=0&&j>=0;i--,j--)		//������� 
		if(queen[i][j] == 1)
			return 1;
	
	for(int i=row,j=col;i>=0&&j<8;i--,j++)	//������� 
		if(queen[i][j] == 1)
			return 1;
	
	return 0;
}

void solve(int row){
	if(row == MAX ){
		print_queen();
		return;
	}
	for(int i = 0; i < MAX; i++){
		if(!check(row,i)){
			queen[row][i] = 1;
			solve(row + 1);
			queen[row][i] = 0;
		}
	}
}

int main(){
	solve(0);
	printf("����%d�ֽⷨ:",sum);
	return 0;
}
