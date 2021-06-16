#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "insert.h"
#include "search.h"

const char fileName[5][30] = {"romantic.txt", "thriller.txt", "horror.txt", "sciFi.txt", "cooking.txt"};

void readIntoLinkedList()
{
    FILE *filePtr[5];
    BookInfoPtr headx[5] = {NULL};
    int i;
    for (i = 0; i < 5; i++)
    {
        filePtr[i] = fopen(fileName[i], "ab+");
        if (filePtr[i]== NULL)
        {
            puts("\a*********ERROR WHILE READING FILES*********");
            exit(1);
        }
        headx[i] = getHead(i + 1);
        int counter;
        while (!feof(filePtr[i]))
        {   
            BookInfo book;
            counter = fread(&book, sizeof(BookInfo), 1, filePtr[i]);
            if(!counter) break;
            insertFirst(&headx[i], book);
        }
        setHead(&headx[i], i + 1);
        fclose(filePtr[i]);
    }

}

void writeFromLinkedList()
{
    FILE *filePtr[5];
    BookInfoPtr headx[5] = {NULL};
    int i;
    for (i = 0; i < 5; i++)
    {
        filePtr[i] = fopen(fileName[i], "wb");
        if (filePtr[i] == NULL)
        {
            puts("\a*********ERROR WHILE WRITING INTO FILES*********");
            exit(1);
        }
        rewind(filePtr[i]);
        headx[i] = getHead(i + 1);

        while (headx[i] != NULL)
        {  

            fwrite(headx[i], sizeof(BookInfo), 1, filePtr[i]);
            (*(headx + i)) = (*(headx + i))->next;
        }

        
        fclose(filePtr[i]);
    }
}