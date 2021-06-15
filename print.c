#include "model.h"
#include <stdio.h>
#include "mainUI.h"
#include <conio.h>
#include <string.h>
void printGenre(int genre){
    BookInfoPtr headX = getHead(genre );
    if(headX == NULL){
        printf("%s", "No books in this Genre");
        getch();
        return;
    }
    while(headX != NULL){
        printf("%s","\n\n");
        showBook(*headX);
        headX = headX->next;
        getch();
    }
}
void assignBookHeader(int i,char bookGenreHeader[]){
      switch (i)
        {
        case 1:
            strcpy(bookGenreHeader, "Romantic");
            break;
        
        case 2:
            strcpy(bookGenreHeader, "Thriller");
            break;
        
        case 3:
            strcpy(bookGenreHeader, "Horror");
            break;
        
        case 4:
            strcpy(bookGenreHeader, "SciFi");
            break;
        
        case 5:
            strcpy(bookGenreHeader, "Cooking");
            break;
        }
}
void printAll(){
    int i;
    char bookGenreHeader[50];
    for(i = 1; i<6; i++){
        BookInfoPtr headX = getHead(i);
        if(headX != NULL){
        assignBookHeader(i,bookGenreHeader);
        printf("%s","\n");
        printf("\t\t%s\n", bookGenreHeader);
        printf("%s\n","^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");}
        else continue;
        printGenre(i);
        
    }
}