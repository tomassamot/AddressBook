#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fileoperations.c"
#include "linkedlist.c"


#define DELIMITER ","

int start_ui(char **given_address_path);
static void clear_stdin();
static void process_input(int input);
static void process_get_type_input(int input, char *address_path);
static void process_get_by_index_input(int input, char *address_path);
static void process_get_by_field_input(int input, char *address_path);
static void process_add_type_input(int input, char *address_path);
static struct Node* create_node(char input[]);
static void process_delete_type_input(int input, char *address_path);

char **address_path = NULL;

int start_ui(char **given_address_path)
{
    address_path = given_address_path;
    int input = -1;
    
    while(input != 0){
        printf("What would you like to do?\n");
        printf("0 – Exit, 1 – Get address / addresses, 2 – Add address, 3 – Delete address / addresses\n");

        if(scanf("%d", &input) != 1){
            printf("Couldn't understand given input.\n");
            clear_stdin();
            continue;
        }
        clear_stdin();

        process_input(input);
        if(errno != 0){
            perror("Error detected: ");
        }
    }
}
static void clear_stdin()
{
    char ch = 'a';
    while (ch != EOF && ch != '\n'){
        ch = fgetc(stdin);
    }
}
static void process_input(int input)
{
    int new_input;
    switch(input){
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Get all addresses, 2 – Get address by position, 3 – Get address by information\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            process_get_type_input(new_input, *address_path);
            break;
        case 2:
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Add new address, 2 – Add new address in given position\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            process_add_type_input(new_input, *address_path);
            break;
        case 3:
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Delete address in given position, 2 – Delete the whole address book\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            process_delete_type_input(new_input, *address_path);
            break;
        default:
            printf("Couldn't understand given input. Try again.\n");
            break;
    }
}
static void process_get_type_input(int input, char *address_path)
{
    int new_input;

    switch(input){
        case 0:
            printf("Cancelling...\n");
            break;
        case 1:
            print_all(address_path);
            break;
        case 2:
            printf("Type in index in address book:\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            process_get_by_index_input(new_input, address_path);
            break;
        case 3:
            printf("By what information would you like to search?\n");
            printf("0 – Cancel, 1 – Name, 2 – Surname 3 – Email, 4 – Phone number\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            process_get_by_field_input(new_input, address_path);
            break;
        default:
            printf("Couldn't understand given input. Cancelling...\n");
            break;
    }
}
static void process_get_by_index_input(int input, char *address_path)
{
    if(input < 0){
        printf("Index can't be negative. Cancelling...\n");
        return;
    }

    print_by_index(address_path, input);
}
static void process_get_by_field_input(int input, char *address_path)
{
    char buffer[30];

    if(input == 0){
        printf("Cancelling...\n");
        return;
    }
    if(input > 4 || input < 1){
        printf("Couldn't understand given input. Cancelling...\n");
        return;
    }

    printf("Type in field information:\n");
    scanf("%29[^\n]", buffer);
    clear_stdin();

    print_by_field(address_path, input, buffer);
}
static void process_add_type_input(int input, char *address_path)
{
    int new_input;
    char buffer[100];
    struct Node *new_node = NULL;
    int ret = -1;

    switch(input){
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Type in the name, surname, email and phone number, seperating each by one comma (f.e.: “Peter,Peterson,p.peterson@gmail.com,865792146”)\n");
            scanf("%99[^\n]", buffer);
            clear_stdin();
            new_node = create_node(buffer);
            //ret = add_to_end(full_path, new_node);
            ret = file_add_to_end(address_path, new_node);
            if(ret == 0){
                printf("Added address to end successfully.\n");
            }
            free(new_node);
            break;
        case 2:
            printf("Type in index where you would like to insert new address:\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input.\n");
                clear_stdin();
                return;
            }
            clear_stdin();

            printf("Type in the name, surname, email and phone number, seperating each by one comma (f.e.: “Peter,Peterson,p.peterson@gmail.com,865792146”)\n");
            scanf("%99[^\n]", buffer);
            clear_stdin();

            new_node = create_node(buffer);
            if(new_node == NULL){
                return;
            }
            ret = file_insert(address_path, new_node, new_input);
            if(ret == 0){
                printf("Inserted address into given position successfully.\n");
            }
            else{
                printf("Failed to insert address. Check your index and input and try again.\n");
            }
            break;
        default:
            printf("Couldn't understand given input. Try again.\n");
            break;
    }
}
static struct Node* create_node(char input[])
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
static void process_delete_type_input(int input, char *address_path)
{
    int new_input;
    int ret;

    switch(input){
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Type in index in address book:\n");
            if(scanf("%d", &new_input) != 1){
                printf("Couldn't understand given input. Cancelling...\n");
                clear_stdin();
                return;
            }
            clear_stdin();
            if(new_input < 0){
                printf("Couldn't understand given input. Cancelling...\n");
            }
            ret = file_delete_by_index(address_path, new_input);
            if(ret == 0){
                printf("Address deleted successfully.\n");
            }
            break;
        case 2:
            ret = file_delete_all(address_path);
            if(ret == 0){
                printf("All addresses deleted successfully.\n");
            }
            break;
        default:
            printf("Couldn't understand given input. Try again.\n");
            break;
    }
}