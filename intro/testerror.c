#include "apue.h"
#include <errno.h>

/**
 * void perror(const char *);
 * char* strerror(int errnum);
*/
int main(int argc, char *argv[]) {
	// strerror maps the errno into a readable string, and return a pointer to it.
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	// perror generates an error msg based on errno and send it to stderr.
	perror(argv[0]);  // A standard way to report error.
	exit(0);
}
