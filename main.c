#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "model.h"
#include "search.h"
#include "mainUI.h"
#include "insert.h"
#include "readWriteFiles.h"
    



int main(){
    readIntoLinkedList();
    welcomeMessage();
    registrationWindow();
    mainMenu();
    
    return 0;
}