#ifndef _DICT_H_
#define _DICT_H_
#include <stddef.h>

typedef unsigned long hash_t;
hash_t dict_strhash(const char *s);

#define DICT_HASH_DUMMY (((hash_t) 1) << (8 * sizeof(hash_t) - 1))

struct dict_entry {
  hash_t d_hash;
  char *d_key;
};

struct dict {
  struct dict_entry *d_table;
  size_t d_mask;
  size_t d_load;
  size_t d_count;
};

int dict_init(struct dict *dict, size_t count);
char *dict_lookup(struct dict *dict, const char *key);
char **dict_search(struct dict *dict, char *key);
char *dict_for_each(struct dict *dict, size_t *i);

#endif
