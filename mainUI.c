#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "model.h"
#include "search.h"
#include "insert.h"
#include "readWriteFiles.h"
#include "print.h"
#include "deleteBook.h"
#include "mainUI.h"

char* intToGenreString(int i){
    switch (i)
    {
    case 1:
        return "Romantic";
        break;
    
    case 2:
        return "Thriller";
        break;
    
    case 3:
        return "Horror";
        break;
    
    case 4:
        return "SciFi";
        break;
    
    case 5:
        return "Cooking";
        break;
    default: return "";
    break;
    }
}

void showBook(BookInfo ptr){
            printf("%s","This book\'s data is\n");
            printf("Book name: %s\n",ptr.bookName);
            printf("Author: %s\n",ptr.author);
            printf("Index of the book: %d\n",ptr.index);
            printf("Rating of the book: %d\n",ptr.rating);
            printf("Genre: %s\n", intToGenreString(ptr.genre));
            printf("State: %s\n",(ptr.isBooked==0)?"Not booked":"Booked");

}


void inline deleteBookMenuSelection(int isBooked ,int select){
    printf("%s1) Delete Book\n",select == 0? "=> ":"");
    printf("%s2) %s Book\n",select == 1? "=> ":"" ,isBooked? "Return" : "Book" );
    printf("%s3) Back \n",select == 2? "=> ":"");
}

void deleteBookMenu(BookInfo ptr){

    int select = 0;
    do{
    puts("\t\t\t***SEARCH BOOKS***");
    showBook(ptr);
    puts("***************");
        deleteBookMenuSelection(ptr.isBooked ,select);

        int c = getch(); //getch is different from getchar ----- getch is NOT a standard function
        //getch() is used to fetch any character from the keyboard

        // \r is the character of Enter Key (selecting a value)
        //

        if(c =='\r'){
            
             if(select == 0){int result = deletedBook(ptr);
                if(result){
                    printf("%s", "DELETED");
                    getch();
                    system("cls");
                    mainMenu();
                }
                else{
                     printf("%s", "ERROR OCCURED");
                    getch();
                    system("cls");
                    mainMenu();
                }
             }
            else if(select == 1){
                int result = bookABook(ptr);
                if(result){
                    printf("%s", ptr.isBooked?"Returned":"Booked");
                    getch();
                    system("cls");
                    searchMenu();
                }
                else{
                     printf("%s", "ERROR OCCURED");
                    getch();
                    system("cls");
                    searchMenu();
                }
            }
            else{
                system("cls");
                searchMenu(); 
            }
        }

        else{
            switch(c){
            case 72:{ // 72 is the value of UP ARROW
                switch(select){
                    case 0: {select = 2; break;}
                    case 1: {select = 0; break;}
                    case 2: {select = 1; break;}
                    default: break;
                }
                break;
            }
            case 80:{ // 80 is the value of DOWN ARROW
                switch (select) {
                case 0:{ select = 1;break;}
                case 1:{ select = 2; break;}
                case 2:{ select = 0; break;}
                default:break;
                }
                break;
            }
        }
        }
        
    system("cls");
    }while(1); 





}

void inline searchSelection(int select){
    printf("%s1) Search By Book\n",select == 0? "=> ":"");
    printf("%s2) Search By Index\n",select == 1? "=> ":"");
    printf("%s3) Search By Author\n",select == 2? "=> ":"");
    printf("%s4) Back \n",select == 3? "=> ":"");
}

void searchByBook(){
     char index;
    do
    {
        printf("%s\n","\t 1-Romantic 2-Thriller 3-Horror 4-SciFi 5-Cooking");
        printf("%s","Enter the book genre: ");
        scanf(" %c",&index);
    } while (index < '1' || index > '5');
        Genre genre = atoi(&index);
    char bookName[50];
    printf("%s","Enter the book name: ");
    scanf("%s", bookName);
    BookInfoPtr headX = getHead(genre);
    BookInfoPtr result = searchBook(&headX,bookName);
    //printf("%s", ((*result))->author);
    if(result == NULL) printf("%s", "No book with this name");
    else {
    system("cls");
    deleteBookMenu(*result);
    }
    getch();
}


void searchByIndex(){
    int index;
    printf("%s","Enter the index: ");
    scanf("%d", &index);
    BookInfoPtr result = searchIndex(index);
    if(result == NULL) printf("%s", "No book with this index");
    else {
    system("cls");
    deleteBookMenu(*result);
    }
    getch();
}

