#include "str.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
typedef struct {
    char *text;
    unsigned int capacity;
    unsigned int len;
} String;
 * */

String new_str() {
    String s;
    unsigned int initial_capacity = INITIAL_CAPACITY;

    s.text = (char *)malloc(initial_capacity * sizeof(char));
    if (s.text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    s.text[0] = '\0';
    s.capacity = initial_capacity;
    s.len = 0;

    return s;
}

String from_str(const char *text) {
    String s;
    unsigned int initial_len = strlen(text);
    unsigned int initial_capacity = initial_len + 1;

    s.text = (char *)malloc(sizeof(char) * initial_capacity);
    if (s.text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strncpy(s.text, text, initial_len);
    s.text[initial_len] = '\0';

    s.len = initial_len;
    s.capacity = initial_capacity;

    return s;
}

String with_capacity(int capacity) {
    String s;
    unsigned int initial_capacity;

    if (capacity < 0)
        initial_capacity = INITIAL_CAPACITY;
    else
        initial_capacity = capacity;

    s.text = (char *)malloc(initial_capacity * sizeof(char));
    if (s.text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    s.text[0] = '\0';
    s.capacity = initial_capacity;
    s.len = 0;

    return s;
}

int free_str(String *s) {
    if (s == NULL) {
        return -1;
    }
    free(s->text);
    s->text = NULL;
    s->capacity = 0;
    s->len = 0;
    return 0;
}

int len_str(const String *s) { return s->len; }

int insert_chars(String *s, int idx, const char *text) {
    int text_length = strlen(text);
    if (idx < 0 || text_length <= 0)
        return -1;

    if (s->len == 0 && text_length <= s->capacity) {
        strncpy(s->text, text, text_length);
        s->len = text_length;
    } else if (s->len == 0 && text_length > s->capacity) {
        s->text = (char *)realloc(s->text, sizeof(char) * text_length);
        if (s->text == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return -1;
        }
        s->capacity = text_length;
        s->len = text_length;
    }

    return 0;
}

int insert_str(String *s, int idx, const String *text) {}

int capacity_str(const String *s) { return s->capacity; }

int push_str(String *s, char c) {
    if (s->capacity > s->len) {
        s->text[s->len] = c;
        s->len++;
        s->text[s->len] = '\0';
        return 0;
    } else if (s->capacity <= s->len) {
        s->capacity *= 2;
        s->text = (char *)realloc(s->text, sizeof(char) * s->capacity);
        if (s->text == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return -1;
        }

        s->text[s->len] = c;
        s->len++;
        s->text[s->len] = '\0';
        return 0;
    }

    return -1;
}

int truncate_str(String *s, int idx) {
    if (is_empty_str(s) || idx < 0 || idx > s->len)
        return -1;

    s->text[idx] = '\0';
    s->len = idx;

    return 0;
}

int clear_str(String *s) {
    s->len = 0;
    s->text[0] = '\0';
    return 0;
}

char remove_str(String *s, int idx) {}

char pop_str(String *s) {
    if (is_empty_str(s)) {
        return '\0';
    }

    s->len--;
    char c = s->text[s->len];

    s->text[s->len] = '\0';

    return c;
}

bool is_empty_str(const String *s) { return (s == NULL || s->text == NULL); }
