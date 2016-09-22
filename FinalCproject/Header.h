//Survey using Linked list yr 2 project Alan Heanue G00318763
//This gets rid of warnings which tell you to use certain functions E.G scanf_s
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS//Disables warning without going to settings 
typedef int bool;//Typedef for boolean values
//defining a boolean type
#define FALSE 0
#define TRUE 1
//constants
#define USERNAME_FILE "username.txt"
#define PASSWORD_FILE "password.txt"         //Files
#define MAX_LENGTH 20
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define MAX_USERS 3						//mostly for pasword and users 
#define MAX_LENGTH 20

//library functions 
#include <stdio.h>//Input/Output Functions
#include <stdlib.h>//general functions 
#include <time.h>//date funtions not needed for this as not using dates or time 
#include <string.h>//strings 
#include <Windows.h> //not used but this for adjusting window size and pop ups 
#include <conio.h>

struct survey//**This is shell for the linked list that makes up the survey database**
{	
int ppsNumber;
char firstName[30];
char lastName[30];
char address[30];
char email[30];
int ageBracket;
int incomeBracket;
int exercisePerWeek;
int alcoholPerWeek;
int smokePerWeek;
struct survey* next;//It is pointer field which stores the address of another structure 
};

void loadUserData();                         //defined inside Main.c
bool askForUserData();

//prototypes 
/* This Function Creates a New Survey(Node) and is inserted into the next available slot
in the Linked List.*/
void addSurvey(struct survey** head_ptr);
//displays all in the program 
void displayAll(struct survey* head_ptr);

void displayDetails(struct survey* head_ptr);
void updateSurvey(struct survey** head_ptr);
void delete(struct survey** head_ptr);
void deleteSurvey(struct survey** head_ptr);
void Stats(struct survey* head_ptr);
void sortSurvey(struct survey** head_ptr);


//ReadAndWriteFies
void printFile(struct survey* head_ptr);
void saveList(struct survey* head_ptr);



#endif