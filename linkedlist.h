#include "linkedlist.c"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


int add_to_end(struct Node **address_book,  struct Node *new_node);
void print_all(struct Node **address_book);
void print_by_index(struct Node **address_book, int index);
void print_by_field(struct Node **address_book, int field, char buffer[30]);
int insert(struct Node **address_book, struct Node *new_node, int index);

#endif