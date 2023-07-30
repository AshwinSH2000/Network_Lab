#include<stdio.h> 
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>
#define myport 1234

#define MAXLINE 100
int main()
{
	int connfd = 0, size, n;
	char buffer[30];
	char reply[30];
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);	//socket creation
	struct sockaddr_in	server_addr, client_addr;	


	//feeding values into the socket address structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(myport);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset( server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero) );
	
	bind( listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr) );
	
	//ready for listening		l i s t e n f d
	listen(listenfd, 10);
	size = sizeof(client_addr);
	int childpid=0;
	char buf[100];
	
	while(1)
	{
		connfd=accept(listenfd,(struct sockaddr* ) &client_addr , &size) ;
		printf("%s\n","Received request..." ) ;
		if((childpid = fork ())==0 ) 
		{
			printf ("%s\n" , "Child created for dealing with client requests" ) ;
			close ( listenfd );
		
			while ((n = recv( connfd , buf , MAXLINE , 0 ) ) > 0 )
			{
				printf("%s","String received from and resent to the client: " ) ;
				puts ( buf ) ;
				send(connfd , buf , n , 0 ) ;
			}
			if(n<0)
			{	printf("%s\n","Read error" ) ;
				exit (0);
			}
			close(connfd);
		}
		close(connfd) ;
	}
}