void searchByAuthor(){
    char authorName[50];
    printf("%s","Enter the author name: ");
    scanf("%s", authorName);
    searchauthor(authorName);
}


void searchMenu(void){
    int select = 0;
    do{
    puts("\t\t\t***SEARCH BOOKS***");
        
        searchSelection(select);

        int c = getch(); //getch is different from getchar ----- getch is NOT a standard function
        //getch() is used to fetch any character from the keyboard

        // \r is the character of Enter Key (selecting a value)
        //

        if(c =='\r'){
            
             if(select == 0){searchByBook();}
            else if(select == 1){searchByIndex();}
            else if(select == 2){searchByAuthor();}
            else{
                system("cls");
                mainMenu(); // Escaping the while loop to terminte the program
            }
        }

        else{
            switch(c){
            case 72:{ // 72 is the value of UP ARROW
                switch(select){
                    case 0: {select = 3; break;}
                    case 1: {select = 0; break;}
                    case 2: {select = 1; break;}
                    case 3: {select = 2; break;}
                    default: break;
                }
                break;
            }
            case 80:{ // 80 is the value of DOWN ARROW
                switch (select) {
                case 0:{ select = 1;break;}
                case 1:{ select = 2; break;}
                case 2:{ select = 3; break;}
                case 3:{ select = 0; break;}
                default:break;
                }
                break;
            }
        }
        }
        
    system("cls");
    }while(1); // Make the loop true and escape using a condition inside the loop

}



void AddBook(){
    system("cls");
    BookInfo book;
    BookInfoPtr headX;
    puts("\t\t\t***ADDING NEW BOOK***");

    //genre is first to be able to add in the refered linked-list head
    char genre;
    do
    {
        
        printf("%s\n","1) Book Genre: ");
        printf("%s\n","\t 1-Romantic 2-Thriller 3-Horror 4-SciFi 5-Cooking");
        scanf(" %c",&genre);

    } while (genre < '1' || genre > '5');
        book.genre = atoi(&genre);
         headX = getHead(book.genre);

    do
    { //Can't duplicate the same book in the same genre
        printf("%s","2) Book Name: ");
        scanf("%s",book.bookName);
        if(searchBook(&headX, book.bookName) != NULL){
            //system("cls");
             printf("%s is already exsist\n", book.bookName);
             }
    } while (searchBook(&headX, book.bookName) != NULL);
    
    printf("%s","3) Author Name: ");
    scanf("%s",book.author);



    //Should search the index first
    do
    { //Can't duplicate the same book in the same genre
        printf("%s","4) Book Index: ");
        
    scanf("%u",&book.index);
    char genreString[20];
    itoa((int)book.genre, genreString, 10);

    char indexString[20];
    itoa(book.index, indexString, 10);
    
    strcat(genreString, indexString);
    //book.index = atoi(genreString);

        if(searchIndex(atoi(genreString)) != NULL){
             printf("%d is already exsist\n", book.index);
             }
    } while (searchIndex(book.index) != NULL);
    
    
    do
    {
        printf("%s","5) Book Rating (1:10): ");
        scanf("%d",&book.rating);
    } while (book.rating > 10 || book.rating < 1);
    

    
    insertFirst(&headX,book);
    setHead(&headX, book.genre);
    printf("%s \n", "Book Added");
    getch();
}
// a greating message introducing our names taking few seconds
void welcomeMessage(void)
{
    puts("\a\t\t**** WELCOME ****\t\t"); // \a is used to make the peep sound while \t to make a Tap space
    puts("\n\t PROTOTYPE OF BOOK STORE");
    puts("\n PREPERED BY:");
    puts("1) Mohamed Hossny");
    puts("2) Mohamed Ayman");
    puts("3) Mohamed Qurtam");
    puts("4) Mohamed Samy");
    puts("5) Micheal Mattrey");

    //Creating a junky loop to spend time (used as delay function)
    int i = 0, j = 0;
    for (i = 0; i < 100000; i++)
        for (j = 0; j < 15000; j++)
        {
        }
    system("cls"); //cleaning the window
    
}

