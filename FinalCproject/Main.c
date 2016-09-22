//access to global variables and prepocessor Directives 
#include "Header.h"	

struct login
{
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
};
//create an array of login structures
struct login users[MAX_USERS];

void main()
{
	//struct pointer for type survey and variables declarations 
	struct survey* top;
	bool validData = 0;
	int l;
	int choice;
	char ch;
	int i;
	char firstName[30];
	

	FILE *fptr;//pointer declarations


	//bool successful = false;

	loadUserData();//Load in usernames/passwords from text files
	//add function to read file and add employees to linked list

	do
	{
		validData = askForUserData(); //ask and keep asking for username/password until a correct one is entered
	} while (validData == 0);
	
	//like 2 splash screens 
	for (l = 0; l<80; l++)//
	{
		printf("\xdb");// design bar 
	}
	printf("\n");
	for (l = 0; l<80; l++)
	{
		printf("\xdb");
	}
	system("color 1a");//color text 1 is blue and a is green 

	printf("\t \n");
	printf("\t   **WELCOME TO GMIT SURVEY **\n");
	printf("\t\t By Alan Heanue\n\n");
	printf("Custom-surveys Ltd. currently performs surveys in Ireland and has \n");
	printf("requested you to develop a new survey program for them.\n");
	printf("\n\tPLEASE ENTER ANY KEY TO CONTINUE");
	for (l = 0; l<5; l++)
	{
	printf(".");
	Sleep(500);//after printing one . another comes after 0.5 seconds
	}
	_getch();
	system("cls");//clears the screen
	printf("\n");
	for (l = 0; l<80; l++)
	{
	printf("\xdb");
	}
	system("color 1a");
	printf("\n\n\t** WELCOME TO SURVEY MENU WILL APPEAR BELOW **\n\n\n");
	for (l = 0; l<80; l++)

	{printf("\xdb");}

	printf("\nPLEASE WAIT A SECOND \n");
	for (l = 0; l<5; l++)
	{
	printf(".");
	Sleep(500);//menu apears aftr 5 seconds 
	}
	top = NULL;//Initially set top to NULL
	printf("\t\t          Custom-surveys Ltd.              \n");
	printf("\t\t                                           \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 1 to Add Survey ->               \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 2 to Display all surveys to screen->\n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 3 to Display Survey ->           \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 4 to Update an Survey ->         \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 5 to Delete Survey ->            \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 6 for Survey STATS ->            \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press 7 Print to file ->               \n");
	printf("\t\t                                           \n");
	printf("\t\t <- Press -1 to Exit ->                    \n");
	printf("\t\t-------------------------------------------\n");
	printf("\t   \n\t\tENTER NUMBER FROM ABOVE== ");
	scanf("%d", &choice);//scan choice in using swich statement 
	while (choice != -1)//if its not -1 than select others
	{
	switch (choice)
	{
	case 1:addSurvey(&top);break; case 2:displayAll(top);break;
	case 3:displayDetails(top);break; case 4:updateSurvey(&top);break;
	case 5:deleteSurvey(&top);break;  case 6:Stats(top);break;
	case 7:printFile(top);break;
	} 

		//Print menu
		printf("\t\t          Custom-surveys Ltd.              \n");
		printf("\t\t                                           \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 1 to Add Survey ->               \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 2 to Display all surveys to screen->\n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 3 to Display Survey ->           \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 4 to Update an Survey ->         \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 5 to Delete Survey ->            \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 6 for Survey STATS ->            \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press 7 Print to file ->               \n");
		printf("\t\t                                           \n");
		printf("\t\t <- Press -1 to Exit ->                    \n");
		printf("\t\t                                           \n");
		printf("\t\t    \n\n\t\tENTER NUMBER FROM ABOVE= = ");
		printf("\n\nEnter Choice (-1 to exit): ");
		scanf("%d", &choice);
} 
saveList(top);//saves in struct survey top 
_getch();
}
void loadUserData()//loading in data from text files for username/password
{
	FILE * fru;                       //declare pointers for read to files
	FILE * frp;
	fru = fopen(USERNAME_FILE, "r");  //open files
	frp = fopen(PASSWORD_FILE, "r");

	if (fru == NULL || frp == NULL)   //check if the files exist
	{
		printf("\t\tFile could not be opened");
	}
	else
	{
		//Read in the data from file into the members of my array of login structures
		int i = 0;

		while (fscanf(fru, "%s", users[i].username) != EOF)//loop through username.txt
		{
			++i;
		}

		i = 0;

		while (fscanf(frp, "%s", users[i].password) != EOF)//loop through password.txt
		{
			++i;
		}

		fclose(fru);//close the files
		fclose(frp);
	}
}

