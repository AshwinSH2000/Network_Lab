#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#define myport 3345
int main()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	server.sin_port = htons(myport);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server.sin_zero, '\0', sizeof(server.sin_zero));
		
	int size = sizeof(server);
	int afd = connect(sockfd, (struct sockaddr *)&server, size);
	int buff[20], ch, sch, n,i;
	while(1)
	{
		printf("\n\n\n1. Search for element:\n2. Split into odd and even\n3. Exit\n\nEnter your choice:");
		scanf("%d",&ch);		
		send(sockfd, &ch, sizeof(ch), 0);
		switch(ch)
		{
			case 1:printf("Enter how many elements:");
				scanf("%d", &n);
				printf("Enter the array elements:");
				for(i=0 ; i<n ; i++)
					scanf("%d", &buff[i]);
				printf("Which element to search:");
				scanf("%d", &sch);
				send(sockfd, buff, sizeof(buff), 0);
				send(sockfd, &n, sizeof(n), 0);
				send(sockfd, &sch, sizeof(sch), 0);
				recv(sockfd, &sch, sizeof(sch), 0);
				if(sch == -1)
					printf("The required element not found.");
				else
					printf("The element found at index = %d", sch);
				break;
			case 2:
				printf("Enter how many elements:");
				scanf("%d", &n);
				printf("Enter the array elements:");
				for(i=0 ; i<n ; i++)
					scanf("%d", &buff[i]);
				send(sockfd, buff, sizeof(buff), 0);
				send(sockfd, &n, sizeof(n), 0);
				int odd[10], even[10], x=0,y=0;
				recv(sockfd, even, sizeof(even), 0);
				recv(sockfd, odd, sizeof(odd), 0);
				recv(sockfd, &x, sizeof(x), 0);
				recv(sockfd, &y, sizeof(y), 0);
				printf("\n\nEven elements\n");
				for(i=0 ; i<x ; i++)
					printf("%d,", even[i]);

				printf("\n\nOdd elements\n");
				for(i=0 ; i<y ; i++)
					printf("%d,", odd[i]);
				break;
			case 3:i=999;
				close(sockfd);
					break; 		
		}
		if (i==999)
			break;
		
	}
	close(sockfd);
}
