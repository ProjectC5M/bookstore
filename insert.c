#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "model.h"
#include "insert.h"
#include "search.h"


void insertFirst(BookInfoPtr *ptr, BookInfo b){

    BookInfoPtr newNode=(BookInfoPtr)malloc(sizeof(BookInfo));
    if(newNode != NULL){
        strcpy(newNode->bookName, b.bookName);
        strcpy(newNode->author, b.author);
        newNode->index=b.index;
        newNode->genre=b.genre;
        newNode->rating=b.rating;
        newNode->isBooked=0;
        newNode->next = NULL;
        BookInfoPtr previous = NULL;
        BookInfoPtr current = *ptr;
        int indexBook = b.index;
        char indexStringBook[20];
        // input 44, genre 1
        itoa(indexBook, indexStringBook,10);
        strcpy(&indexStringBook[0], &indexStringBook[1]);
        indexBook = atoi(indexStringBook);
        int indexCur = 0;
        if(current != NULL){
            char indexStringCur[20];
            itoa(current->index, indexStringCur,10);
            strcpy(&indexStringCur[0], &indexStringCur[1]);
            indexCur = atoi(indexStringCur);
        }
        while(current != NULL && indexCur < indexBook){
            previous = current;
            current = current->next;
        }
        if(previous == NULL){
            newNode->next = *ptr;
            *ptr = newNode;
        }
        else {
            previous->next = newNode;
            newNode->next = current;
        }
    }
    
}
