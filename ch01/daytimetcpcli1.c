/*************************************************************************
	> File Name: daytimetcpcli.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月04日 星期五 22时32分35秒
 ************************************************************************/

#include "my_unp.h"

int main(int argc, char **argv)
{

	int sockfd , n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	if(argc != 2)
		err_quit("usage: a.out <IPAddress>");
//	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//	ERRNO 97 ENOSUPPORT,没有支持的相关协议
//	errno.h /usr/include/asm-generic/errno.h
	if( (sockfd = socket(9999, SOCK_STREAM, 0)) < 0)
	{
		printf("errno:%d\n", errno);
		err_sys("socket error");
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);			//time server port
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0)
		err_quit("inet_qtin error for %s", argv[1]);
	if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
		err_quit("connect error");
//	printf("connect\n");
	while( (n =read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if(n < 0)
		err_sys("read error");

	exit(0);
}
