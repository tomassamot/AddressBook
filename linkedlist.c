#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER ","

#ifndef LINKEDLIST_C
#define LINKEDLIST_C





struct Node* create_node(char name[20], char surname[20], char email[30], char phone[20])
{
    struct Node *new_node = NULL;

    new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    strcpy(new_node->surname, surname);
    strcpy(new_node->email, email);
    strcpy(new_node->phone, phone);
    new_node->next = NULL;

    return new_node;
}
struct Node* create_node_csv(char input[])
{
    char *token = strtok(input, DELIMITER);
    struct Node *new_node = NULL;
    new_node = (struct Node*) malloc(sizeof(struct Node));

    for(int i = 0;i<4;i++){
        if(token == NULL){
            printf("Couldn't process given input. Cancelling...\n");
            return NULL;
        }
        switch(i){
            case 0:
                strcpy(new_node->name, token);
                break;
            case 1:
                strcpy(new_node->surname, token);
                break;
            case 2:
                strcpy(new_node->email, token);
                break;
            case 3:
                strcpy(new_node->phone, token);
                break;
            default:
                printf("Unexpected switch case.\n");
                break;
            }
        token = strtok(NULL, DELIMITER);
    }
    return new_node;
}
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
int delete_all(struct Node **address_book)
{
    struct Node *current_node = *address_book;

    while(current_node != NULL){
        struct Node *next = current_node->next;
        current_node = NULL;
        free(current_node);
        current_node = next;
    }
    *address_book = NULL;
    return 0;
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
        if(i == index){
            printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
            printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
            return;
        }
        current_node = current_node->next;
        i++;
    }
    printf("Address with given index not found.\n");
}
void print_by_field(struct Node **address_book, int field, char buffer[30])
{
    struct Node *current_node = *address_book;
    
    char actual[30] = { [0 ... 29] = '\0' };
    char expected[30] = { [0 ... 29] = '\0' };;
    int i = 0;

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
void deallocate_address_book(struct Node **address_book)
{
    struct Node *current_node = *address_book;
    while(current_node != NULL){
        struct Node *tmp = current_node->next;
        free(current_node);
        current_node = tmp;
    }
}
#endif
