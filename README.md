# ******* PROJECT DUE SHEET *********

Autumn Advanced Procedural Programming Assignment
Due Date: Thursday 19th August 2022
ABC Dental Practice Ltd currently manually store patient records but have requested you to develop
a new patient record application for them.
This program will create a database which will store the details of all the patients in the practice. In
addition to storing all the patient data, the application should allow overall patient statistics to be
generated.
Your program should create the database (which for your purpose MUST be implemented as a linked
list) and be able to save, restore, retrieve, add, delete and update patient details.
For each patient , you will store the following details:
• PPS Number (Assume an integer – must be unique)
• First Name
• Second Name
• Year Born
• Gender
• Email Address (must contain an @, a full stop and a .com)
• Next of Kin Name
• Last Appointment
• Weight
• Height
• Does the patient has any allergies to any medications:
▪ Yes
▪ No
• How many cigarettes would you smoke per day?
▪ None
▪ Less than ten cigarettes
▪ More than ten cigarettes
The system is password protected, and only the correct username and password details will allow the
user to gain access to the system.
The username and password (6 characters in length) will be stored in a login structure which is read
in from a login file which holds three login records. Ensure that when the user enters the password
that it cannot be seen on the screen. (It only shows a * for each character. E.g. ******)
Your program should initialise the linked list based on the patient profiles stored in the patient.txt file.
This file should be updated when the user terminates the program.
Your program should provide a menu as follows:
1) Add patient (Note: PPS Number must be unique).
2) Display all patient details to screen
3) Display patient details
4) Update a patient details
5) Delete patient
6) Generate statistics (A-D) based on the user selecting one of the criteria listed in I
A. % of patients with a BMI of less than 18.5
B. % of patients with a BMI of less than 25
C. % of patients with a BMI of less than 30
D. % of patients with a BMI of greater than 30
I. How many cigarettes would you smoke per day
7) Print all patient details into a report file.
8) List all the patient of the following countries in order of their last appointment:
Add Patient: This will add a new patient in your linked list. The PPS number must be unique. If it is
not a unique PPS number.
Display all patient details to screen: Display all patient information to screen
Display patient details: Allow the user to input either a PPS number or a Patient Name and display
the details for that patient.
Update Patient: Allows the user to update patient details based on either a name or pps number being
entered.
Delete Patient: Allows the user to delete a patient from the list by PPS number.
Print all Patient Details into a report file: Display a patient report which outputs the following
information of the patients to file:
• All patient details
• Patient Statistics (based upon item 6 of the menu)
Validation:
Your program should perform validation on all menu inputs.
Project Submission
Each student must submit the code developed to support the application. In addition to the code, a
screencast should be included in the submission, demonstrating the solution's complete functionality
Submission Deadline
Project Submissions to be submitted by email to martin.hynes@gmit.ie by 11.59pm on the 19th August
2022.
NOTES:
• Your project must be written using the C programming language.
• You must implement the customer’s database as a linked list.
• Comments expected.
• The reuse of code through functions is expected. Each section of the assignment should be
structured within its own function, passing parameters as necessary.
• You should create and populate a login file with sample data to allow successful validation of user
credentials which you will then read into your login linked list.
• Ensure that any files that are needed to run the program are included in your submission.
• Use of onscreen messages to inform the user is expected.
• Your code has to run. Serious deduction of marks will occur for code that is not running correctly.
• Plagiarism is not acceptable. You will be asked to explain your code.
• Late Submissions will be deducted by 5% per day. This will be accumulative – e.g. A student
who submits their work three days late will be given a deduction of 15%.
