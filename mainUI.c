#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "model.h"
#include "search.h"
#include "mainUI.h"
#include "insert.h"


void showBook(BookInfo ptr){
            printf("%s","This book data is\n");
            printf("Book name:%s\n",ptr.bookName);
            printf("author:%s\n",ptr.author);
            printf("index of the book:%d\n",ptr.index);
            printf("rating of the book:%d\n",ptr.rating);
            printf("genre:%d\n",ptr.genre);
            printf("isBooked:%s\n",(ptr.isBooked==0)?"Not booked":"Booked");

}


void inline searchSelection(int select){
    printf("%s1) Search By Book\n",select == 0? "=> ":"");
    printf("%s2) Search By Author\n",select == 1? "=> ":"");
    printf("%s3) Back \n",select == 2? "=> ":"");
}

void searchByBook(){
    //extern BookInfoPtr head;
    char bookName[50];
    printf("%s","Enter the book name:\t");
    scanf("%s", bookName);
    BookInfoPtr headX = getHead();
    BookInfoPtr result = searchBook(&headX,bookName);
    if(result == NULL) printf("%s", "No book with this name");
    else showBook(*result);
    system("pause");
}
void searchByAuthor(){}


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
            else if(select == 1){searchByAuthor();}
            else{
                system("cls");
                mainMenu(); // Escaping the while loop to terminte the program
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
    }while(1); // Make the loop true and escape using a condition inside the loop

}

void AddBook(){
    system("cls");
    BookInfo book;
    BookInfoPtr headX = getHead();
    puts("\t\t\t***ADDING NEW BOOK***");
    do
    {
        printf("%s","1) Book Name: ");
        scanf("%s",book.bookName);
        if(searchBook(&headX, book.bookName) != NULL){
            system("cls");
             printf("%s is already exsist\n", book.bookName);
             }
    } while (searchBook(&headX, book.bookName) != NULL);
    
    printf("%s","2) Author Name: ");
    scanf("%s",book.author);


    int genre;
do
{
    
    printf("%s\n","3) Book Genre: ");
    printf("%s\n","\t 1-Romantic 2-Thriller 3-Horror 4-SciFi 5-Cooking");
    scanf("%d",&genre);

} while (genre<1 || genre>5);
    book.genre = genre;


    printf("%s","4) Book Index: ");
    scanf("%u",&book.index);

    do
    {
        printf("%s","4) Book Rating (1:10): ");
        scanf("%d",&book.rating);
    } while (book.rating > 10 || book.rating < 1);
    

    
    printf("%p",headX);
    insertFirst(&headX,book);
    setHead(&headX);
    printf("%p",headX);

    showBook(book);
    system("pause");
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
    printf("%s3) hello \n",select ==2? "=> ":"");
    printf("%s4) Quit \n",select == 3? "=> ":"");
}


void exitProgram(){
    puts("\t\t***THANK YOU FOR USING OUR HUMBLE PROGRAM***");
    
    int i = 0, j = 0;
    for (i = 0; i < 100000; i++)
        for (j = 0; j < 15000; j++);
    exit(0);
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
            else if(select == 2){}
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

