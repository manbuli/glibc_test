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
		printf("cilent process %d loop\n",getpid() );
		sleep(1);
		printf("cilent process %d exit\n",getpid() );
		exit(13);
	}
	else
	{
		count++;
		printf("parent process %d loop , wait child precess is %d\n",getpid() ,pid);

		sleep(60);

	}
	return 0;
}