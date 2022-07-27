#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include <conio.h>

typedef struct node
{
	//List Database Variables
	int pps_number;
	char first_name[30];
	char last_name[30];
	int year_born;
	int gender;
	char email_address[30];
	char next_kin_name[30];
	int last_appointment;
	int weight;
	int height;
	int allergic_reactions;
	int cigarretes_count;
	
	struct node* NEXT;
}nodeT;

struct node* createNode();

//Declaring Functions for program
void displayList(nodeT* top);
void statisticsFunction(struct node* top, char charchoice);

void displayListNumbered(nodeT* top);
int listLength(nodeT* top);
int search(nodeT* top, int searchVal);
int CheckForPps(nodeT* top, int check_pps);
//int search(nodeT* top);
void addAtTheEndList(struct node* top);
void addAtTheStartList(struct node** top);
void deleteAtEnd(struct node* top);
void deleteAtStart(struct node** top);
void addAtTheLocation(struct node* top, int location);
void outputToFile(struct node* top);
void deleteAtLocation(struct node* top, int location);
void ReadDatabase(struct node* top);
void UserLogin(struct node* top);

void main()
{
	nodeT* headPtr = NULL;
	nodeT* newNode;
	nodeT* temp = NULL;

	//Local Variables for main()
	int length = 0;
	int found;
	int searchNum;
	int choice;
	char charchoice;
	int result;
	int loc;
	int searchID;
	int searchVal;
	int location;
	int check_pps;

	
	//LOGIN SYSTEM
	UserLogin(headPtr);

	//Read Database file to load saved entries
	ReadDatabase(headPtr);

	//print new line
	printf("\n");

	//Print options to console
	printf("1) Add patient(Note: PPS Number must be unique).\n");
	printf("2) Display all patient details to screen\n");
	printf("3) Display patient details\n");
	printf("4) Update a patients details\n");
	printf("5) Delete Patient\n");
	printf("6) Generate statistics\n");
	printf("7) Print all patient details into a report file.\n");
	printf("8) List all the patient of the following countries in order of their last appointment.\n");

	//take input of choice that user has made
	scanf_s("%d", &choice);

	//while loop for understanding which option the user has chosen and which function to run
	while (choice != -1)
	{

		if (choice == 1)
		{
			//run function that checks if the inputted pps number exists in linked database
			result = CheckForPps(headPtr, &searchVal);
			
			//if this number exists doesn't continue program
			if (result == 13) {
				printf("this pps number exists - please choose another one \n");
			}
			else {
				addAtTheStartList(&headPtr);
			}
		}

		else if (choice == 2)
		{
			displayList(headPtr);
		}

		else if (choice == 3)
		{
			result = search(headPtr, &searchVal);
		}

		else if (choice == 4)
		{
			displayListNumbered(headPtr);
			
			printf("Please enter the location\n");
			scanf_s("%d", &loc);

			addAtTheLocation(headPtr, &location);
		}

		else if (choice == 5)
		{
			displayListNumbered(headPtr);
			printf("Please enter the location\n");
			scanf_s("%d", &loc);

			printf("%d", headPtr);

			if (loc<0 || loc>(listLength(headPtr) - 1))
			{
				printf("The location is out of range\n");
			}

			else if (loc == 0)
			{
				deleteAtStart(&headPtr);
			}

			else if (loc == (listLength(headPtr) - 1))
			{
				deleteAtEnd(headPtr);
			}

			else
			{
				deleteAtLocation(headPtr, loc);
			}

		}

		else if (choice == 6)
		{
			printf("Please choose how you want to generate your statistics below : \n(A-D) based on the user selecting one of the criteria listed in I\n\t\tA. Percentage of patients with a BMI of less than 18.5\n\t\tB. Percentage of patients with a BMI of less than 25\n\t\tC. Percentage of patients with a BMI of less than 30\n\t\tD. Percentage of patients with a BMI of greater than 30\n\n\t\t\nPlease input A,B,C OR D of what you want to generate for:");
		
			scanf_s(" %c", &charchoice, 1);
			printf(" %c\n", charchoice);

			statisticsFunction(headPtr, charchoice);

			//YOU ARE HERE

			if (charchoice == 'a') {
				printf('A. Percentage of patients with a BMI of less than 18.5');
			}

			if (charchoice == 'b') {
				printf('B. Percentage of patients with a BMI of less than 25');
			}

			if (charchoice == 'c') {
				printf('C. Percentage of patients with a BMI of less than 30');
			}

			if (charchoice == 'd') {
				printf('D. Percentage of patients with a BMI of greater than 30');
			}

		}

		else if (choice == 7)
		{
			outputToFile(headPtr);
		}

		else if (choice == 8)
		{
			if (headPtr == NULL)
			{
				printf("You can not delete from an empty list\n");
			}
			else if (listLength(headPtr) == 1)
			{
				deleteAtStart(&headPtr);
			}
			else
			{
				deleteAtEnd(headPtr);
			}
		}

		//Displaying each option again for user after they have selected the funciton already and we're starting this loop again
		printf("1) Add patient(Note: PPS Number must be unique).\n");
		printf("2) Display all patient details to screen\n");
		printf("3) Display patient details\n");
		printf("4) Update a patients details\n");
		printf("5) Delete Patient\n");
		printf("6) Generate statistics\n");
		printf("7) Print all patient details into a report file.\n");
		printf("8) List all the patient of the following countries in order of their last appointment.\n");
		scanf_s("%d", &choice);
	}

}

