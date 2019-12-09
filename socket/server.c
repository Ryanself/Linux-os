#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	serv_addr.sin_port = htons(1234);
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	listen(serv_sock, 20);
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	char ip[33];
	memset(&clnt_addr, 0, sizeof(clnt_addr));
	int a = getpeername(clnt_sock, (void *__restrict__)(struct sockaddr*)&clnt_addr, &clnt_addr_size);
	const char *ip3 = inet_ntop(AF_INET, &(clnt_addr.sin_addr), (void *__restrict__)&ip, sizeof(ip));
	printf("sock %d >>>>>>>%s>>>>>%s>>>>%d>>>>\n",clnt_sock, ip3, ip, a);
	char str[] = "hello world";
	write(clnt_sock, str, sizeof(str));

	memset(&clnt_addr, 0, sizeof(clnt_addr));
	close(clnt_sock);
	/*
	 * int b = getpeername(clnt_sock, (void *__restrict__)(struct sockaddr*)&clnt_addr, &clnt_addr_size);
	const char *ip4 = inet_ntop(AF_INET, &(clnt_addr.sin_addr), (void *__restrict__)&ip, sizeof(ip));
	printf("%s>>>>>%s>>>>%d>>>>\n", ip4, ip, b);
	ip4 = NULL; */
	close(serv_sock);
	return 0;
}
