
#include<stdio.h>
#include "model.h"

static BookInfoPtr head = NULL;
BookInfoPtr getHead(){
   return head; 
}
void setHead(BookInfoPtr * ptr){
    head = *ptr;
}

