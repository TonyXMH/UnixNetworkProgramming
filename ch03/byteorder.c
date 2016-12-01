/*************************************************************************
	> File Name: byteorder.c
	> Author: tony
	> Mail: 445241843@qq.com 
	> Created Time: 2016年11月30日 星期三 21时57分25秒
 ************************************************************************/
//judge system is which kind. big-endian or little-endian
#include<stdio.h>
#include<stdlib.h>
#define CPU_VENDOR_OS	"sparc64-redhat-centos"

int main(int argc, char **argv)
{
	union
	{
		short	s;
		char	c[sizeof(short)];
	} test;
	printf("%s\n", CPU_VENDOR_OS);
	test.s = 0x0102;
	if(2 == sizeof(short))
	{
		if(test.c[0] == 1 && test.c[1] == 2)
			printf("big-endian\n");
		else if(test.c[0] == 2 && test.c[1] == 1)
			printf("little-endian\n");
		else
			printf("unknow\n");
	}
	else
	{
		printf("sizeof(short) = %d\n", sizeof(short));
	}
	exit(0);
}
