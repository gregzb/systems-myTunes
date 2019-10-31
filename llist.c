#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct node * gen_node(char * name, char * artist) {
    struct node * new_node = malloc(sizeof(struct node));
    strncpy(new_node->name, name, sizeof(new_node->name));
    strncpy(new_node->artist, artist, sizeof(new_node->artist));
    return new_node;
}

void print_list(struct node * list) {
    struct node * current = list;
    while (current != NULL) {
        printf("%s: %s | ", current->artist, current->name);
        current = current->next;
    }
    printf("\n");

}

struct node * insert_front(struct node * list, char * name, char * artist) {
    struct node * new_node = gen_node(name, artist);
    new_node->next = list;
    return new_node;
}

struct node * free_list(struct node * list) {
    struct node * current = list;
    struct node * next = current;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    return NULL;
}

struct node * remove_node(struct node *front, char * name, char * artist) {

    struct node * prev = NULL;
    struct node * current = front;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->artist, artist)) {
            if (prev == NULL) {
                struct node * temp = current->next;
                free(current);
                return temp;
            }
            prev->next = current->next;
            free(current);
            return front;
        }

        prev = current;
        current = current -> next;
    }

    return front;
}

struct node * insert_ordered(struct node * front, char * name, char * artist) {
    struct node * new_node = gen_node(name, artist);

    char found = 0;

    struct node * current = front;
    while (current != NULL ) {
        if (strcmp(new_node->artist, current->artist) > 0 || strcmp(new_node->artist, current->artist) == 0 && strcmp(new_node->name, current->name) > 0) {
            found = 1;
            break;
        }
        current -> next;
    }
    if (found)
}

struct node * find_node(struct node * front, char * name, char * artist) {

}

struct node * find_node_by_artist(struct node * front, char * artist) {

}

struct node * find_random(struct node * front) {

}
