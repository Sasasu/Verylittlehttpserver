#include "head.h"
int startup(u_short *port)
{
	struct sockaddr_in server_sock;
	memset(&server_sock, 0, sizeof(server_sock));
	int httpd = socket(PF_INET, SOCK_STREAM, 0);
	if (httpd == -1)
	{
		printf("ERROR,cna not open sock!\n");
		exit(1);
	}

	server_sock.sin_family = AF_INET;    // IPV4
	server_sock.sin_port = htons(*port); //主机字节序转换成网络字节序(short)
	server_sock.sin_addr.s_addr = htonl(INADDR_ANY); //主机字节序转换成网络字节序(long)

	if (bind(httpd, (struct sockaddr *) &server_sock, sizeof(server_sock)) < 0) //绑定sock地址
	{
		printf("ERROR,can not bind sock\n");
		exit(1);
	}
	if (listen(httpd, 10) < 0) //开始监听
	{
		printf("ERROR,can not listen port\n");
		exit(1);
	}
	return httpd;
}

void process_request(int client)
{
	char send_mes[30];
	sprintf(send_mes, "<h1>Hello!\r\n");
	printf("client connected sending mes");
	send(client, send_mes, strlen(send_mes), 0);
	close(client); //处理结束,关闭客户端连接
}