//Function for displaying every entry in linked list database 
void displayList(nodeT* top)
{
	struct node* temp;

	temp = top;

	printf(" | | |* * * * * * * * * * * * * * * * * * * * * * * * * \n");
	while (temp != NULL)
	{
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("PPS Number : %d \nFirst Name : %s\nSecond Name : %s\nYear Born : %d\nGender : %d\nEmail Address : %s\nNext of Kin : %s\nLast appointment : %d\nWeight : %d\nHeight : %d\nDoes the patient have allergies : %d\nHow many cigarettes smoked per day : % d\n\n", temp->pps_number, temp->first_name, temp->last_name, temp->year_born, temp->gender, temp->email_address, temp->next_kin_name, temp->last_appointment, temp->weight, temp->height, temp->allergic_reactions, temp->cigarretes_count);
		temp = temp->NEXT;
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * \n");
	}
	printf("\n | | | * * * * * * * * * * * * * * * * * * * * * * * * * \n");
}

//Function for statistics - finding BMI and displaying in console
void statisticsFunction(nodeT* top, char charchoice)
{
	struct node* temp;

	temp = top;

	printf(" | | |* * * * * * * * * * * * * * * * * * * * * * * * * \n");
	while (temp != NULL)
	{
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("Statistics For PPS number : %d\n", temp->pps_number);

		temp = temp->NEXT;
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * \n");
	}
	printf("\n | | | * * * * * * * * * * * * * * * * * * * * * * * * * \n");
}

//Function for listing each entry in the database with a number beside it / useful for showing to user and allowing them to input which entry they want for that function
void displayListNumbered(nodeT* top)
{
	struct node* temp;

	temp = top;

	int i = 0;

	while (temp != NULL)
	{
		printf("%d. PPS Number : %d | Name : %s %s\n", i, temp->pps_number, temp->first_name, temp->last_name);
		temp = temp->NEXT;
		i++;
	}
}

//Function for finding length of linked list  / ie how many entries are in this linked list database
int listLength(nodeT* top)
{
	struct node* temp = top;
	int count = 0;

	while (temp != NULL)
	{
		count = count + 1;
		temp = temp->NEXT;
	}

	return count;
}

//Function for searching and displaying desired element from linked list database
int search(nodeT* top, int searchVal)
{
	printf("please input the pps number of the client you are searching for : \n");
	scanf_s("%d", &searchVal);
	printf("%d\n\n",searchVal);

	struct node* temp = top;
	int found = -1;
	int count = 0;


	while (temp != NULL)
	{
		printf("%d / %d\n\n", temp->pps_number, &searchVal);

		if (temp->pps_number == searchVal)
		{
			found = count;
			printf("Your entry is as follows : \n");
			printf("PPS NUMBER IS : %d\n",temp->pps_number);
			printf("PATIENT FIRST NAME IS : %s\n", temp->first_name);
			printf("PATIENT LAST NAME IS  : %s\n", temp->last_name);
			printf("PATIENT BORN IN YEAR : %d\n", temp->year_born);

			if (temp->gender == 0) {
				printf("PATIENT GENDER IS : MALE\n");
			}
			else {
				printf("PATIENT GENDER IS : FEMALE\n");
			}

		}

		temp = temp->NEXT;
		count++;
	}

	printf("\n\n COUNT IS %d \n \n", count);

	return found;
}

