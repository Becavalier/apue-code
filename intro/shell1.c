#include "apue.h"
#include <sys/wait.h>

/**
 * char	*fgets(char * __restrict, int, FILE *);
 * size_t strlen(const char *__s);
 * pid_t fork(void);
 * int execlp(const char * __file, const char * __arg0, ...);
 * pid_t waitpid(pid_t, int *, int);
*/
int main(void) {
	char buf[MAXLINE]; /* from apue.h */
	pid_t pid;
	int status;

	printf("%% "); /* print prompt (printf requires %% to print %) */
	// Read a line of input from stdin, -
	// return a pointer to the string if it succeeds. Otherwise, NULL.
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */

		if ((pid = fork()) < 0) {  // Create a new process, a fork of the current one.
			err_sys("fork error");
		} else if (pid == 0) { /* child */
			execlp(buf, buf, (char *)0);  // Execute the line as a command.
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)  // Wait for child process to exit first.
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
