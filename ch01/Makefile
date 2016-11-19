all:daytimetcpcli daytimetcpcli1 daytimetcpcli2  daytimetcpcli3 daytimetcpsrv daytimetcpsrv1
daytimetcpcli:daytimetcpcli.c error.c
	gcc -o daytimetcpcli daytimetcpcli.c error.c
daytimetcpcli1:daytimetcpcli1.c error.c
	gcc -o daytimetcpcli1 daytimetcpcli1.c error.c
daytimetcpcli2:daytimetcpcli2.c error.c
	gcc -o daytimetcpcli2 daytimetcpcli2.c error.c
daytimetcpcli3:daytimetcpcli3.c error.c
	gcc -o daytimetcpcli3 daytimetcpcli3.c error.c

daytimetcpsrv:daytimetcpsrv.c wrapsock.c error.c
	gcc -o daytimetcpsrv daytimetcpsrv.c wrapsock.c error.c
daytimetcpsrv1:daytimetcpsrv1.c wrapsock.c error.c
	gcc -o daytimetcpsrv1 daytimetcpsrv1.c wrapsock.c error.c 
clean:
	rm -rf daytimetcpcli daytimetcpcli1 daytimetcpcli2 daytimetcpcli3 daytimetcpsrv daytimetcpsrv1

