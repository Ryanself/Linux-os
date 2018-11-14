#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 10
static volatile int loop = 0;

static void alarm_handler (int s)
{
	alarm(1);
	loop = 0;
}

int main (int argc, char **argv)
{
	int fd = -1;
	char buf[BUFSIZE] = "";
	ssize_t readsize = -1;
	ssize_t writesize = -1;
	size_t off = 0;

	if (argc < 2)
	{
		fprintf(stderr, "Usage %s <filepath>\n", argv[0]);
		fprintf(stderr, "使用方法： %s <文件>\n", argv[0]);
		return 1;
	}

	do{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0) {
			if (EINTR != errno) {
				perror("open()");
				goto e_open;
			}
		}
	} while  (fd < 0);

	loop = 1;
	signal(SIGALRM, alarm_handler);
	alarm(1);

	while(1) {
		while (loop) {
			pause();
		}
		loop = 1;

		while ((readsize = read(fd, buf, BUFSIZE)) < 0) {
			if (readsize < 0) {
				if (EINTR == errno) {
					continue;
				}
				perror("read()");
				goto e_read;
			}
		}
		if (!readsize)
		{
			break;
		}

		off = 0;
		do {
			writesize = write(1, buf + off, readsize);//可替换为 writesize = write(1, buf, readsize);
			off += writesize;//可注释掉此句
			readsize -= writesize;//readsize < writesize表示已经读完该文件 while退出
		} while (readsize > 0);
	}

	close(fd);

	return 0;
e_read:
	close(fd);
e_open:
	return 1;

}


/*
 *	ssize_t write(int fd,const void*buf,size_t count);
 *	参数说明：
 *	  fd:是文件描述符（write所对应的是写，即就是1）
 *	    buf:通常是一个字符串，需要写入的字符串
 *	      count：是每次写入的字节数
 *	返回值：
 *	 成功：返回写入的字节数
 *	  失败：返回-1并设置errno
 *	    ps： 写常规文件时，write的返回值通常等于请求写的字节
 *	           数count， 而向终端设备或者网络写时则不一定
 *
 *	ssize_t read(int fd,void*buf,size_t count)
 *	参数说明：
 *	fd:      是文件描述符
 *	buf:     为读出数据的缓冲区；
 *	count:   为每次读取的字节数（是请求读取的字节数，读上来的数据保
 *	         存在缓冲区buf中，同时文件的当前读写位置向后移）
 *
 *	返回值：
 *	 成功：返回读出的字节数
 *	  失败：返回-1，并设置errno，如果在调用read
 *	         之前到达文件末尾，则这次read返回0
 */
