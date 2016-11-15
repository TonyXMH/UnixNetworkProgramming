/*************************************************************************
	> File Name: my_unp.h
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月03日 星期四 11时27分32秒
 ************************************************************************/

#ifndef __MY_UNP_H
#define __MY_UNP_H

#include <sys/socket.h>						//basic socket definitions
#include <sys/types.h>						//basic system data types

#include <netinet/in.h>						//sockaddr_in {} and other Internet defins
#include <arpa/inet.h>						//inet(3) functions
#include <errno.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 4096						//max text line length
#define LISTENQ 1024						//the max number of listen queue.
#define SA struct sockaddr
void err_dump(const char *, ...);			//这5个函数都是调用err_doit()函数，只是其中的某些设置不同
void err_msg(const char *, ...);			//err_doit()是静态的所以不在头文件中。
void err_quit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);
//wrapsock
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Read(int fd, void *ptr, size_t nbytes);

//end wrapsock

#endif					//__MY_UNP_H
