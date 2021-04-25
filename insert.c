#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "model.h"
#include "insert.h"
#include "search.h"
void insertFirst(BookInfoPtr *ptr, BookInfo b){

    BookInfoPtr newNode=(BookInfoPtr)malloc(sizeof(BookInfo));
    /*if(newNode != NULL){
        strcpy(newNode->bookName, b.bookName);
        strcpy(newNode->author, b.author);
        newNode->index=b.index;
        newNode->genre=b.genre;
        newNode->rating=b.rating;
        newNode->isBooked=b.isBooked;
        newNode->next = NULL;
        BookInfoPtr previous = NULL;
        BookInfoPtr current = *ptr;
        //        SOME ALGORITH FOR THE INDEX SHOULD BE HERE
        //
        while(current != NULL & b.index > current->index){
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

    */if (newNode!=NULL){
        strcpy(newNode->bookName, b.bookName);
        strcpy(newNode->author, b.author);
        newNode->index=b.index;
        newNode->genre=b.genre;
        newNode->rating=b.rating;
        newNode->isBooked=b.isBooked;
        newNode->next=*ptr;
        *ptr=newNode;
    }
    
}
/*
void insertAt(BookInfoPtr *ptr,int loc ,BookInfo b){
    
    BookInfoPtr newNode=malloc(sizeof(BookInfo));
    if (newNode!=NULL){

        strcpy(newNode->bookName, b.bookName);
        strcpy(newNode->author, b.author);
        newNode->index=b.index;
        newNode->genre=b.genre;
        newNode->rating=b.rating;
        newNode->isBooked=b.isBooked;
        newNode->next=NULL;
        
        // *ptr=newNode;
    
        BookInfoPtr current=*ptr;
        BookInfoPtr previous=NULL;
        if (loc==1){
            insertFirst(ptr,b);
        }
        else{   int i;
                for ( i = 2; i <= loc; i++){
             previous=current;
             current = current->next;

        }
        previous->next=newNode;
        newNode->next=current;
        }
        
        

    
         for (int i = 2; i <= loc; i++){
              previous=current;
              current = current->next;

         }
         previous->next=newNode;
         newNode->next=current;
               
    }
   
    

    
}*/
