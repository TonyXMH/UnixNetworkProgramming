/*************************************************************************
	> File Name: wrapsock.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月14日 星期一 21时28分25秒
 ************************************************************************/

#incldue "my_unp.h"

int 
Accept(int fd, struct sockaddr *sa, socklen_t salenptr)
{
	int n;
	if( (n = accept(fd, sa, salenptr)) < 0)		
		err_sys("accept error");
	return n;
}

void 
Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

void 
Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(connect(fd, sa, salen) < 0)
		err_sys("connect error");
}

void 
Listen(int fd, int backlog)
{
	if(listen(fd, backlog) < 0)
		err_sys("listen error");
}

int 
Socket(int family, int type, int protocol)
{
	int n ;
	if( (n = socket(family, type, protocol)) < 0)
		err_sys("socket error");
	return n;
}
