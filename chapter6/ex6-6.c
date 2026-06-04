/* Exercise 6-6. Implement a simple version of the 
 * #define processor (i.e., no arguments) suitable 
 * for use with C programs, based on the routines of 
 * this section. You may also find getch and ungetch 
 * helpful.
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
struct nlist *nldup(struct nlist *p);
struct nlist *install(char *name, char *defn);
char *sstrdup(char *);


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
			return np;		// found 
	return NULL;				// not found
}


// remove the first instance of a name from the list
struct nlist *undef(char *name) {

	struct nlist *np;
	struct nlist *prev;
	struct nlist *post;

	if ((np = lookup(name)) == NULL) 	// not found
		return NULL;

	prev = hashtab[hash(name)];		// find prev node
	while (strcmp(name, prev->next->name) == 0)
		prev = prev->next;		

	post = np->next;			// find post

	struct nlist *nreturn = nldup(np);
	free(np);			

	if (post == NULL) 		// next is NULL
		prev->next = NULL;
	else 
		prev->next = post; 	// next is node
	
	return nreturn;
}

struct nlist *nldup(struct nlist *p) {

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

char *sstrdup(char *s) {

	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL) strcpy(p, s);

	return p;
}


// put (name, defn) in hashtab
struct nlist *install(char *name, char *defn) {

	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	// not found
		np = (struct nlist *) malloc(sizeof(*np));

		if (np == NULL || (np->name = sstrdup(name)) == NULL)
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
