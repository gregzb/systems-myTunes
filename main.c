#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

int main() {
    struct node * my_music = NULL;
    my_music = insert_ordered(my_music, "oui", "a");
    my_music = insert_ordered(my_music, "nein", "c");
    my_music = insert_ordered(my_music, "alpha", "b");
    my_music = insert_ordered(my_music, "nein", "a");
    print_list(my_music);

    struct node * found0 = find_node(my_music, "oui", "a");
    struct node * found1 = find_node(my_music, "alpha", "b");
    print_list(found0);
    print_list(found1);
    free_list(my_music);
    return 0;
}
