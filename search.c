#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "model.h"
#include "mainUI.h"


// getting ptr to list and the word to search
BookInfoPtr searchBook(BookInfoPtr *ptr, char word[]){
   
    BookInfoPtr current= *ptr;//initalize  pointer current to first node
    while (current!=NULL)
    {
        if (strcmpi(current->bookName,word) == 0)//check if two strings are the same by this function
        {
            //start printing data to user
           return current;
           

        }
        current = current->next;
        
    }
    
    if (current==NULL)//delivered to null without breaking this means no books found
    {
        return NULL;
    }
    else return current;
    
}


// getting ptr to list and the word to search
BookInfoPtr searchIndex(int index){

            int genre;
            char indexString[20];
            itoa(index, indexString, 10);
            indexString[1] = '\0';
            genre = atoi(indexString);
            BookInfoPtr headX = getHead((Genre) genre);
                
    while (headX!=NULL)
    {
        if ( headX->index  == index)//check if two strings are the same by this function
        {
            //start printing data to user
           return headX;
           

        }
        headX = headX->next;
        
    }
    
    if (headX==NULL)//delivered to null without breaking this means no books found
    {
        return NULL;
    }
    else return headX;
    
}


void searchauthor(char word[50]){
    int flag=0, i,j = 1;
    for (i = 1; i < 6; i++)
    {
        BookInfoPtr current= getHead((Genre) i); //initalize  pointer current to first node
    while (current!=NULL)
    {
        if (!strcmpi(current->author,word))//check if two strings are the same by this function 
        {
            //start printing data to user
            printf("%s\n","******************************************");
            printf("%d\n",j++);
            showBook(*current);
            flag=1;//cause there are many books for one author
            getch();

        }
        current=current->next;
        
    }
    if (!flag)//didnt find any book and ok is still zero
    {
        printf("There are no books for this author\n");
        getch();
        return;
    }
   
    }
    
    

}


