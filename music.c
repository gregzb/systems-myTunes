#include "llist.h"
#include "music.h"

void initialize() {
    int i;
    for (i = 0; i < sizeof(table)/sizeof(table[0]); i++) {
        table[i] = NULL;
    }
}

void add_song(char * name, char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr > 0 ? artist[0] - 'a' : 26;
    table[idx] = insert_ordered(table[idx], name, artist);
}

struct node * find_song(char * name, char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr > 0 ? artist[0] - 'a' : 26;
    return find_node(table[idx], name, artist);
}

struct node * find_artist(char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr > 0 ? artist[0] - 'a' : 26;
    return find_node_by_artist(table[idx], artist);
}

void print_by_letter(char letter) {
    int idx = lenStr > 0 ? letter - 'a' : 26;
    print_list(table[idx]);
}

void print_by_artist(char * artist) {
    print_list(find_artist(artist));
}

void print_all() {
    int idx;
    for (idx = 0; idx < sizeof(table)/sizeof(table[0]); idx++) {
        printf("%c", idx+'a');
        print_list(table[idx]);
    }
}

void shuffle() {
    int idx;
    for (idx = 0; i < 3; i++) {
        int rand_val = rand() % 27;
        print_single(find_random(table[rand_val]));
    }
    print("\n");
}

void delete_song(char * name, char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr > 0 ? artist[0] - 'a' : 26;
    remove_node(table[idx], name, artist);
}

void clear() {
    int idx;
    for (idx = 0; idx < sizeof(table)/sizeof(table[0]); idx++) {
        free_list(table[idx]);
    }
}
