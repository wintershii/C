#include <stdio.h>
#include <string.h>
int main(){
	char word[128][21]={'\0'},ch;
	int words=0,i;    
	int startPos,spaces;  
	                  
	ch=getchar();
	while(ch!='\0'){  
		while(ch==' ') ch=getchar();
		i=0;
		while((ch!=' ')&&(ch!='\n')) {
			word[words][i++]=ch;
			ch=getchar();
		}
		word[words][i]='\0';
		words++;
	}
    startPos=0;
    
	for(i=0;i<words;i++){
		int length=0,curwords=0;    
								
		while(length<20 && i<words){ 
			length+=strlen(word[i]);
			if(length>20 || length+curwords>20) {
				length-=strlen(word[i]);break;
			}
			i++;curwords++;
		}
		i=i-1;

        if(curwords>1)   
			spaces=(20-length)/(curwords-1);	

		int j=startPos;  
		
		do{
			printf("%s",word[j]); 
			for(int k=0;k<spaces;k++) putchar(' ');  
		}while(++j<startPos+curwords-1);
	
		if(curwords>1) { 
			for(int k=0;k<(20-length)%(curwords-1);k++) putchar(' ');
			printf("%s",word[startPos+curwords-1]);
		}
		putchar('\n');	

		startPos+=curwords;  
	}
	return 0;
}

