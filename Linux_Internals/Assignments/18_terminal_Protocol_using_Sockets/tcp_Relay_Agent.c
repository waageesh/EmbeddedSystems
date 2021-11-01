/*
Title   : TCP Relay Agent to route request from Client to corresponding Server
Author  : Vaageesh
Date    : Thursday 21 January 2021 07:34:49 PM IST
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_IP       "127.0.0.1"
#define SERVER_PORT 	5000

#define SERVER1_PORT 	5001
#define SERVER2_PORT 	5002
#define SERVER3_PORT 	5003
#define SERVER4_PORT 	5004
#define SERVER5_PORT 	5005

#define SERVER_LENGTH 	10
#define SERVER_BUFF	20

int main()
{

    int sock_fd, data_sock_fd,buffer_len;
    struct sockaddr_in serv_addr; 
    char serv_buffer[2];
    //char op[][2] = {"+", "-", "*", "/", "%"};
    int server_port;

    printf("Relay Agent Server is waiting...\n");

    /* Create a TCP socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* Bind it to a particular IP address & port) */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT); 

    bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    /* listen for incoming connections */
    listen(sock_fd, SERVER_LENGTH);

    /* If there are any, accept and create a new data socket */
    data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL); 

    memset(serv_buffer, 0, sizeof(serv_buffer));
    /* Try to get some actual data from client */
    recv(data_sock_fd, (void *) serv_buffer,SERVER_BUFF,0);

    /* Print the data received from client */
    printf("Here is the client data: %s\n",serv_buffer);
    
    /* send back the corresponding servers port address(as this is loppback ipaddress, port alone is enough)*/
    if (!strcmp(serv_buffer,"+"))
    {
    	server_port = SERVER1_PORT;
	printf("choosing server1 with port %d\n", server_port);
	send(data_sock_fd, (void*)&server_port, sizeof(server_port), 0);
    }
    else if (!strcmp(serv_buffer,"-"))
    {
    	server_port = SERVER2_PORT;
	printf("choosing server2 with port %d\n", server_port);
	send(data_sock_fd, (void*)&server_port, sizeof(server_port), 0);
    }
    else if (!strcmp(serv_buffer,"*"))
    {
    	server_port = SERVER3_PORT;
	printf("choosing server3 with port %d\n", server_port);
	send(data_sock_fd, (void*)&server_port, sizeof(server_port), 0);
    }
    else if (!strcmp(serv_buffer,"/"))
    {
    	server_port = SERVER4_PORT;
	printf("choosing server4 with port %d\n", server_port);
	send(data_sock_fd, (void*)&server_port, sizeof(server_port), 0);
    }
    else if (!strcmp(serv_buffer,"%"))
    {
    	server_port = SERVER5_PORT;
	printf("choosing server5 with port %d\n", server_port);
	send(data_sock_fd, (void*)&server_port, sizeof(server_port), 0);
    }
        	
    /* Close the sockets now */
    close(data_sock_fd);
    close(sock_fd);
}






