#ifndef model
    #define model
     
    /*function declaration.*/
    typedef enum {Romantic = 1, Thriller, Horror , SciFi, Cooking} Genre;

typedef struct bookInfo{
    char bookName[50];
    char author[50];
    unsigned int index;
    int isBooked; // 0 for unbooked , 1 for booked
    Genre genre;
    int rating;

    struct bookInfo *next;

}BookInfo;

typedef BookInfo *BookInfoPtr;


BookInfoPtr getHead();
void setHead(BookInfoPtr *);

#endif