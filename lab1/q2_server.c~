#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#define myport 3345
int main()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server;
	server.sin_port = htons(myport);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server.sin_zero, '\0', sizeof(server.sin_zero));
	bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr));	

	char str[30]; 

	int size = sizeof(server);
	int res=1, len=0, vowels[5]={0},i,j;
	while(1)
	{	res = 1; len = 0;
		for(i=0 ; i<5 ; i++)
			vowels[i] = 0;
		recvfrom(sockfd, str, sizeof(str), 0, (struct sockaddr *)&server, &size);
		printf("Waiting to receive...");
		if(strcmp("Halt",str)==0)
			break;
		for(i=0 ; str[i]!='\0'; i++)
		{	len++;
			if(str[i] == 'a' || str[i] == 'A')
				vowels[0]++;
			else if(str[i] == 'e' || str[i] == 'E')
				vowels[1]++;
			else if(str[i] == 'i' || str[i] == 'I')
				vowels[2]++;			
			else if(str[i] == 'o' || str[i] == 'O')
				vowels[3]++;			
			else if(str[i] == 'u' || str[i] == 'U')
				vowels[4]++;
		}
		for(i=0 , j = len-1 ; i<=j ; i++,j--)
			if(str[i]!=str[j])
			{	res = 0;
				break;
			}
		//recv 3 things. result of p/notp, count of each vowel in the str, length of the string
		sendto(sockfd, &res, sizeof(res), 0, (struct sockaddr *)&server, size);
		sendto(sockfd, &len, sizeof(len), 0, (struct sockaddr *)&server, size);
		sendto(sockfd, vowels, sizeof(vowels), 0, (struct sockaddr *)&server, size);

	}
	close(sockfd);
}	

