/*************************************************************************
	> File Name: wrapinet.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年12月06日 星期二 15时15分43秒
 ************************************************************************/

#include "my_unp.h"

const char*
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
	const char *ptr;
	if(NULL == strptr)
		err_quit("NULL 3rd argument to inet_ntop");
	if( NULL == (ptr = inet_ntop(family, addrptr, strptr, len)))
		err_sys("inet_ntop error");
	return (ptr);
}


void 
Inet_pton(int family, const char *strptr, void *addrptr)
{
	int n;

	if( (n = inet_pton(family, strptr, addrptr)) < 0)
		err_sys("inet_pton error for %s", strptr);
	else if(0 == n)
		err_quit("inet_pton error for %s", strptr);
	//nothing to return 
}
