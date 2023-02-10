#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> // delete me later
#include "ui.h"
#include "linkedlist.h"
#define DELIMITER ","

void init_addresses(struct Node **address_book);
void read_address_file(struct Node **address_book, FILE *address_file);

int main(void)
{
    struct Node *address_book = NULL;

    init_addresses(&address_book);
    if(address_book == NULL){
        printf("Warning: failed to initialize address book.\n");
    }
    start_ui();
    return 0;
}

void init_addresses( struct Node **address_book)
{
    char *home_path = getenv("HOME");
    char address_file_name[] = "/addresses.csv";
    char *full_path = NULL;

    full_path = (char*)malloc(sizeof(home_path)+sizeof(address_file_name)+2);
    if(full_path == NULL){
        return;
    }
    strcpy(full_path, home_path);
    strcat(full_path, address_file_name);

    FILE *address_file = fopen((full_path), "a+");

    read_address_file(address_book, address_file);
    
    free(full_path);
    fclose(address_file);
}
void read_address_file(struct Node **address_book, FILE *address_file)
{
    char buffer[100];

    while(fscanf(address_file, "%100[^\n]", buffer) != -1){
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
}