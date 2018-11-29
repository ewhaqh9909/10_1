#include <stdio.h>
#include <stdlib.h>

int is_whitespace(char c)
{
	if(c ==' '||
	   c =='\t'||
	   c =='\n'||
	   c =='\r'||
	   c ==')'||
	   c =='(')
	return 1;//공백글자다
	
	
	return 0;//유의미한 글자다 
 } 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fget_word(FILE* fp, char* word)
{	
	char c;
	while((c=fgetc(fp))!=EOF)
	{
		if(is_whitespace(c)==0)
		break;
	}
	if(c==EOF)
	{
		return 0;
	}
	int cnt;

	cnt=0;
	word[cnt++]=c;
	word[cnt]='\0'; //혹시 뒤에서 못 읽을 수 있으므로(한글자짜리 단어) 
	
	while((word[cnt]=fgetc(fp))!=EOF)
	{
		if(is_whitespace(word[cnt])==1)
		{
			word[cnt]='\0';
			break;
		}
		cnt++;
	}
	
	return cnt;
}

int main(int argc, char *argv[]) {
	FILE* fp;
	char name[100];
	char word[100];
	
	printf("input the file name :");
	scanf("%s",name);
	
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		printf("\n열수 없습니다.\n");
		exit(1);
	}
	
	while(fget_word(fp,word)!=0)
	{
		printf("%s\n",word);
	}
	fclose(fp);
	return 0;
}
