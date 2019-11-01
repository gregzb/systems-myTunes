#ifndef LINKED_LIST_C
#define LINKED_LIST_C

struct node{
  char name[124];
  char artist[124];
  struct node *next;
};

void print_list(struct node *);

void print_single(struct node *);

struct node * insert_front(struct node *, char *, char *);

struct node * free_list(struct node *);

struct node * remove_node(struct node *, char *, char *);

struct node * insert_ordered(struct node *, char *, char *);

struct node * find_node(struct node *, char *, char *);

struct node * find_node_by_artist(struct node *, char *);

struct node * find_random(struct node *);

#endif
