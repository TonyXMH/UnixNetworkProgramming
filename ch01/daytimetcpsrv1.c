/*************************************************************************
	> File Name: daytimetcpsvr.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月16日 星期三 15时27分22秒
 ************************************************************************/

#include "my_unp.h"
#include <time.h>

int main(int argc, char **argv)
{
	int listenfd, connfd, i;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9999);
	Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	for( ; ; )
	{
		connfd = Accept(listenfd, (SA*)NULL, NULL);
		ticks = time(NULL);
		snprintf(buff, sizeof(buff),"%.24s\r\n", ctime(&ticks));
//		Write(connfd, buff, strlen(buff));
		for(i = 0; i < strlen(buff); i++)
		{
			Write(connfd, &buff[i], 1);
		}
		Close(connfd);
	}
	return 0;
}
