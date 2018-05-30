#include <stdio.h>
#include <string.h>
#define maxn 110
char buf[110];
int main(){
	int sign,left,dot,i,len;
	char *ch;
	while(scanf("%s", buf + 1) != EOF){         //buf字符数组从下标为一的元素开始录入 
		sign = 0;
		buf[0] = '0';                           //给字符数组的 下标为零的元素赋'0' 
		if(buf[1] == '-') {                     //判断正负 
			sign = 1;
			buf[1] = '0';
		}
		len = strlen(buf);                      //len表示整个数据的长度 
		if(ch = strchr(buf, '.')) {             //strchr()用来查找在字符串中 字符第一次出现的位置 失败返回NULL 
		dot = ch - buf;                         //对指针进行算数运算，dot代表不含小数部分的长度 
		} 
		else dot = len;
		if(len - dot > 3) {                      //小数部分  大于两位时情况 
			if(buf[dot+3] > '4') {                  //第三位小数大于等于5时 
				if(++buf[dot+2] > '9'){                //第二位小数可以进位时 
					buf[dot+2] = '0';                    //第二位归零 
					if(++buf[dot+1] > '9') {              //当第一位小数可以进位时 
						buf[dot+1] = '0';                   //第一位归零 
						++buf[dot-1];                   //给个位加一 
					}
				}
				i = dot - 1;                          //  给i 赋个位的位置 
				while(buf[i] > '9'){                     //整数部分的进位 
					buf[i--] = '0';
					++buf[i];
				}
			}
			buf[dot+3] = '\0';                      //小数两位后结束字符串 
 		} 
		else if(len - dot == 2){                  //当正好有一位小数时 
				buf[len++] = '0';                  //小数后补'0' 
				buf[len] = '\0';                   //结束字符串 
		} 
		else if(len - dot == 1) {                  //没有小树时 
				buf[len++] = '0';
				buf[len++] = '0';
				buf[len] = '\0';
		} 
		else if(len - dot == 0){                   //没有点时 
				buf[len++] = '.';                 //加点，补两位0 
				buf[len++] = '0';
				buf[len++] = '0';
				buf[len] = '\0';
		}
		for(left = 0; buf[left] == '0'; ++left);       //跳过字符数组前面的'0' 
			if(buf[left] == '.') --left;            //若第一位就是'.' 
			if(sign) putchar('(');                // 负数时输出( 
		while(left < dot) {                  //依次输出 整数部分 
			putchar(buf[left++]);
			if(left != dot && (dot - left) % 3 == 0)   //当下一位不是'.'，并且点到当前位置的差能被3整除时，输出',' 
				putchar(',');
		}
		printf("%s", buf + dot);                      //输出小数点和小数部分 
		if(sign) putchar(')');
			putchar('\n');
		}
	return 0;
}
