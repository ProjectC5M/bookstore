#include <stdio.h>
#include <stdlib.h>
#include "../model.h"
BookInfo* fileToLinkedListHead(FILE * file);
int main()
{
    char *pathsOfFiles[5] = {"Romantic.txt", "Thriller.txt", "Horror.txt", "SciFi.txt", "Cooking.txt"};
     BookInfo *HeadOfHeads[5];
    for(size_t i = 0; i < 5; i++){
        
    FILE *hi;
    puts("hello");
    hi = fopen(pathsOfFiles[i], "r");
    if (hi == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }

    HeadOfHeads[i] = fileToLinkedListHead(hi);
    fclose(hi);
    }
}

BookInfo* fileToLinkedListHead(FILE * file){

    if (file == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return NULL;
    }
    BookInfo *head;
    BookInfo *current;
    BookInfo *current2;
    current = malloc(sizeof(BookInfo));
    head = malloc(sizeof(BookInfo));
    fread(head, sizeof(BookInfo), 1, file);
    head->next = current;
    while (fread(current, sizeof(BookInfo), 1, file))
    {
        current->next = malloc(sizeof(BookInfo));
        current2 = current;
        current = current->next;
        current->next = NULL;
    }
    free(current);
    current2->next = NULL;
    
    return head;
}