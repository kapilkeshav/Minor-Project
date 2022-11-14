/* maximum size of hash table */
#define SIZE 211

/* maximum size of tokens-identifiers */
#define MAXTL 40

/* token types */
#define UNDEF 0
#define I_TYPE 1 //int
#define R_TYPE 2 //real
#define S_TYPE 3 //string
#define L_TYPE 4 //logic
#define A_TYPE 5 //array
#define F_TYPE 6 //function

/* how parameter is passed */
#define BY_VALUE 1
#define BY_REFER 2

/* parameter struct */
typedef struct param{
	int p_type;
	char p_name[MAXTL];
	// to store value
	int ival; double fval; char *st_sval;
	int passing; // value or reference
}param;

/* a linked list of references (lineno's) for each variable */
typedef struct varref{ 
    int lineno;
    struct varref *next;
    int type;
}varref;

// struct that represents a list node
typedef struct tokens{
	char t_name[MAXTL];
    int t_size;
    int t_scope;
    varref *lines;
	// to store value and sometimes more information
	int t_ival; double t_fval; char *t_sval;
	// type
    int t_type;
	int inf_type; // for arrays (info type) and functions (return type)
	// array stuff
	int *i_vals; double *f_vals; char **s_vals;
	int array_size;
	// function parameters
	param *parameters;
	int num_of_pars;
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
