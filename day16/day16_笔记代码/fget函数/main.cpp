#include<cstdio>
#include<cstdlib>
#include<string>
int main(int argc,char *argv[])
{
	FILE* fp;
	char buf[1024];
	if (argc != 2)
	{
		printf("error args\n");
	}
	fp = fopen(argv[1], "r+");
	if (NULL == fp)
	{
		perror("fopen");
		goto error;
	}
	while (fgets(buf,sizeof(buf),fp)!=NULL)
	{
		//printf("%s", buf);
		buf[0] -= 32;
		if (buf[strlen(buf)-1] == '\n')  //�ַ����а���\n
		{								 //��Ҫ��ǰ��ƫ��һ���ַ�
			fseek(fp, -strlen(buf - 1), SEEK_CUR);
		}
		else
		{
			fseek(fp, -strlen(buf), SEEK_CUR);
		}
		fputs(buf, fp);
		fseek(fp, 0, SEEK_CUR);
	}
error:
	system("pause");
}