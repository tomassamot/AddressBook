#include <stdio.h>
#include <string.h>
#define DELIMITER ","

#ifndef LINKEDLIST_C
#define LINKEDLIST_C

struct Node{
    char name[20];
    char surname[20];
    char email[30];
    char phone[20];
    struct Node *next;
};


int add_to_end(struct Node **address_book,  struct Node *new_node);
int insert(struct Node **address_book, struct Node *new_node, int index);
int delete_by_index(struct Node **address_book, int index);


int add_to_end(struct Node **address_book,  struct Node *new_node)
{
    struct Node *current_node = *address_book;

    if (current_node == NULL){
        *address_book = new_node;
        return 0;
    }

    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return 0;
}
int insert(struct Node **address_book, struct Node *new_node, int index)
{
    struct Node *previous_node = NULL;
    struct Node *current_node = *address_book;
    int i = 0;

    while (current_node != NULL || i != index){
        if(i == index && i == 0){
            new_node->next = current_node;
            *address_book = new_node;
            return 0;
        }
        else if(i == index){
            previous_node->next = new_node;
            new_node->next = current_node;
            return 0;
        }
        previous_node = current_node;
        current_node = current_node->next;
        i++;
    }
    return 1;
}
int delete_by_index(struct Node **address_book, int index)
{
    struct Node *previous_node = NULL;
    struct Node *current_node = *address_book;
    int i = 0;

    while(current_node != NULL){
        if(i == index && i == 0){
            *address_book = current_node->next;
            free(current_node);
            return 0;
        }
        else if(i == index){
            previous_node->next = current_node->next;
            free(current_node);
            return 0;
        }
        previous_node = current_node;
        current_node = current_node->next;
        i++;
    }
    printf("Address with given index not found.\n");
    return 1;
}


#endif
