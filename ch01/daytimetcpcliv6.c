/*************************************************************************
	> File Name: daytimetcpcliv6.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月13日 星期日 21时02分24秒
 ************************************************************************/
//只改动一些ipv6的标识。
#include "my_unp.h"

int main(int argc, char ** argv)
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in6 servaddr;

	if(argc != 2)
		err_quit("usage: ./a.out <IPAddress>");
	if( (sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin6_family = AF_INET6;
	servaddr.sin6_port = htons(13);					//time service port
	if(inet.pton(AF_INET6, argv[1], &servaddr.sin_addr) < 0)
		err_quit("inet_pton error for %s\n", argv[1]);
	if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");
	while( (n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF)
			err_sys("read error");
	}
	if(n < 0)
		err_sys("read error");
	exit(0);
}

