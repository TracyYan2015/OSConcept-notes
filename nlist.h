#define HASHSIZE 101

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

/* hash: form hash value for string s */
unsigned hash(char *s);

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s);

// char *strdup(char *);

struct nlist *install(char *name, char *defn);

