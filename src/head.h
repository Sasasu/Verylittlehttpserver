/*
 * head.h
 *
 *  Created on: Jan 5, 2016
 *      Author: li
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int startup(u_short*);//建立sock并监听
void process_request(int);//处理连接
