#include <stdio.h>
#include <string.h>
#define maxn 110
char buf[110];
int main(){
	int sign,left,dot,i,len;
	char *ch;
	while(scanf("%s", buf + 1) != EOF){         //buf�ַ�������±�Ϊһ��Ԫ�ؿ�ʼ¼�� 
		sign = 0;
		buf[0] = '0';                           //���ַ������ �±�Ϊ���Ԫ�ظ�'0' 
		if(buf[1] == '-') {                     //�ж����� 
			sign = 1;
			buf[1] = '0';
		}
		len = strlen(buf);                      //len��ʾ�������ݵĳ��� 
		if(ch = strchr(buf, '.')) {             //strchr()�����������ַ����� �ַ���һ�γ��ֵ�λ�� ʧ�ܷ���NULL 
		dot = ch - buf;                         //��ָ������������㣬dot������С�����ֵĳ��� 
		} 
		else dot = len;
		if(len - dot > 3) {                      //С������  ������λʱ��� 
			if(buf[dot+3] > '4') {                  //����λС�����ڵ���5ʱ 
				if(++buf[dot+2] > '9'){                //�ڶ�λС�����Խ�λʱ 
					buf[dot+2] = '0';                    //�ڶ�λ���� 
					if(++buf[dot+1] > '9') {              //����һλС�����Խ�λʱ 
						buf[dot+1] = '0';                   //��һλ���� 
						++buf[dot-1];                   //����λ��һ 
					}
				}
				i = dot - 1;                          //  ��i ����λ��λ�� 
				while(buf[i] > '9'){                     //�������ֵĽ�λ 
					buf[i--] = '0';
					++buf[i];
				}
			}
			buf[dot+3] = '\0';                      //С����λ������ַ��� 
 		} 
		else if(len - dot == 2){                  //��������һλС��ʱ 
				buf[len++] = '0';                  //С����'0' 
				buf[len] = '\0';                   //�����ַ��� 
		} 
		else if(len - dot == 1) {                  //û��С��ʱ 
				buf[len++] = '0';
				buf[len++] = '0';
				buf[len] = '\0';
		} 
		else if(len - dot == 0){                   //û�е�ʱ 
				buf[len++] = '.';                 //�ӵ㣬����λ0 
				buf[len++] = '0';
				buf[len++] = '0';
				buf[len] = '\0';
		}
		for(left = 0; buf[left] == '0'; ++left);       //�����ַ�����ǰ���'0' 
			if(buf[left] == '.') --left;            //����һλ����'.' 
			if(sign) putchar('(');                // ����ʱ���( 
		while(left < dot) {                  //������� �������� 
			putchar(buf[left++]);
			if(left != dot && (dot - left) % 3 == 0)   //����һλ����'.'�����ҵ㵽��ǰλ�õĲ��ܱ�3����ʱ�����',' 
				putchar(',');
		}
		printf("%s", buf + dot);                      //���С�����С������ 
		if(sign) putchar(')');
			putchar('\n');
		}
	return 0;
}
