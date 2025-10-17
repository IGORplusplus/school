#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 < 0) {
	perror("fork failed\n");
	exit(1);
    } else if (pid1 == 0) {
	printf("child 1 pid: %d parent pid: %d\n", getpid(), getppid());
	execlp("date", "date", NULL);
	perror("failure on the date command in child 1\n");
	exit(1);
    } else {
	//this is only for the parent
	pid2 = fork();
    }

    if (pid2 < 0) {
	perror("fork failed\n");
	exit(1);
    } else if (pid2 == 0){
	printf("child 2 pid: %d parent pid: %d\n", getpid(), getppid());
	execlp("whoami", "whoami", NULL);
	perror("failure on the whomai command in child 2\n");
	exit(1);
    }

    bool child1_terminated = false;
    bool child2_terminated = false;
    for(;;) {
	pid_t terminated_process = waitpid(-1, &status, 0);
	if (terminated_process == -1) {
	    perror("termination error");
	    exit(1);
	}

	if (terminated_process == pid1) {
	    child1_terminated = true;
	    printf("child one is terminated %d\n", pid1);
	} else if (terminated_process == pid2) {
	    child2_terminated = true;
	    printf("child two is terminated %d\n", pid2);
	}
	if (child1_terminated && child2_terminated) {
	    break;
	}
    }
    printf("all children are terminated\n");

    return 0;
}
