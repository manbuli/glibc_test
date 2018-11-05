#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void test_wait_1()
{
	pid_t pid = fork();
	if(pid == -1)
		perror("create process fail\n");
	else if(pid == 0)
	{
		printf("cilent process %d loop\n",getpid() );
		sleep(60);
		printf("cilent process %d exit\n",getpid() );
		exit(13);
	}
	else
	{
		printf("parent process %d loop , wait child precess is %d\n",getpid() ,pid);
		int status;

		pid_t child = wait(&status);
		if(WIFEXITED(status))
		{
			printf("client %d normal exit :%d\n",child,WEXITSTATUS(status) );
		}
		else if(WIFSIGNALED(status))
		{
			printf("client %d no normal exit :%d\n",child,WTERMSIG(status) );
		}
		else
		{
			printf("client %d  unkonw exit \n",child );
		}
	}
	
	printf("%s\n","Call test_wait_1 end" );
}

int main(int argc, char const *argv[])
{
	test_wait_1();

	return 0;
}