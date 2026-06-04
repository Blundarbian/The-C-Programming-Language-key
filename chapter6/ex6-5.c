/* Exercise 6-5. Write a function undef that will remove 
 * a name and definition from the table maintained by 
 * lookup and install
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {			// table entry
	struct nlist *next;	// next entry
	char *name;		// def name
	char *defn;		// replacment text
};

static struct nlist *hashtab[HASHSIZE];		// ptr table

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *undef(char *);
struct nlist *nldup(struct *p);
struct nlist *install(char *name, char *defn);
char *strdup(char *);


// form hash value for string s
unsigned hash(char *s) {
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}


// look for s in hashtab
struct nlist *lookup(char *s) {

	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return mp;		// found 
	return NULL;				// not found
}


struct nlist *undef(char *name) {

	struct nlist *np;
	struct nlist *prev;
	struct nlist *post;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) 	// not found
		return NULL;

	prev = hashtab[hash(s)];
	while (strcmp(s, prev->next->name) == 0)
		prev = prev->next;

	post = np->next;

	if (post == NULL) {
		free(np);
		prev->next = NULL;
	}
	else {
		free(np);
		prev->next = post;
	}
}

struct nlist *nldup(struct *p) {

	struct nlist *np;
	
	if (p == NULL) return NULL;

	np = (struct nlist *) malloc(sizeof(struct nlist));

	if (np != NULL) {
		np->next = p->next;
		np->name = p->name;
		np->defn = p->defn;
	}

	return np;
}


// put (name, defn) in hashtab
struct nlist *install(char *name, char *defn) {

	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	// not found
		np = (struct nlist *) malloc(sizeof(*np));

		if (np = NULL || (np->name = sstrdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else 					// at node
		free((void *) np->defn);	// free prev defn
	
	if ((np->defn = sstrdup(defn)) == NULL)
		return NULL;

	return np;
}