void registrationWindow(void)
{
    const char userName[] = "admin";
    const char passWord[] = "5mAdmins";
    char getUserName[20];
    char getPassWord[20];
    do
    { // a do-while loop until the user enters the correct username and password
        puts("\t\t\t PLEASE ENTER THE USERNAME & THE PASSWORD");
        printf("%s", "USERNAME: ");
        scanf("%s", getUserName);
        printf("%s", "PASSWORD: ");
        int p = 0;
        do // replacing each character pressed by the user with astrek 
        {
            getPassWord[p] = getch();
            if (getPassWord[p] != '\r')
            {
                printf("%s", "*");
            }
            ++p;
        } while (getPassWord[p - 1] != '\r'); // p -1 not p as we increament p with 1;
        getPassWord[p - 1] = '\0';

        // showing wrong username or password message then cleaning the window again
        if (strcmp(getPassWord, passWord) || strcmp(getUserName, userName))
        {
            int i, j;
            system("cls");
            puts("\a\t\t\t ***WRONG USERNAME OR PASSWORD***");
            for (i = 0; i < 100000; i++)
                for (j = 0; j < 10000; j++)
                {
                }
            system("cls");
        }

    } while (strcmp(getPassWord, passWord) || strcmp(getUserName, userName));
    system("cls");
}


// Making the ui of the mainMenu
void inline selection(int select){
    printf("%s1) Search\n",select == 0? "=> ":"");
    printf("%s2) Add new book\n",select == 1? "=> ":"");
    printf("%s3) Print \n",select ==2? "=> ":"");
    printf("%s4) Quit \n",select == 3? "=> ":"");
}


void exitProgram(){
    writeFromLinkedList();
    puts("\t\t***THANK YOU FOR USING OUR HUMBLE PROGRAM***");
    
    int i = 0, j = 0;
    for (i = 0; i < 90000; i++)
        for (j = 0; j < 15000; j++);
    exit(0);
}

void inline printselection(int select){
    printf("%s1) Print Genre\n",select == 0? "=> ":"");
    printf("%s2) Print All\n",select == 1? "=> ":"");
    printf("%s3) back \n",select ==2? "=> ":"");
}

void printGenreMenu(){
    system("cls");
    puts("\t\t\t****PRINT GENRE****");
    char genre;
    do
    {
        
        printf("%s\n","\t 1-Romantic 2-Thriller 3-Horror 4-SciFi 5-Cooking");
        scanf(" %c",&genre);

    } while (genre < '1' || genre > '5');
        printGenre(atoi(&genre));
    
}

void printMenu(){
    system("cls");
    int select =0;
    do{
    puts("\t\t\t****PRINT BOOKS****");
        
        printselection(select);

        int c = getch(); //getch is different from getchar ----- getch is NOT a standard function
        //getch() is used to fetch any character from the keyboard

        // \r is the character of Enter Key (selecting a value)
        //

        if(c =='\r'){
            if(select == 0){printGenreMenu();}
            else if(select == 1){printAll();}
            else {system("cls");mainMenu();} 
        }

        else{
            switch(c){
            case 72:{ // 72 is the value of UP ARROW
                switch(select){
                    case 0: {select = 2; break;}
                    case 1: {select = 0; break;}
                    case 2: {select = 1; break;}
                    default: break;
                }
                break;
            }
            case 80:{ // 80 is the value of DOWN ARROW
                switch (select) {
                case 0:{ select = 1;break;}
                case 1:{ select = 2; break;}
                case 2:{ select = 0;break;}
                default:break;
                }
                break;
            }
        }
        }
        
    system("cls");
    }while(1);
}

void mainMenu(void){
    int select =0;
    do{
        
        selection(select);

        int c = getch(); //getch is different from getchar ----- getch is NOT a standard function
        //getch() is used to fetch any character from the keyboard

        // \r is the character of Enter Key (selecting a value)
        //

        if(c =='\r'){
            if(select == 0){
                system("cls");
                searchMenu();}
            else if(select == 1){AddBook();}
            else if(select == 2){printMenu();}
            else exitProgram(); // Escaping the while loop to terminte the program
        }

        else{
            switch(c){
            case 72:{ // 72 is the value of UP ARROW
                switch(select){
                    case 0: {select = 3; break;}
                    case 1: {select = 0; break;}
                    case 2: {select = 1; break;}
                    case 3: {select = 2; break;}
                    default: break;
                }
                break;
            }
            case 80:{ // 80 is the value of DOWN ARROW
                switch (select) {
                case 0:{ select = 1;break;}
                case 1:{ select = 2; break;}
                case 2:{ select = 3;break;}
                case 3:{ select = 0;break;}
                default:break;
                }
                break;
            }
        }
        }
        
    system("cls");
    }while(1); // Make the loop true and escape using a condition inside the loop
}