//function that asks for username/password
bool askForUserData()
{
	char password[MAX_LENGTH];
	int i = 0, l;
	char ch;
	char username[MAX_LENGTH];

	for (l = 0; l<10; l++)//
	
	printf("\n");
	for (l = 0; l<10; l++)
	
	system("color 1a");

	printf("\n\n                                   username = alan1  password = enter1 ");
	printf("\n\n                            6 Character Username and Password - Case Sensitive");

	printf("\n\n                                              Enter Username: ");
	fflush(stdin);
	scanf("%s", username);

	printf("\n                                              Enter Password: ");

	//Changes each letter of password to an * and also takes backspace into account
	while (1)
	{
		ch = _getch();

		if (ch == ENTER || ch == TAB)//when user hit enter or tab a number corresponds to those keys
		{
			password[i] = '\0'; //add the null character
			break;
		}
		else if (ch == BACKSPACE)//if user hits backspace
		{
			if (i > 0)
			{
				--i;              //de-increment
				printf("\b \b"); //and print the backspace
			}
		}
		else
		{
			password[i++] = ch;
			printf("* \b");
		}
	}

	//Compares the username/password entered with the ones read in from the files.
	for (i = 0; i < MAX_USERS; ++i)
	{
		if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
		{
			printf("\n\n                                      Correct Username and Password");
			return 1;
		}
	}

	printf("\n\n                                       Incorrect Username and Password");
	return 0;
}

