#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// extern char **environ;
// int execl(const char *path, const char *arg, ...
//                /* (char  *) NULL */);
// int execlp(const char *file, const char *arg, ...
//                /* (char  *) NULL */);
// int execle(const char *path, const char *arg, ...
//                /*, (char *) NULL, char * const envp[] */);
// int execv(const char *path, char *const argv[]);
// int execvp(const char *file, char *const argv[]);
// int execvpe(const char *file, char *const argv[],
//                char *const envp[]);


void test_excel()
{
	char* strPath = "/bin/ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParam0 = "ls1";
	char* strParam1 = "-l";
	char* strParam2 = "-at";

	printf("%s\n","Call test_excel before" );
	if(-1 == execl(strPath,strParam0,strParam1,strParam2,NULL))
	{
		perror("Call test_excel error" );
	}

	printf("%s\n","Call test_excel end" );
}

void test_excelp()
{
	//find cmd from system path
	char* strPath = "ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParam0 = "ls";
	char* strParam1 = "-l";
	char* strParam2 = "-at";

	printf("%s\n","Call test_excelp before" );
	if(-1 == execlp(strPath,strParam0,strParam1,strParam2,NULL))
	{
		perror("Call test_excelp error" );
	}

	printf("%s\n","Call test_excelp end" );
}

void test_excele()
{
	char* strPath = "/bin/ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParam0 = "ls";
	char* strParam1 = "-l";
	char* strParam2 = "-at";

	//pass environment variab to process
	char* strEnv[] = {"PATH=/bin",NULL};

	printf("%s\n","Call test_excele before" );
	if(-1 == execle(strPath,strParam0,strParam1,strParam2,NULL,strEnv))
	{
		perror("Call test_excele error" );
	}

	printf("%s\n","Call test_excele end" );
}

void test_excev()
{
	char* strPath = "/bin/ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParams[] = {"ls","-lat",NULL};

	printf("%s\n","Call test_excev before" );
	if(-1 == execv(strPath,strParams))
	{
		perror("Call test_excev error" );
	}

	printf("%s\n","Call test_excev end" );
}

void test_excevp()
{
	char* strPath = "ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParams[] = {"ls","-lat",NULL};

	printf("%s\n","Call test_excev before" );
	if(-1 == execvp(strPath,strParams))
	{
		perror("Call test_excev error" );
	}

	printf("%s\n","Call test_excev end" );
}

void test_excevpe()
{
	char* const strPath = "ls";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* const strParams[] = {"ls","-lt",NULL};

	printf("%s\n","Call test_excevpe before" );
	//pass environment variab to process
	char* const strEnv1[] = {"PATH=/bin1",NULL};
	if(-1 == execvpe(strPath,strParams,strEnv1))
	{
		perror("Call test_excevpe error" );
	}

	printf("%s\n","Call test_excevpe end" );
}

void test_excelp_2()
{
	//find cmd from system path
	char* strPath = "ps";
	//char* strParam0 = "ls1"; == char* strParam0 = "ls";
	char* strParam0 = "ps";
	char* strParam1 = "-avx";

	int fd = open("logs",O_CREAT|O_WRONLY|O_TRUNC );

	printf("%s\n","Call dup2 before" );
	if(-1 == fd)
			perror("create file fail\n");
	else
		dup2(fd,STDOUT_FILENO);
	printf("%s\n","Call dup2 after" );

	printf("%s\n","Call test_excelp before" );
	if(-1 == execlp(strPath,strParam0,strParam1,NULL))
	{
		perror("Call test_excelp error" );
	}

	printf("%s\n","Call test_excelp end" );
}

int main(int argc, char const *argv[])
{
	/* code */
	//test_excel();
	//test_excelp();
	// test_excele();
	//test_excev();
	// test_excevp();
	// test_excevpe();
	test_excelp_2();

	return 0;
}