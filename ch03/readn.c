/*************************************************************************
	> File Name: readn.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年12月01日 星期四 15时14分59秒
 ************************************************************************/
#include "my_unp.h"

//确保一定能够读取n个字节
ssize_t 
readn(int fd, void *vptr, size_t n)
{
	size_t	nleft;
	ssize_t nread;
	char	*ptr;
	ptr = vptr;
	nleft = n;
	while(nleft > 0)
	{
		if( (nread = read(fd, ptr, nleft)) < 0)
		{
			if(EINTR == errno)
				nread = 0;
			else
				return (-1);
		}
		else if(0 == nread)
			break;					//EOF
		nleft -= nread;
		ptr += nread;
	}
	return (n - nleft);
}

ssize_t
Readn(int fd, void *ptr, size_t nbytes)
{
	ssize_t n;
	if( (n = readn(fd, ptr, nbytes)) < 0)
		err_sys("readn error");
	return (n);
}
