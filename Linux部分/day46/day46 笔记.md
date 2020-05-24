# day46 笔记

## Ep01 进程池

- 编写方法：

  > - 定义清晰的数据结构
  > - 增量编写
  > - 父进程
  >   - 初始化子进程结构体数组，创建所有子进程，保存子进程信息到结构体数组（父进程内）
  >   - tpclnit初始化tpc协议，监听端口
  >   - 将socketFd和所有跟子进程通信的管道交给epoll监听
  >   - 等待连接，sfd就绪，accept拿到newFd，找到非忙碌的子进程，将newFd通过sendmsg传递给子进程，colse（newFd）将子进程标记为忙碌。（此时子进程自己去做分配的任务）
  >   - 加入子进程的管道描述符可读，代表任务完成，标记成非忙碌状态
  > - 子进程
  >   - recvFd读管道，说明无任务，阻塞
  >   - 如果可读吗，则读管道，拿到父进程传进来的newFd
  >   - 开始传输文件（干活）
  >   - 完成之后先断开close（newFd）
  >   - 写管道，通知父进程任务完成，继续读管道（进入阻塞，等待下一次任务）
  > - 下午复习dup机制

- procecc_pool.h

  ```c
  #include<myLibrary.h>
  typedef struct {
      pid_t pid;
      //进程id
      ind fd;
      //管道
      short busy;
      //子进程是否忙碌，忙碌为1
      
  }process_data;
  int makeChild.c(process_data_t* p,int processNum);
  int childHandle()
  int tcpInit(int *sfd,char* ip,char* port);
  ```

  

- 

- 父进程管理子进程的数据结构

  ```c
  int main(int argc,char*argv[])
  {
      ARGS_CHECK(argc,4);
      int prpcessNum = atoi(argv[3]);
      pricess_data_t *pData = (process_data_t*)calloc(processNum,sizeof);
      makeChlid(pData,processNum);
      tcpInit(&socketFd,argv[1],argv[2]);
      //传参
      int socketFd;
      tcpInit();
      
      int epfd;
      epfd = epoll_creat(1);
      ERROR_CHECK();
      epollInAdd(epfd,socketFd);
      
      close(fd);
      //相当于引用计数-1
      while(1);
                                                      
          
  }
  ```

- makeCilld.c(创建子进程)

  ```c
  int makeChild.c(process_data_t* p,int processNum)
  {
      int fds[2];
      int ret = 0;
      //管道
      pid_t = pid;
      for(int i = 0;i<processNum;i++)
      {
       
          
          ret = socketpair(AL_LOCAL_STREAM,0,fds);
          ERROR_CHECK(ret,-1,"socketpair Error")
          pid = fork();
          if(0 == pid)
          {
              close(fds[1]);
              childHandle(fds[0]);
          }
          close(fds[0]);
          p[i].busy = 0;
          p[i].pid = pid;
          p[i].pipefd = fds[1];
          //初始化
          /*printf("child%d pid = %d,pipe = %d",p[i].pid,p[i].pipefd);
          result:每个子进程的pid和管道
          */
      }   
  }
  
  ```

- 

- tcpInit.c

  ```c
  int tcpInit(int *sfd,char* ip,char* port)
  {
      int socketFd=socket(AF_INET,SOCK_STREAM,0);
      ERROR_CHECK(socketFd,-1,"socket Error");
      //printf("socketFd = %d",socketFd);
      struct sockaddr_in serAddr;  
      bzero(&serAddr,sizeof(serAddr));
      serAddr.sin_family=AF_INET;
      serAddr.sin_port=htons(atoi(port));
      serAddr.sin_addr.s_addr=inet_addr(ip);
      int ret;
      ret=bind(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
      ERROR_CHECK(ret,-1,"bind");
      listen(socketFd,10);
      *sfd=socketFd;
      return 0;
  }
  ```

- childHandle.c

  ```c
  int childHandle(int pipefd)
  {
      int newFd = 0;
      while(1)
      {
          recvFd(pipefd,&newFd);
          //假如管道不可读则阻塞
          printf("newFd = %d\n",newFd);
      }
  }
  ```

- sendFd.c

  ```c
  int sendFd
  ```

- epullInadd.c

  ```c
  int epullInadd(int epfd,int fd)
  {
      struct epull_event event;
      event.data.fd = fd;
      event.enents = EPOLLIN;
      int ret;
      ret = epoll_ctl(epfd,)
  }
  ```

- 

