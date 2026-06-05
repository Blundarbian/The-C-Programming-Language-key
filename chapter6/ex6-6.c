/* Exercise 6-6. Implement a simple version of the 
 * #define processor (i.e., no arguments) suitable 
 * for use with C programs, based on the routines of 
 * this section. You may also find getch and ungetch 
 * helpful.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 100
#define SIZE 100

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
void printdef();

int main() {
	char line[SIZE];
	char name[SIZE] = "";
	char defn[SIZE] = "";
	char *token;

	while (fgets(line, SIZE, stdin) != NULL)
		if (strncmp(line, "#define", 7) == 0) {

			printf("%s", line);

			token = strtok(line ," ");
			token = strtok(NULL, " ");

			if (token != NULL) strcpy(name, token);
			token = strtok(NULL, "\n");
			if (token != NULL) strcpy(defn, token);

			install(name, defn);
		}
		else {
			token = strtok(line ," ");
			char fixed[SIZE] = "";
			while (token != NULL) {

				struct nlist *item;
				if ((item = lookup(token)) != NULL)
					strcat(fixed, item->defn);
				else 
					strcat(fixed, token);

				token = strtok(NULL, " ");
			}
			printf("%s", fixed);
		}
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

void printdef() {

	for (int i = 0; i < HASHSIZE; i++) {
		if (hashtab[i] != NULL) {
			for (struct nlist *p = hashtab[i]; p != NULL; p = p->next) {
				printf("#define %s %s", p->name, p->defn);
				if (p->next != NULL)
					printf(" -> ");
				else
					printf("\n");
			}
		}
	}
}
