#ifndef MY_MUSIC
#define MY_MUSIC

#include "llist.h"

struct node * table[27];

void initialize();

void add_song(char *, char *);
struct node * find_song(char *, char *);
struct node * find_artist(char *);
void print_by_letter(char);
void print_by_artist(char *);
void print_all();
void shuffle();
void delete_song(char *, char *);
void clear();

#endif
