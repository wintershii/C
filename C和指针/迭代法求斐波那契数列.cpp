#include<stdio.h>

long fibonacci(int n){
	long result;
	long previous_result;
	long next_older_result;
	result = previous_result = next_older_result = 1;
	while(n > 2){
		n-=1;
		previous_result = next_older_result;
		next_older_result = result;
		result = previous_result + next_older_result;
	}
	return result;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%ld\n",fibonacci(n));
} 
