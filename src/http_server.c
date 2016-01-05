#include "head.h"

int main(int argc, char const *argv[])
{
//	if (argc < 2)
//	{
//		printf("Useage : .%s Port\n", argv[0]);
//		exit(1);
//	}

	u_short port = 8051; //端口

	struct sockaddr_in client_name; //客户端结构体
	socklen_t client_name_len = sizeof(client_name);

	int server_sock = startup(&port); //分配sock句柄并开始监听
	int client_sock;
	printf("httpd running on port %d\n", port);

	for (;;)
	{
		client_sock = accept(server_sock, (struct sockaddr *) &client_name,
				&client_name_len); //客户端sock
		if (client_sock == -1)                  //失败处理
		{
			printf("ERROR, receive failed!\n");
			continue;
		}
		process_request(client_sock); //接受客户端数据
		printf("done\n");
	}
	close(server_sock);
	return 0;
}
