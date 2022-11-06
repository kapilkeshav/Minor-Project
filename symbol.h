/* maximum size of hash table */
#define SIZE 211

/* maximum size of tokens-identifiers */
#define MAXTOKENLEN 40

/* token types */
#define UNDEF 0
#define INT_T 1
#define REAL_T 2
#define STR_T 3
#define LOGIC_T 4
#define ARRAY_T 5
#define FUNCTION_T 6

/* how parameter is passed */
#define BY_VALUE 1
#define BY_REFER 2

/* parameter struct */
typedef struct Param{
	int p_type;
	char p_name[MAXTOKENLEN];
	// to store value
	int ival; double fval; char *st_sval;
	int passing; // value or reference
}Param;

/* a linked list of references (lineno's) for each variable */
typedef struct varref{ 
    int lineno;
    struct RefList *next;
    int type;
}varref;

// struct that represents a list node
typedef struct tokens{
	char t_name[MAXTOKENLEN];
    int t_size;
    int t_scope;
    varref *lines;
	// to store value and sometimes more information
	int st_ival; double st_fval; char *st_sval;
	// type
    int t_type;
	int t_ifo; // for arrays (info type) and functions (return type)
	// array stuff
	int *i_vals; double *f_vals; char **s_vals;
	int arr_size;
	// function parameters
	Param *parameters;
	int n_pars;
	// pointer to next item in the list
	struct tokens *next;
}tokens;

/* the hash table */
static tokens **hash_table;

// Function Declarations
void init_hash_table(); // initialize hash table
unsigned int hash(char *key); // hash function 
void insert(char *name, int len, int type, int lineno); // insert entry
tokens *lookup(char *name); // search for entry
tokens *lookup_scope(char *name, int scope); // search for entry in scope
void hide_scope(); // hide the current scope
void incr_scope(); // go to next scope