void Stats(struct survey* head_ptr)
{
	int i, j;
	struct survey *temp;
	temp = head_ptr;
	



	//12 array
	int brackets[12] = { 0 };
	int nonSmokers[12] = { 0 }; int smoke20[12] = { 0 }; int smoke40[12] = { 0 }; int smoke40Plus[12] = { 0 };
	//Exercise array
	int nonExercisers[12] = { 0 }; int exercise3[12] = { 0 }; int exercise5[12] = { 0 };int exercise5Plus[12] = { 0 };
	//Alcohol arry
	int nonDrinker[12] = { 0 }; int drink2[12] = { 0 };int drink4[12] = { 0 }; int drink4Plus[12] = { 0 };


	
	while (temp != NULL)
	{
		
		for (i = 1; i <= 5; i++)
		{
			if (temp->ageBracket == i)
			{
				//Gets total number of people per age 
				switch (i)
				{
				case 1:
					brackets[0]++;
					break;
				case 2:
					brackets[1]++;
					break;
				case 3:
					brackets[2]++;
					break;
				case 4:
					brackets[3]++;
					break;
				case 5:
					brackets[4]++;
					break;
				} //end switch   
				for (j = 1; j <= 4; j++)
				{
					//Cigarettes
					if (temp->smokePerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonSmokers[i - 1]++;
							break;
						case 2:
							smoke20[i - 1]++;
							break;
						case 3:
							smoke40[i - 1]++;
							break;
						case 4:
							smoke40Plus[i - 1]++;
							break;
						} //end switch
					} //end if

					//Exercise
					if (temp->exercisePerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonExercisers[i - 1]++;
							break;
						case 2:
							exercise3[i - 1]++;
							break;
						case 3:
							exercise5[i - 1]++;
							break;
						case 4:
							exercise5Plus[i - 1]++;
							break;
						} //end switch
					} //end if

					//Alcohol
					if (temp->alcoholPerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonDrinker[i - 1]++;
							break;
						case 2:
							drink2[i - 1]++;
							break;
						case 3:
							drink4[i - 1]++;
							break;
						case 4:
							drink4Plus[i - 1]++;
							break;
						} //end switch
					} //end if
				} //end for (j)

			} //end if (age == i)

		} //end for (i)

		// Count Stats based on Income
		for (i = 1; i <= 7; i++)
		{
			if (temp->incomeBracket == i)
			{
				switch (i)
				{
				case 1:
					brackets[5]++;
					break;
				case 2:
					brackets[6]++;
					break;
				case 3:
					brackets[7]++;
					break;
				case 4:
					brackets[8]++;
					break;
				case 5:
					brackets[9]++;
					break;
				case 6:
					brackets[10]++;
					break;
				case 7:
					brackets[11]++;
					break;
				} //end switch

				//Get number of people in each category
				for (j = 1; j <= 4; j++)
				{
					//Cigarettes
					if (temp->smokePerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonSmokers[i + 4]++;
							break;
						case 2:
							smoke20[i + 4]++;
							break;
						case 3:
							smoke40[i + 4]++;
							break;
						case 4:
							smoke40Plus[i + 4]++;
							break;
						} //end switch
					} //end if

					//Exercise
					if (temp->exercisePerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonExercisers[i + 4]++;
							break;
						case 2:
							exercise3[i + 4]++;
							break;
						case 3:
							exercise5[i + 4]++;
							break;
						case 4:
							exercise5Plus[i + 4]++;
							break;
						} //end switch
					} //end if

					//Alcohol
					if (temp->alcoholPerWeek == j)
					{
						switch (j)
						{
						case 1:
							nonDrinker[i + 4]++;
							break;
						case 2:
							drink2[i + 4]++;
							break;
						case 3:
							drink4[i + 4]++;
							break;
						case 4:
							drink4Plus[i + 4]++;
							break;
						} //end switch
					} //end if

				} //end for (j)

			} //end if 

		} // end 

		//increment to next list position
		temp = temp->next;
	} //end while


	printf("\n\t******************************************************************");

	printf("\n\t                     ***************************                  ");

	printf("\n\t*********************        Statistics     *******************");

	printf("\n\t                     ***************************                  ");

	printf("\n\t******************************************************************");
	
	printf("\n\t 1: Ages 18 - 20\n\t 2: Ages 20 - 30\n\t 3: Ages 30 - 50\n\t 4: Ages 50 - 65\n\t 5: Ages 65+");

	printf("\n\t 6: No income\n\t 7: Less than 20,000 Income\n\t 8: Less than 40,000 Income\n\t 9: Less than 60,000 Income");

	printf("\n\t 10: Less than 80,000 Income\n\t 11: Less than 100,000 Income\n\t 12: Greater than 100,000 Income\n\n");

	for (i = 0; i < 12; i++)//print ones thats inserted 
	{
		//prints value null if below 0 
		if ((float)nonSmokers[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d are Non Smokers", ((float)nonSmokers[i] / brackets[i] * 100), (i + 1));

		if ((float)smoke20[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d smoke less than 20 Cigarettes per week", ((float)smoke20[i] / brackets[i] * 100), (i + 1));

		if ((float)smoke40[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d smoke less than 40 Cigarettes per week", ((float)smoke40[i] / brackets[i] * 100), (i + 1));

		if ((float)smoke40Plus[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d smoke greater than 40 Cigarettes per week", ((float)smoke40Plus[i] / brackets[i] * 100), (i + 1));

		if ((float)nonExercisers[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d never exercise", ((float)nonExercisers[i] / brackets[i] * 100), (i + 1));

		if ((float)exercise3[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d exercise 3 times per week", ((float)exercise3[i] / brackets[i] * 100), (i + 1));

		if ((float)exercise5[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d exercise 5 times per week", ((float)exercise5[i] / brackets[i] * 100), (i + 1));

		if ((float)exercise5Plus[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d exercise more than 5 times per week", ((float)exercise5Plus[i] / brackets[i] * 100), (i + 1));

		if ((float)nonDrinker[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d are Non Drinkers", ((float)nonDrinker[i] / brackets[i] * 100), (i + 1));

		if ((float)drink2[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d drink less than 2 units per week", ((float)drink2[i] / brackets[i] * 100), (i + 1));

		if ((float)drink4[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d drink less than 4 units per week", ((float)drink4[i] / brackets[i] * 100), (i + 1));

		if ((float)drink4Plus[i] / brackets[i] * 100 > 0)
			printf("\n%.2f percent of people in Bracket %d drink more than 4 units per week", ((float)drink4Plus[i] / brackets[i] * 100), (i + 1));
	}

} //end 
/* This Function Creates a New Employee(Node) and is inserted into the next available slot
in the Linked List.*/
void addSurvey(struct survey** head_ptr)
{
	//int ppsNumber = 0, length = 0;

	struct survey *newNode;//pointer to new node 
	char emailval[5] = ".com";
	//allocate a certain amount of memory for survey in the program 
	newNode = (struct survey*)malloc(sizeof(struct survey));
	printf("\nPPS Number(Must be unique): ");
	scanf("%d", &newNode->ppsNumber);
	printf("\nFirst Name: ");
	scanf("%s", newNode->firstName);
	printf("\nLast Name: ");
	scanf("%s", newNode->lastName);
	printf("\nAddress: ");
	scanf("%s", newNode->address);
do
	{
	printf("\nEmail Address(must contain an @,a full stop and a .com): ");
	scanf("%s", newNode->email);
	} 
//validation for email
while
	((strchr(newNode->email, '@') == NULL) || (strchr(newNode->email, '.') == NULL) || (strstr(newNode->email, emailval) == NULL));

	printf("\nAge: ");
	printf("\n\t\t <- Press 1 if you are between 18-20 yrs->");
	printf("\n\t\t <- Press 2 if you are between 20-30 yrs->");
	printf("\n\t\t <- Press 3 if you are between 30-50 yrs->");
	printf("\n\t\t <- Press 4 if you are between 50-65 yrs->");
	printf("\n\t\t <- Press 5 if you are between 65+ yrs->");
	printf("\t\t <- You have pressed = ");
	scanf("%d", &newNode->ageBracket);//assigns age to agebracket of newnodeptr 
	printf("\nIncome: ");
	printf("\n\tPress 1 No Income");
	printf("\n\tPress 2 Less Than 20,000");
	printf("\n\tPress 3 Less Than 40,000");
	printf("\n\tpress 4 Less Than 60,000");
	printf("\n\tPress 5 Less Than 80,000");
	printf("\n\tPress 6 Less Than 100,000");
	printf("\n\tPress 7 Greater Than 100,000");
	printf("\t\t <- You have pressed = ");
	scanf("%d", &newNode->incomeBracket);//assigns Income to incomebracket of newNode
	printf("\nHow often do you exercise: ");
	printf("\n\tPress 1 if Never");
	printf("\n\tPress 2 if Less Than 3 Times/week");
	printf("\n\tPress 3 if Less Than 5 Times/week");
	printf("\n\tPress 4 if More Than 5 Times/week");
	printf("\t\t <- You have pressed = ");
	scanf("%d", &newNode->exercisePerWeek);
	printf("\nHow much alcohol do you consume per week: ");
	printf("\n\tPress1 None");
	printf("\n\tPress 2 Less Than 2 Units");
	printf("\n\tPress 3 Less Than 4 Units");
	printf("\n\tPress 4 More Than 4 Units");
	printf("\t\t <- You have pressed = ");
	scanf("%d", &newNode->alcoholPerWeek);
	printf("\nHow many cigarettes do you smoke per week: ");
	printf("\n\tNone (1)");
	printf("\n\tLess Than 20 Cigarettes (2)");
	printf("\n\tLess Than 40 Cigarettes (3)");
	printf("\n\tMore Than 40 Cigarettes (4)");
	printf("\t\t <- You have pressed = ");
	scanf("%d", &newNode->smokePerWeek);
	newNode->next = *head_ptr;// move value from head to next 
	*head_ptr = newNode;//new address 
	sortSurvey(head_ptr);
}
void displayAll(struct survey* head_ptr)
{
	struct survey *temp;

	temp = head_ptr;

	while (temp != NULL)
	{
		printf("\n\nPPS Number: %d", temp->ppsNumber);
		printf("\nFirst Name: %s", temp->firstName);
		printf("\nLast Name: %s", temp->lastName);
		printf("\nAddress: %s", temp->address);
		printf("\nEmail: %s", temp->email);

		switch (temp->ageBracket)
		{
		case 1:
			printf("\nAge Bracket: 18 - 20 yrs");
			break;
		case 2:
			printf("\nAge Bracket: 20 - 30 yrs");
			break;
		case 3:
			printf("\nAge Bracket: 30 - 50 yrs");
			break;
		case 4:
			printf("\nAge Bracket: 50 - 65 yrs");
			break;
		case 5:
			printf("\nAge Bracket: 65+ yrs");
			break;
		}

		switch (temp->incomeBracket)
		{
		case 1:
			printf("\nIncome Bracket: No income");
			break;
		case 2:
			printf("\nIncome Bracket: Less Than 20,000");
			break;
		case 3:
			printf("\nIncome Bracket: Less Than 40,000");
			break;
		case 4:
			printf("\nIncome Bracket: Less Than 60,000");
			break;
		case 5:
			printf("\nIncome Bracket: Less Than 80,000");
			break;
		case 6:
			printf("\nIncome Bracket: Less Than 100,000");
			break;
		case 7:
			printf("\nIncome Bracket: Greater Than 100,000");
			break;
		}

		switch (temp->exercisePerWeek)
		{
		case 1:
			printf("\nExercise PerWeek: Never");
			break;
		case 2:
			printf("\nExercise PerWeek: Less Than 3 Times");
			break;
		case 3:
			printf("\nExercise PerWeek: Less Than 5 Times");
			break;
		case 4:
			printf("\nExercise PerWeek: More Than 5 Times");
			break;
		}

		switch (temp->alcoholPerWeek)
		{
		case 1:
			printf("\nAlcohol PerWeek: None");
			break;
		case 2:
			printf("\nAlcohol PerWeek: Less Than 2 Units");
			break;
		case 3:
			printf("\nAlcohol PerWeek: Less Than 4 Units");
			break;
		case 4:
			printf("\nAlcohol PerWeek: More Than 4 Units");
			break;
		}

		switch (temp->smokePerWeek)
		{
		case 1:
			printf("\nCigarettes PerWeek: None");
			break;
		case 2:
			printf("\nCigarettes PerWeek: Less Than 20");
			break;
		case 3:
			printf("\nCigarettes PerWeek: Less Than 40");
			break;
		case 4:
			printf("\nCigarettes PerWeek: More Than 40");
			break;
		}

		temp = temp->next;
	}
}
//displays a specific survey you want on to the screen 
void displayDetails(struct survey* head_ptr)
{
	struct survey *temp;
	int pps;
	temp = head_ptr;
	printf("\nEnter PPS Number: ");//ask for pps
	scanf("%d", &pps);

	//loop through linked list
	while (temp != NULL)
	{
	if (pps == temp->ppsNumber)
	{
			//Print Survey Details
			printf("\n\nPPS Number: %d", temp->ppsNumber);
			printf("\nFirst Name: %s", temp->firstName);
			printf("\nLast Name: %s", temp->lastName);
			printf("\nAddress: %s", temp->address);
			printf("\nEmail: %s", temp->email);

			switch (temp->ageBracket)
			{
			case 1:
				printf("\nAge 18 - 20 yrs");
				break;
			case 2:
				printf("\nAge 20 - 30 yrs");
				break;
			case 3:
				printf("\nAge 30 - 50 yrs");
				break;
			case 4:
				printf("\nAge  50 - 65 yrs");
				break;
			case 5:
				printf("\nAge 65+ yrs");
				break;
			}

			switch (temp->incomeBracket)
			{
			case 1:
				printf("\nIncome  No income");
				break;
			case 2:
				printf("\nIncome  Less Than 20,000");
				break;
			case 3:
				printf("\nIncome  Less Than 40,000");
				break;
			case 4:
				printf("\nIncome  Less Than 60,000");
				break;
			case 5:
				printf("\nIncome  Less Than 80,000");
				break;
			case 6:
				printf("\nIncome  Less Than 100,000");
				break;
			case 7:
				printf("\nIncome  Greater Than 100,000");
				break;
			}

			switch (temp->exercisePerWeek)
			{
			case 1:
				printf("\nExercise PerWeek: Never");
				break;
			case 2:
				printf("\nExercise PerWeek: Less Than 3 Times");
				break;
			case 3:
				printf("\nExercise PerWeek: Less Than 5 Times");
				break;
			case 4:
				printf("\nExercise PerWeek: More Than 5 Times");
				break;
			}

			switch (temp->alcoholPerWeek)
			{
			case 1:
				printf("\nAlcohol PerWeek: None");
				break;
			case 2:
				printf("\nAlcohol PerWeek: Less Than 2 Units");
				break;
			case 3:
				printf("\nAlcohol PerWeek: Less Than 4 Units");
				break;
			case 4:
				printf("\nAlcohol PerWeek: More Than 4 Units");
				break;
			}

			switch (temp->smokePerWeek)
			{
			case 1:
				printf("\nCigarettes PerWeek: None");
				break;
			case 2:
				printf("\nCigarettes PerWeek: Less Than 20");
				break;
			case 3:
				printf("\nCigarettes PerWeek: Less Than 40");
				break;
			case 4:
				printf("\nCigarettes PerWeek: More Than 40");
				break;
			}

			//return from function
			return;
		}
		else
		{
			//increment to next list element
			temp = temp->next;
		}
	} //end while

	printf(" Not Found");

}
//updates a specic survey allows user to update all information on that survey
void updateSurvey(struct survey** head_ptr)
{
	struct survey *temp;
	int pps;
	char emailval[5] = ".com";

	temp = *head_ptr;

	//Enter pps number
	printf("\n\t                     ***************************                  ");
	printf("\n\t*********************        UpdateSurvey        *******************");
	printf("\n\t                     ***************************                  ");
	printf("\nEnter Survey PPS Number: ");
	scanf("%d", &pps);

	//loop through list
	while (temp != NULL)
	{
		if (pps == temp->ppsNumber)
		{
			//Enter new details
			printf("\nEnter new PPS Number: ");
			scanf("%d", &temp->ppsNumber);

			//enter new name..etc
			printf("\nEnter First Name: ");
			scanf("%s", temp->firstName);

			printf("\nEnter Last Name: ");
			scanf("%s", temp->lastName);

			printf("\nEnter Address: ");
			scanf("%s", temp->address);

			do
			{
				//Validate email address
				//Keep asking for email while strchr() and strstr() functions are returning NULL
				printf("\nEnter Email Address: ");
				scanf("%s", temp->email);
			} while ((strchr(temp->email, '@') == NULL) || (strchr(temp->email, '.') == NULL) || (strstr(temp->email, emailval) == NULL));

			printf("\nAge Bracket: ");
			printf("\n\t18-20 yrs (1)");
			printf("\n\t20-30 yrs (2)");
			printf("\n\t30-50 yrs (3)");
			printf("\n\t50-65 yrs (4)");
			printf("\n\t65+ yrs (5)");
			printf("\nEnter option (1-5): ");
			scanf("%d", &temp->ageBracket);

			printf("\nIncome Bracket: ");
			printf("\n\tNo Income (1)");
			printf("\n\tLess Than 20,000 (2)");
			printf("\n\tLess Than 40,000 (3)");
			printf("\n\tLess Than 60,000 (4)");
			printf("\n\tLess Than 80,000 (5)");
			printf("\n\tLess Than 100,000 (6)");
			printf("\n\tGreater Than 100,000 (7)");
			printf("\nEnter option (1-7): ");
			scanf("%d", &temp->incomeBracket);

			printf("\nHow often do you exercise: ");
			printf("\n\tNever (1)");
			printf("\n\tLess Than 3 Times/week (2)");
			printf("\n\tLess Than 5 Times/week (3)");
			printf("\n\tMore Than 5 Times/week (4)");
			printf("\nEnter option (1-4): ");
			scanf("%d", &temp->exercisePerWeek);

			printf("\nHow much alcohol do you consume per week: ");
			printf("\n\tNone (1)");
			printf("\n\tLess Than 2 Units (2)");
			printf("\n\tLess Than 4 Units (3)");
			printf("\n\tMore Than 4 Units (4)");
			printf("\nEnter option (1-4): ");
			scanf("%d", &temp->alcoholPerWeek);

			printf("\nHow many cigarettes do you smoke per week: ");
			printf("\n\tNone (1)");
			printf("\n\tLess Than 20 Cigarettes (2)");
			printf("\n\tLess Than 40 Cigarettes (3)");
			printf("\n\tMore Than 40 Cigarettes (4)");
			printf("\nEnter option (1-4): ");
			scanf("%d", &temp->smokePerWeek);

			//re-sort the list
			sortSurvey(head_ptr);

			//return from function
			return;
		}
		else
		{
			//increment to next list element
			temp = temp->next;
		}
	} //end while

	printf("Survey Not Found");
}
//This frees up the head node to make space 
void delete(struct survey** head_ptr)
{
	
	struct survey *next_node = NULL;
	if (*head_ptr == NULL)
	{printf("Nothing to delete");}
	else
	{
	next_node = (*head_ptr)->next;
	free(*head_ptr);
	*head_ptr = next_node;
	}
}
//gives user cahnce to delete a survey by inputting pps 
void deleteSurvey(struct survey** head_ptr)
{
	// Declaration of types of Variables, Pointers and Struct size allocation
	struct survey *current = *head_ptr;
	struct survey *temp = NULL;
	int i;
	int pps;
	int index = 0;
	printf("\nEnter PPS Number You want to delete: ");
	scanf("%d", &pps);
	//goes threw nodes finds it and deletes.
	while (current != NULL)
	{
	if (current->ppsNumber == pps)
	{
	break;
	}
    index++;
	current = current->next;
	}
	if (current == NULL)
	{
	printf("not there try again ");
	return; 
	}
	if (index == 0)
	{
	delete(head_ptr);
	printf("\nDeleted survey with PPS Number: %d", pps);
	return;
	}
	current = *head_ptr;
	for (i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
	{
	printf("\nNode does not exist");
	return; 
}
current = current->next;
}
temp = current->next;     current->next = temp->next;
free(temp);
printf("\nDeleted survey with PPS Number: %d", pps);
}
//Locates the nodes b4 point of insertion 
void sortSurvey(struct survey** head_ptr)
{
	struct survey *temp;
	struct survey *temp2;
	int i, j;int tempPPS;char tempFirstName[15];char tempLastName[15];char tempAddress[30];char tempEmail[30];
	int tempAgeBracket;int tempIncomeBracket;int tempExercisePerWeek;int tempAlcoholPerWeek;int tempSmokePerWeek;
	temp = *head_ptr;
	temp2 = temp->next;
	do
	{
	j = 0;
	while (temp2 != NULL)
		{
		if (temp->ppsNumber > 0)
			{ 
				if (temp->ppsNumber > temp2->ppsNumber)
				{
					//loop
j = 1;
tempPPS = temp->ppsNumber; temp->ppsNumber = temp2->ppsNumber; temp2->ppsNumber = tempPPS;

strcpy(tempFirstName, temp->firstName); strcpy(temp->firstName, temp2->firstName); strcpy(temp2->firstName, tempFirstName);

strcpy(tempLastName, temp->lastName); strcpy(temp->lastName, temp2->lastName); strcpy(temp2->lastName, tempLastName);

strcpy(tempAddress, temp->address); strcpy(temp->address, temp2->address); strcpy(temp2->address, tempAddress);

strcpy(tempEmail, temp->email); strcpy(temp->email, temp2->email); strcpy(temp2->email, tempEmail);

tempAgeBracket = temp->ageBracket; temp->ageBracket = temp2->ageBracket;temp2->ageBracket = tempAgeBracket;

tempIncomeBracket = temp->incomeBracket; temp->incomeBracket = temp2->incomeBracket;	temp2->incomeBracket = tempIncomeBracket;

tempExercisePerWeek = temp->exercisePerWeek; temp->exercisePerWeek = temp2->exercisePerWeek; temp2->exercisePerWeek = tempExercisePerWeek;

tempAlcoholPerWeek = temp->alcoholPerWeek; temp->alcoholPerWeek = temp2->alcoholPerWeek; temp2->alcoholPerWeek = tempAlcoholPerWeek;

tempSmokePerWeek = temp->smokePerWeek; temp->smokePerWeek = temp2->smokePerWeek; temp2->smokePerWeek = tempSmokePerWeek;
}
}
temp = temp->next;
			temp2 = temp->next;
} //end 

} while (j == 1);
}