//Function for adding list element at start of linked list database
void addAtTheStartList(struct node** top)//(nodeT* top, int check_pps)
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter the patient's pps number : \n");
	scanf_s("%d", &newNode->pps_number);

	printf("Please enter the patient's first name : \n");
	scanf("%s", newNode->first_name);

	printf("Please enter the patient's last name : \n");
	scanf("%s", newNode->last_name);

	printf("What year was the patient born? : \n");
	scanf("%d", &newNode->year_born);

	printf("What gender is the patient? : 0 for Male , 1 for Female\n");
	scanf("%d", &newNode->gender);

	printf("What is the user's email : \n");
	scanf("%s", newNode->email_address);

	printf("What is the name of the next of kin of the patient ? : \n");
	scanf("%s", newNode->next_kin_name);

	printf("When was the patients last appointment FORMAT DD/MM/YY : \n");
	scanf("%s", &newNode->last_appointment);

	printf("What is the patient's weight? : \n");
	scanf("%d", &newNode->weight);

	printf("What is the patient's Height? : \n");
	scanf("%d", &newNode->height);

	printf("Does the patient have any allergies to medications? 1 for yes 0 for no : \n");
	scanf("%d", &newNode->allergic_reactions);

	printf("How many cigarretes does the patient smoke per day? 0 for none 1 for less than ten 2 for more than 10 : \n");
	scanf("%d", &newNode->cigarretes_count);

	printf("User Creation Function Finished \n\n\n\n");

	newNode->NEXT = *top;
	*top = newNode;

}

//Function for deleting list entry at end of linked list
void deleteAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* prev = NULL;

	while (temp->NEXT != NULL)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = NULL;
	free(temp);
}

//Function for deleting linked list entry at start of linked list
void deleteAtStart(struct node** top)
{
	struct node* temp = *top;

	*top = (*top)->NEXT;

	free(temp);
}

//Function for creating a node / useful for creating elements
struct node* createNode()
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));

	//Option 1
	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter the patient's pps number : \n");
	scanf_s("%d", &newNode->pps_number);

	printf("Please enter the patient's first name : \n");
	scanf("%s", newNode->first_name);

	printf("Please enter the patient's last name : \n");
	scanf("%s", newNode->last_name);

	printf("What year was the patient born? : \n");
	scanf("%d", &newNode->year_born);

	printf("What gender is the patient? : 0 for Male , 1 for Female\n");
	//ADD MORE LOGIC CODE HERE
	scanf("%d", &newNode->gender);

	printf("What is the user's email : \n");
	scanf("%s", newNode->email_address);

	printf("What is the name of the next of kin of the patient ? : \n");
	scanf("%s", newNode->next_kin_name);

	printf("When was the patients last appointment FORMAT DD/MM/YY : \n");
	scanf("%s", &newNode->last_appointment);

	printf("What is the patient's weight? : \n");
	scanf("%d", &newNode->weight);

	printf("What is the patient's Height? : \n");
	scanf("%d", &newNode->height);

	printf("Does the patient have any allergies to medications? 1 for yes 0 for no : \n");
	scanf("%d", &newNode->allergic_reactions);

	printf("How many cigarretes does the patient smoke per day? 0 for none 1 for less than ten 2 for more than 10 : \n");
	scanf("%d", &newNode->cigarretes_count);

	return newNode;
}

