#include <stdio.h>
#include <string.h>

#ifndef LINKEDLIST_C
#define LINKEDLIST_C

struct Node{
    char name[20];
    char surname[20];
    char email[30];
    char phone[20];
    struct Node *next;
};

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
        if(i == index){
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
void print_all(struct Node **address_book)
{
    struct Node *current_node = *address_book;
    int i = 0;

    printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
    while (current_node != NULL){
        printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
        current_node = current_node->next;
        i++;
    }
}
void print_by_index(struct Node **address_book, int index)
{
    struct Node *current_node = *address_book;
    int i = 0;

    while (current_node != NULL){
        if (i == index){
            printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
            printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
            return;
        }
        current_node = current_node->next;
        i++;
    }
    printf("Address with given index not found.\n");
}
void print_by_field(struct Node **address_book, int field, char buffer[30]){
    size_t size = 30;
    char actual[size];
    char expected[size];
    char tmp[size];
    int i = 0;
    /*for (int i = 0;i<30;i++)
        tmp[i] = '\0';*/

    strcpy(actual, tmp);
    strcpy(expected, tmp);
    
    struct Node *current_node = *address_book;

    printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
    while (current_node != NULL){
        switch(field){
            case 1:
                strcpy(actual, current_node->name);
                strcpy(expected, buffer);
                if (strncmp(actual, expected, 4) == 0)
                    printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
                break;
            case 2:
                strcpy(actual, current_node->surname);
                strcpy(expected, buffer);
                if (strncmp(actual, expected, 4) == 0)
                    printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
                break;
            case 3:
                strcpy(actual, current_node->email);
                strcpy(expected, buffer);
                if (strncmp(actual, expected, 4) == 0)
                    printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
                break;
            case 4:
                strcpy(actual, current_node->phone);
                strcpy(expected, buffer);
                if (strncmp(actual, expected, 4) == 0)
                    printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
                break;
        }
        current_node = current_node->next;
        i++;
    }
}

#endif
