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

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%d %d\t %12ld\t : %s\n", stbuf.st_uid, stbuf.st_gid, stbuf.st_size, name);
}

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0
				|| strcmp(dp->name, ".."))
			continue; /* skip self and parent */
		if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s %s too long\n",
					dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}
