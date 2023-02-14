
/*
*
* Used earlier to do linkedlist style operatinos on a text file
*
*/


#include <stdio.h>
#include "linkedlist.c"

void file_get_all(struct Node **address_book, char *address_path);
void print_all(char *address_path);
void print_by_index(char *address_path, int index);
void print_by_field(char *address_path, int field, char buffer[30]);
int file_add_to_end(char *address_path,  struct Node *new_node);
int file_insert(char *address_path, struct Node *new_node, int index);
int file_delete_by_index(char *address_path, int index);
int file_delete_all(char *address_path);
void deallocate_address_book(struct Node **address_book);

void file_get_all(struct Node **address_book, char *address_path)
{
    FILE *address_file = NULL;
    address_file = fopen((address_path), "r");

    if(address_file == NULL){
        printf("Error: trying to read file with null pointer\n");
        return;
    }

    char buffer[100];

    while(fscanf(address_file, "%99[^\n]", buffer) != -1){
        struct Node *new_node = NULL;
        new_node = (struct Node*) malloc(sizeof(struct Node));
        char *token = strtok(buffer, DELIMITER);
        for(int i = 0;i<4;i++){
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
                    printf("Unexpected switch case.");
                    break;
            }
            token = strtok(NULL, DELIMITER);
        }
        new_node->next = NULL;
        add_to_end(address_book, new_node);
        fscanf(address_file, "%1[\n]", buffer);
    }
    fclose(address_file);
}
void print_all(char *address_path)
{
    struct Node *address_book = NULL;
    struct Node *current_node = NULL;    
    int i = 0;

    file_get_all(&address_book, address_path);
    current_node = address_book;

    printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
    while (current_node != NULL){
        printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
        current_node = current_node->next;
        i++;
    }
    deallocate_address_book(&address_book);
}
void print_by_index(char *address_path, int index)
{
    struct Node *address_book = NULL;
    struct Node *current_node = NULL;
    int i = 0;

    file_get_all(&address_book, address_path);
    current_node = address_book;

    while (current_node != NULL){
        if (i == index){
            printf("%3.3s %20.20s %20.20s %30.30s %20.20s\n", "IND", "NAME", "SURNAME", "EMAIL", "PHONE NUMBER");
            printf("%3.3d %20.20s %20.20s %30.30s %20.20s\n", i, current_node->name, current_node->surname, current_node->email, current_node->phone);
            deallocate_address_book(&address_book);
            return;
        }
        current_node = current_node->next;
        i++;
    }
    printf("Address with given index not found.\n");
    deallocate_address_book(&address_book);
}
void print_by_field(char *address_path, int field, char buffer[30]){
    struct Node *address_book = NULL;
    struct Node *current_node = NULL;
    
    char actual[30] = { [0 ... 29] = '\0' };
    char expected[30] = { [0 ... 29] = '\0' };;
    int i = 0;  
    
    file_get_all(&address_book, address_path);
    current_node = address_book;

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
    deallocate_address_book(&address_book);
}
int file_add_to_end(char *address_path,  struct Node *new_node)
{
    FILE *address_file = NULL;
    char buffer[100];

    address_file = fopen((address_path), "a");
    if(address_file == NULL){
        printf("Failed to create address file\n");
        return 1;
    }

    strcpy(buffer, new_node->name);
    strcat(buffer, ",");
    strcat(buffer, new_node->surname);
    strcat(buffer, ",");
    strcat(buffer, new_node->email);
    strcat(buffer, ",");
    strcat(buffer, new_node->phone);
    strcat(buffer, "\n");
    
    fprintf(address_file, "%s", buffer);

    fclose(address_file);
    return 0;
}
int file_insert(char *address_path, struct Node *new_node, int index)
{
    char buffer[100];
    struct Node *address_book = NULL;
    struct Node *current_node = NULL;
    FILE *address_file = NULL;

    file_get_all(&address_book, address_path);

    int ret = insert(&address_book, new_node, index);
    if(ret != 0){
        return ret;
    }

    current_node = address_book;
    address_file = fopen((address_path), "w");
    while(current_node != NULL){
        strcpy(buffer, current_node->name);
        strcat(buffer, ",");
        strcat(buffer, current_node->surname);
        strcat(buffer, ",");
        strcat(buffer, current_node->email);
        strcat(buffer, ",");
        strcat(buffer, current_node->phone);
        strcat(buffer, "\n");

        fprintf(address_file, "%s", buffer);

        current_node = current_node->next;
    }

    fclose(address_file);
    deallocate_address_book(&address_book);
    return ret;
}
int file_delete_by_index(char *address_path, int index)
{
    char buffer[100];
    struct Node *address_book = NULL;
    struct Node *current_node = NULL;
    FILE *address_file = NULL;

    file_get_all(&address_book, address_path);

    int ret = delete_by_index(&address_book, index);
    if(ret != 0){
        return ret;
    }

    current_node = address_book;
    address_file = fopen((address_path), "w");
    while(current_node != NULL){
        strcpy(buffer, current_node->name);
        strcat(buffer, ",");
        strcat(buffer, current_node->surname);
        strcat(buffer, ",");
        strcat(buffer, current_node->email);
        strcat(buffer, ",");
        strcat(buffer, current_node->phone);
        strcat(buffer, "\n");

        fprintf(address_file, "%s", buffer);

        current_node = current_node->next;
    }

    fclose(address_file);
    deallocate_address_book(&address_book);
    return ret;
}
int file_delete_all(char *address_path)
{
    FILE *address_file = NULL;
    address_file = fopen((address_path), "w");
    fclose(address_file);
    return 0;
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

