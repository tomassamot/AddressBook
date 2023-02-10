#include <stdio.h>

struct Node{
    char name[25];
    char surname[25];
    char email[25];
    char phone[25];
    struct Node *next;
};

void add_to_end(struct Node **address_book,  struct Node *new_node)
{
    struct Node *current_node = *address_book;

    if(current_node == NULL){
        *address_book = new_node;
        return;
    }

    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
}
/*
int get_length(Node **address_book)
{
    Node *curr = *address_book;

    int length = 0;
    while(curr != NULL){
        length++;
    }
    return length;
}
int get_all_addresses(Node **address_book)
{
    Address addresses[get_length(address_book)];
    int count = 0;

    Node *curr = *address_book;
    while(curr != NULL){
        Address *address = NULL;

        strcpy(curr->name, address->name);
        strcpy(curr->surname, address->surname);
        strcpy(curr->email, address->email);
        strcpy(curr->phone, address->phone);

        addresses[count] = *address;
        count++;
    }
}*/