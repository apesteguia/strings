#include "str.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *
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
char remove_str(String *, int);
char pop_str(String *);
bool is_empty_str(const String *);
 * */

int main(int argc, char **argv) {
    String s;
    s = from_str("Hola mikel");
    printf("%s\n", s.text);

    push_str(&s, 'c');
    push_str(&s, 'u');
    push_str(&s, 'l');

    printf("%s\n", s.text);

    pop_str(&s);
    pop_str(&s);
    pop_str(&s);
    pop_str(&s);
    pop_str(&s);

    printf("%s\n", s.text);

    truncate_str(&s, 5);
    printf("%s\n", s.text);

    clear_str(&s);

    printf("%s\n", s.text);
	free_str(&s);

    return 0;
}
