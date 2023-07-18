#include "apue.h"
#include <dirent.h>

/**
 * DIR* opendir(const char*);
 * struct dirent* readdir(DIR*);
 * int closedir(DIR*);
*/
int main(int argc, char *argv[]) {
	/* structure describing an open directory. */
	DIR *dp; 
	struct dirent *dirp;

	if (argc != 2)
		err_quit("usage: ls directory_name");

	// NULL => ((void*)0).
	if ((dp = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
