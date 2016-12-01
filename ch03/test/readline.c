/*************************************************************************
	> File Name: readline.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年12月01日 星期四 15时53分59秒
 ************************************************************************/

#include "../my_unp.h"

//very slow
ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t n, rc;
	char c, *ptr;
	ptr = vptr;
	for(n = 1; n < maxlen; n++)
	{
again:
		if( 1 == (rc = read(fd, &c, 1)))
		{
			*ptr++ = c;
			if('\n' == c)
				break;			//读到'\n'为止
		}
		else if(0 == rc)		//EOF
		{
			*ptr = 0;
			return (n - 1);
		}
		else
		{
			if(EINTR == errno)
				goto again;
			return (-1);
		}
	}
	*ptr = 0;
	return (n);
}
//为什么会慢因为使一个字节一个字节读的。
ssize_t
Readline(int fd, void *ptr, size_t maxlen)
{
	ssize_t n;
	if( (n = readline(fd, ptr, maxlen)) < 0)
		err_sys("readline error");
	return (n);
}
