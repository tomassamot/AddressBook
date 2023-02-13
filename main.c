#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ui.c"

int get_size(const char *ptr); 

int main(void)
{
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
    
    start_ui(&full_path);
    free(full_path);
    return 0;
}
int get_size(const char *ptr)
{
    char curr_char = 'a';
    int size = 0;

    while(curr_char != '\0'){
        curr_char = ptr[size];
        size++;
    }
    return size;
}