#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    char name[20];
    char surname[20];
    char email[30];
    char phone[20];
    struct Node *next;
};

struct Node* create_node(char name[20], char surname[20], char email[30], char phone[20]);
struct Node* create_node_csv(char input[]);
int add_to_end(struct Node **address_book,  struct Node *new_node);
int insert(struct Node **address_book, struct Node *new_node, int index);
int delete_by_index(struct Node **address_book, int index);
int delete_all(struct Node **address_book);
void print_all(struct Node **address_book);
void print_by_index(struct Node **address_book, int index);
void print_by_field(struct Node **address_book, int field, char buffer[30]);
void print_node(struct Node *node, int index);
void deallocate_address_book(struct Node **address_book);

#endif