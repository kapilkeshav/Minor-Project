#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

/* current scope */
int cur_scope = 0;

void init_hash_table(){
	int i; 
	hash_table = malloc(SIZE * sizeof(tokens*));
	for(i = 0; i < SIZE; i++) hash_table[i] = NULL;
}

unsigned int hash(char *key){
	unsigned int hashval = 0;
	for(;*key!='\0';key++) hashval += *key;
	hashval += key[0] % 11 + (key[0] << 3) - key[0];
	return hashval % SIZE;
}

void insert(char *name, int len, int type, int lineno){
	unsigned int hashval = hash(name);
	tokens *l = hash_table[hashval];
	
	while ((l != NULL) && (strcmp(name,l->t_name) != 0)) l = l->next;
	
	/* variable not yet in table */
	if (l == NULL){
		l = (tokens*) malloc(sizeof(tokens));
		strncpy(l->t_name, name, len);  
		/* add to hashtable */
		l->t_type = type;
		l->t_scope = cur_scope;
		l->lines = (varref*) malloc(sizeof(varref));
		l->lines->lineno = lineno;
		l->lines->next = NULL;
		l->next = hash_table[hashval];
		hash_table[hashval] = l; 
		printf("Inserted %s for the first time with linenumber %d!\n", name, lineno); // error checking
	}
	/* found in table, so just add line number */
	else{
		l->t_scope = cur_scope;
		varref *t = l->lines;
		while (t->next != NULL) t = t->next;
		/* add linenumber to reference list */
		t->next = (varref*) malloc(sizeof(varref));
		t->next->lineno = lineno;
		t->next->next = NULL;
		printf("Found %s again at line %d!\n", name, lineno);
	}
}

tokens *lookup(char *name){ /* return symbol if found or NULL if not found */
	unsigned int hashval = hash(name);
	tokens *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(name,l->t_name) != 0)) l = l->next;
	return l; // NULL is not found
}

tokens *lookup_scope(char *name, int scope){ /* return symbol if found or NULL if not found */
	unsigned int hashval = hash(name);
	tokens *l = hash_table[hashval];
	while ((l != NULL) && (strcmp(name,l->t_name) != 0) && (scope != l->t_scope)) l = l->next;
	return l; // NULL is not found
}

void hide_scope(){ /* hide the current scope */
	if(cur_scope > 0) cur_scope--;
}

void incr_scope(){ /* go to next scope */
	cur_scope++;
}

