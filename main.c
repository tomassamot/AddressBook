#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ui.h"
#include "linkedlist.h"

#define DELIMITER ","

static int get_size(const char *ptr);
static void read_addresses_file(struct Node **address_book, char *full_path);

int main(void)
{
    struct Node *address_book = NULL;
    char *full_path = NULL;
    char *home_path = getenv("HOME");
    char address_file_name[] = "/addresses.csv";

    full_path = (char*)malloc(get_size(home_path)+sizeof(address_file_name)+2);
    if(full_path == NULL){
        printf("Couldn't allocate memory for full path variable.\n");
        return 1;
    }
    strcpy(full_path, home_path);
    strcat(full_path, address_file_name);

    read_addresses_file(&address_book, full_path);

    
    
    start_ui(&address_book);

    free(full_path);
    deallocate_address_book(&address_book);
    return 0;
}
static int get_size(const char *ptr)
{
    char curr_char = 'a';
    int size = 0;

    while(curr_char != '\0'){
        curr_char = ptr[size];
        size++;
    }
    return size;
}
static void read_addresses_file(struct Node **address_book, char *full_path)
{
    FILE *address_file = NULL;
    address_file = fopen((full_path), "r");

    if(address_file == NULL){
        printf("Error: trying to read file with null pointer\n");
        return;
    }

    char buffer[100];

    while(fscanf(address_file, "%99[^\n]", buffer) != -1){
        char name[20], surname[20], email[30], phone[20];
        char *token = strtok(buffer, DELIMITER);

        for(int i = 0;i<4;i++){
            switch(i){
                case 0:
                    strcpy(name, token);
                    break;
                case 1:
                    strcpy(surname, token);
                    break;
                case 2:
                    strcpy(email, token);
                    break;
                case 3:
                    strcpy(phone, token);
                    break;
                default:
                    printf("Unexpected switch case.\n");
                    break;
            }
            token = strtok(NULL, DELIMITER);
        }
        struct Node *new_node = create_node(name, surname, email, phone);
        add_to_end(address_book, new_node);
        fscanf(address_file, "%1[\n]", buffer);
    }
    fclose(address_file);
}