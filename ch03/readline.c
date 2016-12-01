/*************************************************************************
	> File Name: readline.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年12月01日 星期四 16时16分12秒
 ************************************************************************/

#include "my_unp.h"

static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];

static ssize_t
my_read(int fd, char *ptr)
{
	if(read_cnt <= 0)
	{
again:
		if( (read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0)	//先从fd中读取一段出来
		{
			if(EINTR == errno)
				goto again;
			return (-1);
		}
		else if(0 == read_cnt)
			return (0);
		read_ptr = read_buf;
	}
	read_cnt--;
	*ptr = *read_ptr++;
	return (1);
}

ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t n, rc;
	char c, *ptr;
	ptr = vptr;
	for(n = 1; n < maxlen; n++)
	{
		if( 1 == (rc = my_read(fd, &c)))
		{
			*ptr++ = c;
			if('\n' == c)
				break;
		}
		else if(rc == 0)	//EOF
		{
			*ptr = 0;
			return(n - 1)
		}
		else
			return (-1);
	}
	*ptr = 0;
	return (n);
}

ssize_t
readlinebuf(void **vptrptr)
{
	if(read_cnt)
		*vptrptr = read_ptr;
	return (read_cnt);
}

ssize_t
Readline(int fd, void * ptr, size_t maxlen)
{
	ssize_t n;
	if( (n = readline(fd, ptr, maxlen)) < 0)
		err_sys("readline error");
	return (n);
}
