#include<stdio.h>
int main()
{
	printf("Before forking,");	
	printf("\nPid = %d, \nppid = %d\n", getpid(), getppid());
	int pid = fork();
	if(pid == 0)
	{
		printf("\nChild process");
		printf("\nPid = %d, \nppid = %d\n", getpid(), getppid());
	}
	else
	{
		printf("\nParent process");
		printf("\nPid = %d, \nppid = %d\n", getpid(), getppid());
	}
	return 0;
}
