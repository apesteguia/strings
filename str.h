#ifndef MAG_STR
#define MAG_STR

#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    char *text;
    unsigned int capacity;
    unsigned int len;
} String;

String new_str();
String from_str(const char *);
String with_capacity(int);
int len_str(const String *);
int insert_chars(String *, int, const char *);
int insert_str(String *, int, const String *);
int capacity_str(const String *);
int push_str(String *, char);
int truncate_str(String *, int);
int clear_str(String *);
int free_str(String *);
char remove_str(String *, int);
char pop_str(String *);
bool is_empty_str(const String *);

#endif
