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
	struct sockaddr_in client;
	client.sin_port = htons(myport);
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(client.sin_zero, '\0', sizeof(client.sin_zero));
	bind(sockfd, (struct sockaddr *)&client, sizeof(struct sockaddr));	

	//no connect and listen. direct sendto and recvfrom()
	char str[30]; 

	int size = sizeof(client);
	int res, len, vowels[5],i;
	char x;
	while(1)
	{
		printf("\nEnter the string:");
		scanf("%[^\n]",str);
		scanf("%c",&x);

		str[strlen(str)] = '\0';
		sendto(sockfd, str, sizeof(str), 0, (struct sockaddr *)&client, size);
		if(strcmp("Halt",str)==0)
			break;		

		//recv 3 things. result of p/notp, count of each vowel in the str, length of the string
		recvfrom(sockfd, &res, sizeof(res), 0, (struct sockaddr *)&client, &size);
		recvfrom(sockfd, &len, sizeof(len), 0, (struct sockaddr *)&client, &size);
		recvfrom(sockfd, vowels, sizeof(vowels), 0, (struct sockaddr *)&client, &size);
		if(res == 1)
			printf("\n\nIt is a palindrome");
		else
			printf("\n\nIt is not a palindrome");
		printf("\n\nIts length is %d", len);
		printf("\n\nVowels count :");
		printf("\nA = %d ",vowels[0]);
		printf("\nE = %d ",vowels[1]);
		printf("\nI = %d ",vowels[2]);
		printf("\nO = %d ",vowels[3]);
		printf("\nU = %d ",vowels[4]);

	}
	close(sockfd);
}	
		
