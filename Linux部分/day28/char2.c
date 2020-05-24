#include<myLibrary.h> 
int main(int argc, char *argv[]){
    ARGC_CHECK(argc,3);
    int fdr = open(argv[1],0_WRONLY);
    //1.pipe的写端
    int fdw = open(argv[2],0_OPONLY);
    //2.pipe的读端
    ERROR_CHECK(fdr,-1,"open 4");
    printf("i am char2 fdr %d fwd = %d",fdr,fdw);
    char buf[1024] = {0};
	while(1)
    {
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,sizeof(buf));
        //从键盘读取，以换行结尾
        write(fdw,buf,strlen(buf)-1);
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        //从管道中读取
        puts(buf);
    }
    char buf[128]={0};
    read(fdr,buf,sizeof(buf));
    printf("buf = %s\n",buf);
 	return 0； 
}

