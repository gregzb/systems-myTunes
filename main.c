#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "llist.h"
#include "music.h"

int main() {
    srand(time(NULL));

    printf("LINKED LIST TESTS\n");
    printf("==================================\n\n");

    printf("Testing print list\n");
    struct node * my_music = NULL;
    my_music = insert_front(my_music, "hello", "its me");
    my_music = insert_front(my_music, "world", "big world");
    my_music = insert_front(my_music, "song", "artiste");
    print_list(my_music);
    my_music = free_list(my_music);
    printf("==================================\n\n");

    printf("Testing insert_ordered\n");
    my_music = insert_ordered(my_music, "oui", "a");
    my_music = insert_ordered(my_music, "nein", "c");
    my_music = insert_ordered(my_music, "alpha", "b");
    my_music = insert_ordered(my_music, "nein", "a");
    my_music = insert_ordered(my_music, "nein", "c");
    print_list(my_music);
    printf("==================================\n\n");

    printf("Testing find node\n");

    printf("looking for [a: oui]\n");
    struct node * found0 = find_node(my_music, "oui", "a");
    print_list(found0);

    printf("looking for [b: alpha]\n");
    found0 = find_node(my_music, "alpha", "b");
    print_list(found0);

    printf("looking for [a: no]\n");
    found0 = find_node(my_music, "no", "a");
    print_list(found0);
    printf("==================================\n\n");

    printf("Testing find artist\n");
    printf("Looking for songs by c\n");
    struct node * found1 = find_node_by_artist(my_music, "c");
    print_list(found1);
    printf("Looking for songs by a\n");
    found1 = find_node_by_artist(my_music, "a");
    print_list(found1);
    printf("Looking for songs by x\n");
    found1 = find_node_by_artist(my_music, "x");
    print_list(found1);
    printf("==================================\n\n");

    printf("Testing find_random\n");
    struct node * random = find_random(my_music);
    print_list(random);
    random = find_random(my_music);
    print_list(random);
    random = find_random(my_music);
    print_list(random);
    random = find_random(my_music);
    print_list(random);
    random = find_random(my_music);
    print_list(random);
    printf("==================================\n\n");

    printf("Testing remove\n");
    printf("Removing [a: oui] \n");
    my_music = remove_node(my_music, "oui", "a");
    print_list(my_music);
    printf("Removing [b: alpha] \n");
    my_music = remove_node(my_music, "alpha", "b");
    print_list(my_music);
    printf("==================================\n\n");

    printf("Testing free_list\n");
    my_music = free_list(my_music);
    printf("List after free\n");
    print_list(my_music);
    printf("==================================\n\n");

    printf("MUSIC LIBRARY TESTS\n");
    printf("==================================\n\n");
    initialize();

    printf("Testing print_all\n");
    add_song("alpha", "alpha");
    add_song("beta", "beta");
    add_song("alpha", "beta");
    add_song("beta", "alpha");
    add_song("gamma", "abc");
    add_song("hahaha", "boo");
    //printf("1\n");
    add_song("soong", "");
    //printf("2\n");
    //print_all();
    add_song("world", "[hello]");
    //printf("3\n");
    print_all();
    //printf("4\n");
    printf("==================================\n\n");

    printf("Testing find_song\n");
    printf("looking for [beta:alpha]\n");
    struct node * tfound = find_song("alpha", "beta");
    print_list(tfound);

    printf("looking for [beta:beta]\n");
    tfound = find_song("beta", "beta");
    print_list(tfound);

    printf("looking for [[hello]:world]\n");
    tfound = find_song("world", "[hello]");
    print_list(tfound);

    printf("looking for [:soong]\n");
    tfound = find_song("soong", "");
    print_list(tfound);

    printf("looking for [gamma:beta]\n");
    tfound = find_song("beta", "gamma");
    print_list(tfound);
    printf("==================================\n\n");

    printf("Testing find artist\n");
    printf("Looking for songs by alpha\n");
    struct node * foundArtist = find_artist("alpha");
    print_list(foundArtist);

    printf("Looking for songs by beta\n");
    foundArtist = find_artist("beta");
    print_list(foundArtist);

    printf("Looking for songs by [hello]\n");
    foundArtist = find_artist("[hello]");
    print_list(foundArtist);

    printf("Looking for songs by artiste \n");
    foundArtist = find_artist("artiste ");
    print_list(foundArtist);
    printf("==================================\n\n");

    printf("Testing print letter\n");
    printf("printing by a\n");
    print_by_letter('a');
    printf("printing by b\n");
    print_by_letter('b');
    printf("printing by c\n");
    print_by_letter('c');
    printf("==================================\n\n");

    printf("Testing print artist\n");
    printf("printing by alpha\n");
    print_by_artist("alpha");
    printf("printing by beta\n");
    print_by_artist("beta");
    printf("printing by [hello]\n");
    print_by_artist("[hello]");
    printf("printing by c\n");
    print_by_artist("c");
    printf("==================================\n\n");

    printf("Testing shuffle\n");
    shuffle();
    printf("==================================\n\n");

    printf("Testing delete_song\n");
    printf("deleting [alpha:alpha]\n");
    delete_song("alpha", "alpha");
    printf("deleting [beta:beta]\n");
    delete_song("beta", "beta");
    printf("deleting [:soong]\n");
    delete_song("soong", "");
    printf("deleting [notArtist:song]\n");
    delete_song("notArtist", "song");
    print_all();

    printf("Testing clear\n");
    clear();
    printf("Library after clear\n");
    print_all();

    return 0;
}
