#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// The waitpid() system call suspends execution of the calling process until a child specified by pid argument has changed state.  By default, waitpid() waits only for
// terminated children, but this behavior is modifiable via the options argument, as described below.

// The value of pid can be:

// < -1   meaning wait for any child process whose process group ID is equal to the absolute value of pid.

// -1     meaning wait for any child process.

// 0      meaning wait for any child process whose process group ID is equal to that of the calling process.

// > 0    meaning wait for the child whose process ID is equal to the value of pid.

// The value of options is an OR of zero or more of the following constants:

// WNOHANG     return immediately if no child has exited.

void test_waitpid_1()
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

		pid_t child  = -1;
		do
		{
			child = waitpid(pid,&status,WNOHANG);  //no block
			if(child == 0)
			{
				printf("wait clild sleep 10s\n");
				sleep(10);
			}
			
		}while(child == 0);
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

void test_waitpid_2()
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

		pid_t child  = -1;
		do
		{
			child = waitpid(pid,&status,0);  // block
			if(child == 0)
			{
				printf("wait clild sleep 10s\n");
				sleep(10);
			}
			
		}while(child == 0);
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

void test_waitpid_3()
{
	int count = 0;
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
		count++;
		printf("parent process %d loop , wait child precess is %d\n",getpid() ,pid);

		pid = fork();

		if(pid == -1)
			perror("create process fail\n");
		else if(pid == 0)
		{
			printf("cilent process %d loop\n",getpid() );
			sleep(60);
			printf("cilent process %d exit\n",getpid() );
			exit(132);
		}
		else
		{
			count++;
			printf("parent process %d loop , wait new child precess is %d\n",getpid() ,pid);

		}

		int status;

		pid_t child  = -1;
		
		do
		{
			child = waitpid(-1,&status,WNOHANG);  // no block ；wait any one child process
			// child = waitpid(0,&status,WNOHANG);  // no block ；wait any one child process
			// child = waitpid(0,&status,WNOHANG);  //  block ；wait any one child process
			if(child == 0)
			{
				printf("wait clild sleep 10s\n");
				sleep(10);
			}
			else
			{
				printf("clild %d exit\n",child);

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

				count--;
			}
			
		}while(count > 0);

		
	}
	
	printf("%s\n","Call test_waitpid_3 end" );
}

void test_waitpid_4()
{
	int count = 0;
	pid_t pid = fork();
	if(pid == -1)
		perror("create process fail\n");
	else if(pid == 0)
	{
		printf("cilent process %d loop\n",getpid() );
		sleep(30);
		printf("cilent process %d exit\n",getpid() );
		exit(13);
	}
	else
	{
		count++;
		printf("parent process %d loop , wait child precess is %d\n",getpid() ,pid);

		pid = fork();

		if(pid == -1)
			perror("create process fail\n");
		else if(pid == 0)
		{
			printf("cilent process %d loop\n",getpid() );
			sleep(40);
			printf("cilent process %d exit\n",getpid() );
			exit(112);
		}
		else
		{
			count++;
			printf("parent process %d loop , wait new child precess is %d\n",getpid() ,pid);

		}

		int status;

		pid_t child  = -1;
		
		do
		{
			child = waitpid(-1 * getpid(),&status,WNOHANG);  // no block ；wait any one child process
			// child = waitpid(0,&status,WNOHANG);  // no block ；wait any one child process
			// child = waitpid(0,&status,WNOHANG);  //  block ；wait any one child process
			if(child == 0)
			{
				printf("wait clild sleep 10s\n");
				sleep(10);
			}
			else
			{
				printf("clild %d exit\n",child);

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

				count--;
			}
			
		}while(count > 0);

		
	}
	
	printf("%s\n","Call test_waitpid_4 end" );
}
int main(int argc, char const *argv[])
{
	// test_waitpid_1();
	// test_waitpid_2();
	// test_waitpid_3();
	test_waitpid_4();
	return 0;
}