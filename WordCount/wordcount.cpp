#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWord(char *file)
{
	int word=0,s=0;
	int zifu=0;
	FILE *fp = fopen(file, "r");
	char a;
	if(!fp)
	{
		printf("错误：文件读取失败\n");
	}
	else while(!feof(fp))
	{
		a = fgetc(fp);
		if((a >='a' && a <= 'z') || (a>='A' && a<='Z'))
		{
			s = 1;
		}
		else if(s)
		{
			word++;
			s=0;
		}
	}
	fclose(fp);
	printf("单词数 %d",word);
	return word;
}

int countZifu(char *file)
{
	int zifu=0;
	FILE *fp = fopen(file, "r");
	char a;
	if(!fp)
	{
		printf("错误：文件读取失败\n");
	}
	else while(!feof(fp))
	{
		a = fgetc(fp);
		if(a!=' ' && a!='\n' && a!='\t')
			zifu++;
	}
	fclose(fp);
	printf("字符数 %d",zifu);
	return zifu;
}

int main(int argc,char*argv[])
{
	FILE *f;
	while(1)
	{
		if((f = fopen(argv[2],"r"))==NULL)
		{
			printf("错误：文件读取失败\n");
			scanf("%s%s%s\n",argv[0],argv[1],argv[2]);
			continue;
		}
		else if(!strcmp(argv[1],"-w"))
			countWord(argv[2]);
		else if(!strcmp(argv[1],"-c"))
			countZifu(argv[2]);
		else 
			printf("NULL\n");
		scanf("%s%s%s\n",argv[0],argv[1],argv[2]);
	}
	return 0;
}