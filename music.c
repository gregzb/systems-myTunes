#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int idx = lenStr <= 0 || artist[0] < 'a' || artist[0] > 'z' ? 26 : artist[0] - 'a' ;
    table[idx] = insert_ordered(table[idx], name, artist);
}

struct node * find_song(char * name, char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr <= 0 || artist[0] < 'a' || artist[0] > 'z' ? 26 : artist[0] - 'a' ;
    return find_node(table[idx], name, artist);
}

struct node * find_artist(char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr <= 0 || artist[0] < 'a' || artist[0] > 'z' ? 26 : artist[0] - 'a' ;
    return find_node_by_artist(table[idx], artist);
}

void print_by_letter(char letter) {
    int idx = letter >= 'a' && letter <= 'z' ? letter - 'a' : 26;
    if (table[idx] == NULL){
      printf("No songs with Artist of this letter\n");
    }
    print_list(table[idx]);
}

void print_by_artist(char * artist) {
    struct node * song = find_artist(artist);
    while (song != NULL && strcmp(song -> artist, artist) == 0){
      print_single(song);
      song = song -> next;
      printf("\n");
    }
}

void print_all() {
    // if (table == NULL){
    //   printf("No library\n");
    //   return;
    // }
    int idx;
    for (idx = 0; idx < (sizeof(table)/sizeof(table[0])) - 1; idx++) {
        printf("%c: ", idx+'a');
        print_list(table[idx]);
    }
    printf("Misc: ");
    print_list(table[idx]);
}

void shuffle() {
    int idx;
    for (idx = 0; idx < 3; idx++) {
        int rand_val = rand() % 27;
        while(table[rand_val] == NULL){
          rand_val = rand() % 27;
        }
        print_single(find_random(table[rand_val]));
    }
    printf("\n");
}

void delete_song(char * name, char * artist) {
    int lenStr = strlen(artist);
    int idx = lenStr <= 0 || artist[0] < 'a' || artist[0] > 'z' ? 26 : artist[0] - 'a';
    table[idx] = remove_node(table[idx], name, artist);
}

void clear() {
    int idx;
    for (idx = 0; idx < sizeof(table)/sizeof(table[0]); idx++) {
        table[idx] = free_list(table[idx]);
    }
}
