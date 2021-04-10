#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
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

int getArrow(void)
{
    
    switch (c)
    {
        if (c == 72)
        { //72 is the int value represeting UP arrow
            puts("UP WAS PRESSED\n");
            break;
        }
    case 80:
    { //80 is the int value represeting DOWN arrow
        puts("DOWN WAS PRESSED\n");
        break;
    }
    }
}

// Making the ui of the mainMenu
void inline firstSelected(void){
    printf("%s", "=> 1) hello\n");
    printf("%s", "2) hello\n");
    printf("%s", "3) hello \n");
    printf("%s", "4) Quit \n");
}
void inline secondSelected(void){
    printf("%s", "1) hello\n");
    printf("%s", "=> 2) hello\n");
    printf("%s", "3) hello \n");
    printf("%s", "4) Quit \n");
}
void inline thirdSelected(void){
    printf("%s", "1) hello\n");
    printf("%s", "2) hello\n");
    printf("%s", "=> 3) hello \n");
    printf("%s", "4) Quit \n");
}
void inline forthSelected(void){
    printf("%s", "1) hello\n");
    printf("%s", "2) hello\n");
    printf("%s", "3) hello \n");
    printf("%s", "=> 4) Quit \n");
}

// Declearing and assiging a pointer pointing on an Array of functions
void (*selectionPtr[])() = { firstSelected, secondSelected,thirdSelected,forthSelected } ;

void mainMenu(void){
    int select =0;
    do{
        
        (*selectionPtr[select])();

        int c = getch(); //getch is different from getchar ----- getch is NOT a standard function
        //getch() is used to fetch any character from the keyboard

        // \r is the character of Enter Key (selecting a value)
        //

        if(c =='\r'){
            if(select == 3)
            break; // Escaping the while loop to terminte the program
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