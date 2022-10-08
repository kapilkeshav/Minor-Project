#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

void init_hash_table(){
    int i;
    hash_table = malloc(HS*sizeof(tokens));
    for(i=0;i<HS;i++){
        hash_table[i]=NULL;
    }
}

unsigned int hash(char *key){
    unsigned int hv = 0;
    for(;*key!='\0';key++){
        hv += *key;
    }
    hv+=key[0]%11+(key[0]<<3)-key[0];
    return hv%HS;
}

void insert(char *name, int len, int type, int lineno){
    unsigned int hashv = hash(name);
    tokens *l = hash_table[hashv];

    while((l!=NULL)&&(strcmp(name,l->t_name)!=0)){
        l=l->next;
    }

    if(l==NULL){
        l = (tokens*)malloc(sizeof(tokens));
        strncpy(l->t_name,name,len);
        l->t_type = type;
        l->t_scope = cur_scope;
        l->lines = (varref*)malloc(sizeof(varref));
        l->lines->lineno = lineno;
        l->lines->next = NULL;
        l->next = hash_table[hashv];
        hash_table[hashv]=l;
        printf("Inserted %s for the first time with linenumber %d!\n", name, lineno); // error checking
    }
}

tokens *lookup(char *name){
    unsigned int hashv = hash(name);
    tokens *l = hash_table[hashv];
    while((l!=NULL)&&(strcmp(name,l->t_name)!=0)){
        l=l->next;
    }
    return l;
}

void hide_scope(){ 
	if(cur_scope > 0) cur_scope--;
}

void incr_scope(){ 
	cur_scope++;
}

tokens *lookup_scope(char *name, int scope){ 
    unsigned int hashval = hash(name);
    tokens *l = hash_table[hashval];
    while ((l != NULL) && (strcmp(name,l->t_name) != 0) && (scope != l->t_scope)) l = l->next;
    return l; 
}
