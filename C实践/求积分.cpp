#include<stdio.h>
#include<math.h>
 
float s(float x,float y,int a)
{
	float l,i;
	float sum = 0; 
	l = (x - y) / 50; 
	switch(a){ 
		case 1:
		for(i = 0; i < 50; i++)
			sum += sin(y + i*l + l/2);
			break; 
		case 2: 
		for(i = 0; i < 50; i++) 
			sum += cos(y + i*l + l/2);
			break; 
		case 3: 
		for(i = 0; i < 50; i++)
  			sum += exp(y + i*l + l/2);
  			break;
	}
	return sum*l;
}


int main()
{
	float a,b,c,d,n,m; 
	printf("���������Һ����Ļ���������(a,b)"); 
	scanf("%f %f",&a,&b);
	 
	printf("���������Һ����Ļ���������(c,d)"); 
	scanf("%f %f",&c,&d);
	
	printf("�������ݺ����Ļ���������(n,m)");
	scanf("%f %f",&n,&m);
	 
	printf("���һ��ֵĽ��Ϊ%.5f\n",s(a,b,1));
	printf("���Һ����Ļ��ֽ��Ϊ%.5f\n",s(c,d,2)); 
	printf("�ݺ����Ļ��ֽ��Ϊ%.5f\n",s(n,m,3));
	return 0;
}


