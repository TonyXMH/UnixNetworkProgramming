/*************************************************************************
	> File Name: writen.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年12月01日 星期四 15时42分29秒
 ************************************************************************/

#include "my_unp.h"

//这里我本来有点糊涂的，const void * 
//但是仔细想想，我们是将vptr所指向的内存的内容写入fd，
//所以用const保护数据不被修改很合理
ssize_t
writen(int fd, const void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;
	ptr = vptr;
	nleft = n;
	while(nleft > 0)
	{
		if( (nwritten = write(fd, ptr, nleft)) <= 0)
		{//写情况不存在EOF
			if(EINTR == errno && nwritten < 0)
				nwritten = 0;
			else
				return (-1);
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return n;
}

void Writen(int fd, void *ptr, size_t nbytes)
{
	if(writen(fd, ptr, nbytes) != nbytes)
		err_sys("writen error");
}
