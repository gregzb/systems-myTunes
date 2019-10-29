#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

int main() {
    struct node * my_music = NULL;
    my_music = insert_front(my_music, "me", "oui");
    my_music = insert_front(my_music, "not me", "nein");
    print_list(my_music);
    free_list(my_music);
    return 0;
}
