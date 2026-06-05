/* Exercise 6-5. Write a function undef that will remove a name 
 * and definition from the table maintained by lookup and install
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 100

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
void printhash();


int main() {

	install("John", "pizza");
	install("Dave", "pie");
	install("Lary", "crust");
	printhash();
	undef("Lary");
	printhash();

	return 0;
}


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

	unsigned h = hash(name);
	struct nlist *np = hashtab[h];
	struct nlist *prev = NULL;

	while (np && strcmp(np->name, name) != 0) {
		prev = np;
		np = np->next;
	}

	if (np == NULL) return NULL;
	struct nlist *r = nldup(np);

	if (prev == NULL)	// prev is NULL when np is first element
		hashtab[h] = np->next;	
	else
		prev->next = np->next;	

	free(np->name);
	free(np->defn);
	free(np);

	return r;
}

// deep copy of struct item
struct nlist *nldup(struct nlist *p) {

	struct nlist *np;
	
	if (p == NULL) return NULL;

	np = (struct nlist *) malloc(sizeof(struct nlist));

	if (np != NULL) {
		np->next = p->next;
		np->name = strdup(p->name);
		np->defn = strdup(p->defn);
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

void printhash() {

	for (int i = 0; i < HASHSIZE; i++) {
		if (hashtab[i] != NULL) {
			for (struct nlist *p = hashtab[i]; p != NULL; p = p->next) {
				printf("Hash %s, def %s", p->name, p->defn);
				if (p->next != NULL)
					printf(" -> ");
				else
					printf("\n");
			}
		}
	}
}
