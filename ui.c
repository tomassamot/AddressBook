#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> // delete me later
#include "linkedlist.h"

static int process_input(char input);
static int process_get_type_input(char input);
static int process_get_position_input(char input);
static int process_get_information_input(char input);

int clear_stdin()
{
    char ch = 'a';
    while (ch != EOF && ch != '\n'){
        ch = fgetc(stdin);
    }
    return 0;
}

int start_ui()
{
    char input;
    char asdf;
    while(input != '0'){
        printf("What would you like to do?\n");
        printf("0 – Exit, 1 – Get address / addresses, 2 – Add address, 3 – Delete address / addresses\n");
        //scanf(" %1[^\n]", input);
        scanf("%c[^\n]", &input);
        clear_stdin();

        process_input(input);
        if(errno != 0){
            perror("Error detected: ");
        }
        printf("input: %c\n", input);
        sleep(0.5);
    }
}
static int process_input(char input)
{
    char new_input;
    switch(input){
        case '0':
            printf("You selected 0, exiting...\n");
            break;
        case '1':
            printf("You selected 1.\n");
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Get all addresses, 2 – Get address by position, 3 – Get address by information\n");
            scanf("%c[^\n]", &new_input);
            printf("new_input: %c\n", new_input);
            clear_stdin();
            process_get_type_input(new_input);
            break;
        case '2':
            printf("You selected 2.\n");
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Add new address, 2 – Add new address in given position\n");
            scanf("%c[^\n]", &new_input);
            //process_add_input(new_input);
            break;
        case '3':
            printf("You selected 3.\n");
            printf("What would you like to do next?\n");
            printf("0 – Cancel, 1 – Delete address in given position, 2 – Delete the whole address book\n");
            scanf("%c[^\n]", &new_input);
            //process_remove_input(new_input);
            break;
        default:
            printf("Couldn't understand given input. Try again.\n");
            break;
    }
    return 0;
}
static int process_get_type_input(char input)
{
    
    switch(input){
        case '0':
            printf("You selected 0, cancelling...\n");
            break;
        case '1':
            printf("You selected 1.\n");
            //get_all_addresses();
            break;
        case '2':
            //int position =

            printf("You selected 2.\n");
            printf("Write position in address book.\n");
            scanf("%c[^\n]", &input);
            //process_get_input(input);
            break;
        case '3':
            printf("You selected 3.\n");
            printf("By what information would you like to search?\n");
            printf("0 – Cancel, 1 – Name, 2 – Surname 3 – Email, 4 – Phone number\n");
            scanf("%c[^\n]", &input);
            //process_get_input(input);
            break;
        default:
            printf("Couldn't understand given input. Try again.\n");
            break;
    }
}
static int process_get_position_input(char input)
{

}
static int process_get_information_input(char input)
{

}
static int process_add_type_input(char input)
{

}
static int process_add_position_input(char input)
{

}
static int process_delete_type_input(char input)
{

}
/*
*   
*/
static int process_delete_position_input(char input)
{

}
static int process_delete_whole_input(char input)
{

}