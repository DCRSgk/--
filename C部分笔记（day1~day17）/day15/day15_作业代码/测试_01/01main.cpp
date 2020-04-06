#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;
int main()
{
    char c;
    int ret;
    FILE* fp;
    FILE* fpCount;
    fp = fopen("The_Holy_Bible.txt", "r+");
    fpCount = fopen("fail.txt", "r+");
    //可以为相对路径，也可以是绝对路径
    while ((c=fgetc(fp)!=EOF))
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = c + 32;
            fseek(fp, -1, SEEK_CUR);
            fputc(c, fp);
        }
        fseek(fp, 0, SEEK_CUR);
    }

error:
    cout << "open fail" << endl;
    fclose(fp);
    fclose(fpCount);
}
