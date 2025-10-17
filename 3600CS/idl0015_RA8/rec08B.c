#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if ( pid < 0) {
	perror("Failure in forking the process");
	exit(1);
    } else if ( pid == 0){
	//exiting the child process
	exit(0);
    } else {
	sleep(5);
	system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");
    }
}
