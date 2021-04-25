#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"


// getting ptr to list and the word to search
BookInfoPtr searchBook(BookInfoPtr *ptr, char word[]){
   
    // bookptr first=malloc(sizeof(Book));
    //int location=0;
    BookInfoPtr current= *ptr;//initalize  pointer current to first node
    //(*current)->next= NULL;//will be removed when we have insert function
    while (current!=NULL)
    {
        if (strcmpi(current->bookName,word) == 0)//check if two strings are the same by this function
        {
            //start printing data to user
            //printf("EXSIS");
           return current;
           

        }
        current = current->next;
        //++location;
        
    }
    
    if (current==NULL)//delivered to null without breaking this means no books found
    {
        //printf("There is no book with this name\n");
        return NULL;
    }
    
}

/*
void searchauthor(BookInfoPtr *ptr,char word[50]){
    int flag=0;
    int location=0;
    BookInfoPtr current= *ptr;//initalize  pointer current to first node
    (current)->next=NULL;
    while (current!=NULL)
    {
        if (strcmpi((current)->author,word)==0)//check if two strings are the same by this function 
        {
            //start printing data to user
            display(current);
            flag=1;//cause there are many books for one author

        }
        current=current->next;
        location++;
        
    }
    
    if (!flag)//didnt find any book and ok is still zero
    {
        printf("There are no books for this author\n");
    }
   

}


*/