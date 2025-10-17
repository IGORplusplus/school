#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *name;
    pid_t pid = fork();

    if ( pid < 0) {
	perror("fork error");
	exit(1);
    } else if ( pid == 0) {
	printf("child: %d started\n", getpid());
	printf("child: parent = %d\n", getppid());
	printf("child: userid = %d\nNow going to sleep for 20 seconds\n", getuid());

	sleep(20);

	printf("Child just woke up\n");
    } else {
	printf("parent: %d started\n", getpid());
	printf("parent: parent = %d\n", getppid());
	exit(1);
    }

    name = (pid == 0) ? "child" : "parent";
    printf("%s terminating...\n", name);
}
