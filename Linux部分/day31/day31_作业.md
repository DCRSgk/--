### 1、通过fork创建子进程，让父子进程都打印pid，都处于while(1),然后用ps进程查看，查看完毕，用kill命令杀掉

- ![image-20200417195813435](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417195813435.png)

- ![image-20200417195751413](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417195751413.png)

- kill杀死子进程之后父进程变成僵尸进程（未写wait语句）

### 2、能够得到孤儿进程；

- ![image-20200417201642763](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417201642763.png)
- ![image-20200417201702012](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417201702012.png)
- 孤儿进程被init接收

- 上文用kill杀死父进程之后子进程变成孤儿进程（未写wait语句）

### 3、通过fork创建进程，能够产生僵尸进程；

- ![image-20200417195813435](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417195813435.png)
- ![image-20200417195751413](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417195751413.png)
- kill杀死子进程之后父进程变成僵尸进程（未写wait语句）

### 4、通过fork创建子进程，然后父进程通过wait回收，同时拿到子进程的返回值

- ![image-20200417223001695](C:\Users\GK\AppData\Roaming\Typora\typora-user-images\image-20200417223001695.png)

### 5、通过execl拉起来一个add进程，并给其传参3和4，让其求和最终得到7

- 

附加作业：

### 1、验证ps显示的是有效用户ID，还是真实用户ID

- 有效用户id：真正执行程序的用户ID
- 真实用户id：真正执行程序的用户ID
- 

2、验证sudo里边是使用了setuid，还是seteuid

- sudo内用了setuid
- 查阅文档得知sudo通过`/etc/sudoers`配置文件确定用户是否有获得root权限的资格；如果有，则给调用程序设置`sticky`标识，这样用户就能运行程序了；最后，再去掉`sticky`标识（sudo命令只对一条命令有效）

