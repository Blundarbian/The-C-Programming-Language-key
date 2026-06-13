/* Exercise 8-5. Modify the fsize program to print the other 
 * information contained in the inode entry.
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>	// r/w flags
#include <sys/types.h>	// typedefs
#include <sys/stat.h>	// structure returned by stat
#include <dirent.h>

#define MAX_PATH 1024
#ifndef DIRSIZ
#define DIRSIZ 14
#endif

void fsize(char *);
void dirwalk(char *, void (*fct)(char *));

int main(int argc, char *argv[]) {

	if (argc == 1)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	
	return 0;
}

void fsize(char *name) {

}

void dirwalk(char *dir, void (*fct)(char *)) {

}
