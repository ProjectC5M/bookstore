
#include<stdio.h>
#include "model.h"

static BookInfoPtr head[5] = {NULL};

BookInfoPtr getHead(Genre genre){
   return head[(int) genre - 1 ]; 
}
void setHead(BookInfoPtr * ptr, Genre genre){    
    head[(int) genre - 1] = *ptr;
}

