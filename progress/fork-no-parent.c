#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */

	int count = 0;
	pid_t pid = fork();
	if(pid == -1)
		perror("create process fail\n");
	else if(pid == 0)
	{
		printf("cilent process %d loop,parent is %d\n",getpid(),getppid() );
		sleep(60);
		printf("cilent process %d parent is %d\n",getpid(),getppid() );
		exit(13);
	}
	else
	{
		count++;
		sleep(1);
		printf("parent process %d loop , wait child precess is %d\n",getpid() ,pid);

	}
	return 0;
}