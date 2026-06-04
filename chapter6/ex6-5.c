/* Exercise 6-5. Write a function undef that will remove 
 * a name and definition from the table maintained by 
 * lookup and install
 */
#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;	// next entry
	char *name;		// def name
	char *defn;		// replacment text
};

static struct nlist *hashtab[HASHSIZE];		// ptr table

unsigned int hash(char *);
struct nlist *lookup(char *);
struct nlist *undef(char *);
struct nlist *install(char *name, char *defn);
char *strdup(char *);

unsigned int hash(char *s) {

}
