#define HS 211
#define MTL 40
#define UNDEF 0
#define INT 1
#define REAL 2
#define STR 3
#define LGC 4
#define ARR 5
#define FUNC 6
#define BY_VAL 1
#define BY_REF 2
int cur_scope=0;
typedef struct param{
    int p_type;
    char p_name[MTL];
    int i;double f;char *str;
    int passing;
}param;

typedef struct varref{
    int lineno;
    struct varref *next;
    int type;
}varref;

typedef struct tokens{
    char t_name[MTL];
    int t_size;
    int t_scope;
    varref *lines;
    int i; double f; char *str;
    int t_type;
    int t_ifo;
    int *i_vals; double *f_vals; char **s_vals;
    int arr_size;
    param *params;
    int n_params;
    struct tokens *next;
}tokens;

static tokens **hash_table;

// Function Declarations
void init_hash_table(); // initialize hash table
unsigned int hash(char *key); // hash function 
void insert(char *name, int len, int type, int lineno); // insert entry
tokens *lookup(char *name); // search for entry
tokens *lookup_scope(char *name, int scope); // search for entry in scope
void hide_scope(); // hide the current scope
void incr_scope(); // go to next scope
void symtab_dump(FILE *of); // dump file