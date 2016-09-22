#include "Header.h"
//Prints the Actual Values of the LinkedlIst to File
void printFile(struct survey* head_ptr)
{
	FILE *fptr;
	struct survey *temp;
	temp = head_ptr;
	fptr = fopen("surveyReport.txt", "w");
	if (fptr == NULL)
	{
	printf("Error printing to file - surveyReport.txt");
	return;
	}
	else
	{
		while (temp != NULL)
		{
			
			fprintf(fptr, "\n\t******************************************************************");

			fprintf(fptr, "\n\t                    ***************************                  ");

			fprintf(fptr, "\n\t*********************   SURVEY REPORT     *******************");

			fprintf(fptr, "\n\t                     ***************************                  ");

			fprintf(fptr, "\n\t******************************************************************");
			fprintf(fptr, "\t\nPPS : %d", temp->ppsNumber);
			fprintf(fptr, "\t\nFirst Name: %s", temp->firstName);
			fprintf(fptr, "\t\nLast Name: %s", temp->lastName);
			fprintf(fptr, "\t\nAddress: %s", temp->address);
			fprintf(fptr, "\t\nEmail: %s", temp->email);
			fprintf(fptr, "\n\t******************************************************************");
			switch (temp->ageBracket)
			{
			case 1:
				fprintf(fptr, "\nAge Bracket: 18 - 20 yrs");
				break;
			case 2:
				fprintf(fptr, "\nAge Bracket: 20 - 30 yrs");
				break;
			case 3:
				fprintf(fptr, "\nAge Bracket: 30 - 50 yrs");
				break;
			case 4:
				fprintf(fptr, "\nAge Bracket: 50 - 65 yrs");
				break;
			case 5:
				fprintf(fptr, "\nAge Bracket: 65+ yrs");
				break;
			}

			switch (temp->incomeBracket)
			{
			case 1:
				fprintf(fptr, "\nIncome Bracket: No income");
				break;
			case 2:
				fprintf(fptr, "\nIncome Bracket: Less Than 20,000");
				break;
			case 3:
				fprintf(fptr, "\nIncome Bracket: Less Than 40,000");
				break;
			case 4:
				fprintf(fptr, "\nIncome Bracket: Less Than 60,000");
				break;
			case 5:
				fprintf(fptr, "\nIncome Bracket: Less Than 80,000");
				break;
			case 6:
				fprintf(fptr, "\nIncome Bracket: Less Than 100,000");
				break;
			case 7:
				fprintf(fptr, "\nIncome Bracket: Greater Than 100,000");
				break;
			}

			switch (temp->exercisePerWeek)
			{
			case 1:
				fprintf(fptr, "\nExercise PerWeek: Never");
				break;
			case 2:
				fprintf(fptr, "\nExercise PerWeek: Less Than 3 Times");
				break;
			case 3:
				fprintf(fptr, "\nExercise PerWeek: Less Than 5 Times");
				break;
			case 4:
				fprintf(fptr, "\nExercise PerWeek: More Than 5 Times");
				break;
			}

			switch (temp->alcoholPerWeek)
			{
			case 1:
				fprintf(fptr, "\nAlcohol PerWeek: None");
				break;
			case 2:
				fprintf(fptr, "\nAlcohol PerWeek: Less Than 2 Units");
				break;
			case 3:
				fprintf(fptr, "\nAlcohol PerWeek: Less Than 4 Units");
				break;
			case 4:
				fprintf(fptr, "\nAlcohol PerWeek: More Than 4 Units");
				break;
			}

			switch (temp->smokePerWeek)
			{
			case 1:
				fprintf(fptr, "\nCigarettes PerWeek: None");
				break;
			case 2:
				fprintf(fptr, "\nCigarettes PerWeek: Less Than 20");
				break;
			case 3:
				fprintf(fptr, "\nCigarettes PerWeek: Less Than 40");
				break;
			case 4:
				fprintf(fptr, "\nCigarettes PerWeek: More Than 40");
				break;
			}
			//increment
			temp = temp->next;
		}
		printf("\n\t                     ***************************                  ");
		printf("\n\t********************Survey Report File Successful*******************");
		printf("\n\t                     ***************************                  ");
		//printf("\nSurvey Report File Successful.\n");
		fclose(fptr);
	}

}
/* writeFile Function: Prepares the printSurveys function by putting in survey nodes
into the file pointer */
void saveList(struct survey* head_ptr)
{
	FILE *fptr;
	struct survey *temp;

	//Open file in write mode
	fptr = fopen("survey.txt", "w");

	if (fptr == NULL)// if pointer is full
	{
		printf("\n\nError Saving to file Survey.txt");
		return;
	}
	else
	{
		temp = head_ptr;

		while (temp != NULL)//loop through the linked list 
		{
			fprintf(fptr, "\n%d", temp->ppsNumber);fprintf(fptr, "\n%s", temp->firstName);fprintf(fptr, "\n%s", temp->lastName);
			fprintf(fptr, "\n%s", temp->address);fprintf(fptr, "\n%s", temp->email);fprintf(fptr, "\n%d", temp->ageBracket);
			fprintf(fptr, "\n%d", temp->incomeBracket);fprintf(fptr, "\n%d", temp->exercisePerWeek);fprintf(fptr, "\n%d", temp->alcoholPerWeek);
			fprintf(fptr, "\n%d", temp->smokePerWeek);//print all out to file 

			
			temp = temp->next;//increment through the list 
		}

		printf("\n\nSurvey Information saved to file - \"survey.txt\"");
		fclose(fptr);
	}
}

