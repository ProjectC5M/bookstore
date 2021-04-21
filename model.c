
#include<stdio.h>

typedef enum {Romantic = 1 , Action =2, Horror =3} Genre;

typedef struct bookInfo{
    char bookName[50];
    char author[50];
    unsigned int index[5];
    int isBooked; // 0 for unbooked , 1 for booked
    Genre genre;
    int rating;

    struct bookInfo *next;
} BookInfo;