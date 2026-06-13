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
	
	struct stat stbuf;
	
	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "size: no acess %s\n", name);
		return;
	}

	if ((strbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%d %d\t %12ld\t : %s\n", stbuf.st_uid, stbuf.st_gid, stbuf.st_size, name);
}


void dirwalk(char *dir, void (*fct)(char *)) {

	char name[FILENAME_MAX];
	struct dirent *dp;
	DIR *dfd;

	if ((dfd

}
