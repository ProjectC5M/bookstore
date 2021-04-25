#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "model.h"
#include "search.h"
#include "mainUI.h"
#include "insert.h"
    

//BookInfoPtr head = NULL;

int main(){
    //welcomeMessage();
    //registrationWindow();
   /* BookInfoPtr headX = getHead();
    BookInfo book = {.genre = 1, .isBooked = 0, .rating=3,.bookName = "Book1", .author = "author1"};
    insertFirst(headX, book);
    //BookInfoPtr result = searchBook(&headX,"book1");
    BookInfo book1 = {.genre = 1, .isBooked = 0, .rating=3,.bookName = "Book2", .author = "author2"};
    insertFirst(headX, book1);
    BookInfo book2 = {.genre = Horror, .isBooked = 0, .rating=3,.bookName = "Book3", .author = "author3",.isBooked=1};
    insertFirst(headX, book2);
    BookInfo book3 = {.genre = 1, .isBooked = 0, .rating=3,.bookName = "Book4", .author = "author4"};
    insertFirst(headX, book3);*/
    /*char bookName[50]
    printf("%s","Enter the book name: ");
    scanf("%s",bookName);
    BookInfoPtr result = searchBook(&headX,bookName);
    if(result == NULL) printf("%s","This book isn\'t exsist");
    else
    showBook(*result);*/

    mainMenu();
   
     
    //searchauthor(&start,word);
    //searchauthor(&start,"mo");
    //BookInfo bookInfo;
    system("pause");
    return 0;
}