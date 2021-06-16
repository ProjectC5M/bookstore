#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"model.h"


int  deletedBook(BookInfo book){
    BookInfoPtr headX = getHead(book.genre);
    if(book.index == headX->index){
        BookInfoPtr temp = headX;
        headX= headX->next;
        free(temp);
        setHead(&headX, book.genre);
        return 1;
    }else{
        BookInfoPtr previous = headX;
        BookInfoPtr current = headX->next;
        while(current != NULL && book.index != current->index){
            previous = current;
            current = current->next;
        }
        if (current != NULL)
        {
            BookInfoPtr temp = current;
            previous->next = current->next;
            free(temp);
        }
        
    setHead(&headX, book.genre);
    return 1;
    }
    return 0;
}

int bookABook(BookInfo bookInfo){
    
        BookInfoPtr headX = getHead(bookInfo.genre);
        BookInfoPtr temp = headX;
        while(temp != NULL && bookInfo.index != temp->index){
            temp = temp->next;
        }
        if (temp != NULL)
        {
            if(temp->isBooked){
            temp->isBooked = 0;
        } else{
            temp->isBooked = 1;
        }
        setHead(&headX, bookInfo.genre);
        return 1;
        }
        
    return 0;
}
    