//Function for reading login file and offering dialog for user to input username and password and checking that against linked list databse
void UserLogin(struct node* top)
{
	//login creds	

	//USER ONE
	char username[30];
	char UserPassword[15];
	char UsernameInput[30];
	char PasswordInput[15];

	struct node* temp = NULL;
	struct node* prev = NULL;
	nodeT* newPatientEntry;

	FILE* fp;

	fp = fopen("UserDB.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {
			fscanf(fp, "%s %s\n", username, UserPassword);
		}

		printf("\n\nINTERESTING: USER %s \n PASS %s . \n", username, UserPassword);

		system("CLS");

		int LoginRun = 0;
		while (LoginRun == 0) {
			printf("Please enter your username:\n");
			scanf("%s", &UsernameInput);

			printf("password:\n");
			int p = 0;
			do {
				PasswordInput[p] = getch();
				if (PasswordInput[p] != '\r') {
					printf("*");
				}
				p++;
			} while (PasswordInput[p - 1] != '\r');
			PasswordInput[p - 1] = '\0';
			getch();

			if ((strcmp(username, UsernameInput) == 0) && (strcmp(PasswordInput, UserPassword) == 0)) {
				LoginRun = 1;
				system("CLS");
				printf("\nLOGGED IN\n");
			}
			else {
				system("CLS");
				printf("\nINCORRECT USERNAME OR PASSWORD \n");
			}
		}

	} else {
		printf("No Accounts available to login to.\n");
	}
}

//Function for reading entries in from text file
void ReadDatabase(struct node** top)
{
	struct node* temp = NULL;
	struct node* prev = NULL;
	nodeT* newPatient;

	FILE* fp;

	fp = fopen("client.txt", "r");
	if (fp == NULL) {
		printf("File does not exist or could not be opened\n");
	} else {
		//Loops through the file reading in all informtion to an entry in the list
		//Echoes the outputToFile function
		
		while (!feof(fp))
		{
			newPatient = (struct node*)malloc(sizeof(struct node));
			fscanf(fp, "%d %s %s %d %d %s %s %d %d %d %d %d\n", &newPatient->pps_number, &newPatient->first_name, &newPatient->last_name, &newPatient->year_born, &newPatient->gender, &newPatient->email_address, &newPatient->next_kin_name, &newPatient->last_appointment, &newPatient->weight, &newPatient->height, &newPatient->allergic_reactions, &newPatient->cigarretes_count);
			printf("%d %s %s\n", newPatient->pps_number, &newPatient->first_name, &newPatient->last_name);
			newPatient->NEXT = temp;
			temp = newPatient;

			prev = temp;
			temp = newPatient;
			newPatient->NEXT = prev;
		}

		fclose(fp);
	}
	return temp;
}

//Function for outputting linked list into text file
void outputToFile(struct node* top)
{
	struct node* temp;
	FILE* fp;
	temp = top;

	fp = fopen("client.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "%d %s %s %d %d %s %s %d %d %d %d %d\n", temp->pps_number, temp->first_name, temp->last_name, temp->year_born, temp->gender, temp->email_address, temp->next_kin_name, temp->last_appointment, temp->weight, temp->height, temp->allergic_reactions, temp->cigarretes_count);
		}

		temp = temp->NEXT;
	}

	if (fp != NULL)
	{
		fclose(fp);
		printf("File saved!\n");
		exit;
	}
}

//Function for deleting entry in linked list at particular location
void deleteAtLocation(struct node* top, int location)
{
	struct node* temp = top;
	struct node* prev = NULL;
	int i;

	for (i = 0; i < location; i++)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = temp->NEXT;
	free(temp);
}

//Function for adding entry at location in linked list
void addAtTheLocation(struct node* top, int location)
{
	struct node* temp = top;
	struct node* newNode;
	int i;

	newNode = createNode();

	for (i = 0; i < location - 1; i++)
	{
		temp = temp->NEXT;
	}

	newNode->NEXT = temp->NEXT;
	temp->NEXT = newNode;
}

/*
void addAtTheLocation(struct node* top, int location)
{
	struct node* temp = top;
	struct node* newNode;
	int i;


	//Option 2
	//
	newNode = createNode();

	for (i = 0; i < location - 1; i++)
	{
		temp = temp->NEXT;
	}


	newNode->NEXT = temp->NEXT;
	temp->NEXT = newNode;
}*/

//This function is to check if the passed pps (check_pps) exists in the linked list
int CheckForPps(nodeT* top, int check_pps)
{
	printf("Please input pps number you want to check \n");
	scanf("%d", &check_pps);

	struct node* temp = top;
	int found = -1;
	int count = 0;


	while (temp != NULL)
	{
		if (temp->pps_number == check_pps)
		{
			found = count;
			printf("Sorry - but there already exists a patient with that pps number \n");
			return 13;
		}

		temp = temp->NEXT;
		count++;
	}

}
