/*
* Ian Corkill
* P2681678
This is a simple time calculator program, which will convert the user's input time into the desired output time. For example, the first option is to change the user's input of seconds to an output of hours.
*/

/*
Reference List:

Dawson, M. (2010) Beginning C++ Through Game Programming. 3rd Edition. Course Technology.
Gregoire, M. (2014) Proefssional C++. 3rd Edition. Indianapolis, Indiana. John Wiley & Sons, Inc.
Horton, J. (2016) Beginning C++ Game Programming. Birmingham, UK. Packt Publishing Ltd.
Pupius, R. (2015) SFML Game Development by Example. Birmingham, UK. Packt Publishing Ltd.
Schlögl, E., Dempster, M.A.H., Madan, D.B. (2014) Quantative Finance: An Object-Orientated Approach in C++. Boca Raton, FL. CRC Press LLC.
Stroustrup, B. (2014) Programming Principles and Practice Using C++. 2nd Edition. Pearson Addison Wesley.

*/

/*
Below are the SFML headers which have been used for this program. (Pupius, 2015. p.3)
These have been included (#include) so that the files are included before the program is compiled.
iostream is used for the input and output operations of the program, such as 'cin' to allow the user to input a value into the console and 'cout' to output the result. (Stroustrup, 2014. p.347-349)
This also includes the endl; function to seaprate input and output on the console, as well as the use of << for the flow on the output statement and >> for the flow of the input statement. (Schlögl, 2014. p.2)
*/

#include <iostream>

/*
Below is a list of the data types which have been used throughout the program. These are global variables which are used throughout the program to define certain parameters.
*/

using namespace std; // Using namespace std; allows the program to access variables and functions from the Standard Library. (Dawson, 2010. p.36)

char cMenuOption = 'F'; // char cMenuOption represents "character" and is presented, in this instance, by the single letter 'F'. (Dawson, 2010. p.18) This char is used in the systemMenu to confirm the user's choice to quit the program from the systemMenu.
char cQuitOption = 'Y'; // char cQuitOption represents "character" and is presented, in this instance, by the single letter 'Y'. This char is used in the quitProgram to confirm the user's choice of "Yes", after being prompted to confirm they wish to quit, to stop running the program.
bool bActive; // The boolean (bool) active represents the running of the whole program. A boolean will provide either a true or false statement. (Dawson, 2010. p.18) If the statement is true, then the program will continue to run. If the statement is false, the program will stop running.

float fTimeIn = 0.0; // The float fTImeIn is used to represent the user's input in each of the different segments of code. It is defined as a single floating point number. (Dawson, 2010. p.18) This has been defined as 0.0 initially, to give it a value.
float fSecsOut = 0.0; // The float fSecsOut is used to present the output for any of the calculations where seconds are the output. This has been defined as 0.0 initially, to give it a value.
float fMinsOut = 0.0; // The float fMinsOut is used to present the output for any of the calculations where minutes are the output. This has been defined as 0.0 initially, to give it a value.
float fHoursOut = 0.0; // The float fHoursOut is used to present the output for any of the calculations where hours are the output. This has been defined as 0.0 initially, to give it a value.

int iSecsMulti = 60; // The integer (int) (Dawson, 2010. p.18) iSecsMulti has been defined as 60 and is used in the calculation in minutes to seconds, where the user input is multiplied by 60.
int iMinsMulti = 60; // The int iMinsMUlti has been defined as 60 and is used in the seconds to minutes calculation. The user input is divided by 60. This is a similar value to the iSecsMUlti integer, but was created to differentiate between the calculations.
int iHoursMulti = 60; // The int iHoursMulti has been defined as 60 and is used in the minutes to hours calculation. The user input is divided by 60. This is similar to the above two integers, but was created to differentiate between the 3 calculations. 
int iSecsHoursMulti = 60 * 60; // The int iSecsHoursMulti has been defined as 60 multiplied by 60 and is used in the seconds to hours calculation. The user input is divided by (60*60).
int iHoursSecsMulti = 60 * 60; // The int iHoursSecsMulti has been defined as 60 multiplied by 60 and is used in the hours to seconds calculation. The user input is multiplied by (60*60).

/*
The below void function will operate when the user selects option A(a) from the menu. When selected, this will advise the user that they would like to convert seconds to hours and will ask the user to input the seconds.
If the user inputs a value of less than or equal to zero, the while loop will advise that this is an incorrect value and ask the user to input a new value which is greater than zero.
Once the user has input a calculable value, (not zero) the input time will be divided by secsHoursMulti (60x60), based on the calculation above the final cout.
The final cout statement will then remind the user of the seconds which were input (fTimeIn) and output the sum of the calculation (fHoursOut).
The system("pause"); will then pause the program and ask for user input to be taken back to the menu.
*/

void secondsToHours() // Stores the information to complete secondsToHours. The void function will not return a value, such as the main integer, as the program has not completed running. (Dawson, 2010. p.153)
{ // The curly brackets contain the code and are required.
	cout << "Please input the seconds you would like to convert to hours: " << endl; // Output message to prompt the user as to what is required by their input below. endl; will separate the output and inputs onto separate lines on the program when it has been run.

	cin >> fTimeIn; // User will input the seconds they want to convert to minutes.

	while (fTimeIn <= 0.0) // While the user input is equal to or less than 0.0, it will print the below output and ask the user for input again for a number other than zero. The while loop will keep running until the user input is false. In this instance, when the user inputs a number greater than zero. (Horton, 2016. p.111)
	{
		cout << "That is an invalid option. Please enter a new number other than zero: " << endl;
		cin >> fTimeIn;
	}

	fHoursOut = fTimeIn / iSecsHoursMulti; // Calculation to work out how many hours (output) there are in the amount of seconds (input). ((fTimeIn / (60*60)) = fHoursOut)) The / symbol indicates that division will occur.
	cout << "After converting " << fTimeIn << " seconds to hours, the result is " << fHoursOut << " hours." << endl; // Message will confirm the user's input once again and confirm the number of hours out. The output for fHoursOut has been left as a float, to provide a decimal output if required.

	system("pause"); // This will pause the statement and ask the user to input any key to continue back to the menu.	
}

/*
The below void function will operate when the user selects option B(b) from the menu. When selected, this will advise the user that they would like to convert seconds to minutes and will ask the user to input the seconds.
If the user inputs a value of less than or equal to zero, the while loop will advise that this is an incorrect value and ask the user to input a new value which is greater than zero.
Once the user has input a calculable value (not zero) the input time will be divided by minsMulti (60), based on the calculation above the final cout.
The final cout statement will then remind the user of the seconds which were input (fTimeIn) and output the sum of the calculation (fMinsOut).
The system("pause"); will then pause the program and ask for user input to be taken back to the menu.
*/

void secondsToMinutes() // Stores the information to complete secondsToMinutes.
{
	cout << "Please input the seconds you would like to convert to minutes: " << endl; // Output message to prompt the user as to what is required by their input below.

	cin >> fTimeIn; // User will input the seconds they want to convert to minutes.

	while (fTimeIn <= 0.0) // While the user input is equal to or less than 0.0, it will print the below output and ask the user for input again for a number other than zero.
	{
		cout << "That is an invalid option. Please enter a new number other than zero: " << endl;
		cin >> fTimeIn;
	}

	fMinsOut = fTimeIn / iMinsMulti; // Calculation to work out how many minutes (output) there are in the amount of seconds (input). (fTimeIn / 60 = fMinsOut)
	cout << "After converting " << fTimeIn << " seconds to minutes, the result is " << fMinsOut << " minutes." << endl; // Message will confirm the user's input once again and confirm the number of hours out. The output for fMinsOut has been left as a float, to provide a decimal output if required.

	system("pause"); // This will pause the statement and ask the user to input any key to continue back to the menu.
}

/*
The below void function will operate when the user selects option C(c) from the menu. When selected, this will advise the user that they would like to convert minutes to hours and will ask the user to input the minutes.
If the user inputs a value of less than or equal to zero, the while loop will advise that this is an incorrect value and ask the user to input a new value which is greater than zero.
Once the user has input a calculable value (not zero) the input time will be divided by hoursMulti (60), based on the calculation above the final cout.
The final cout statement will then remind the user of the seconds which were input (fTimeIn) and output the sum of the calculation (fHoursOut).
The system("pause"); will then pause the program and ask for user input to be taken back to the menu.
*/

void minutesToHours() // Stores the information to complete minutesToHours.
{
	cout << "Please input the minutes you would like to convert to hours: " << endl; // Output message to prompt the user as to what is required by their input below.

	cin >> fTimeIn; // User will input the minutes they want to convert to hours.

	while (fTimeIn <= 0.0) // While the user input is equal to or less than 0.0, it will print the below output and ask the user for input again for a number other than zero.
	{
		cout << "That is an invalid option. Please enter a new number other than zero: " << endl;
		cin >> fTimeIn;
	}

	fHoursOut = fTimeIn / iHoursMulti; // Calculation to work out how many hours (output) there are in the amount of minutes (input). (fTimeIn / 60 = fHoursOut)
	cout << "After converting " << fTimeIn << " minutes to hours, the result is " << fHoursOut << " hours." << endl; // Message will confirm the user's input once again and confirm the number of hours out. This output for fHoursOut has been left as a float, to provide a decimal output if required.

	system("pause"); // This will pause the statement and ask the user to input any key to continue back to the menu.
}

/*
The below void function will operate when the user selects option D(d) from the menu. When selected, this will advise the user that they would like to convert hours to seconds and will ask the user to input the hours.
If the user inputs a value of less than or equal to zero, the while loop will advise that this is an incorrect value and ask the user to input a new value which is greater than zero.
Once the user has input a calculable value (not zero) the input time will be divided by hoursSecsMulti (60x60), based on the calculation above the final cout.
The final cout statement will then remind the user of the seconds which were input (fTimeIn) and output the sum of the calculation (fSecsOut).
The forced integer (int)fSecsOut means that the result of the calculation will be presented as an integer rather than a float, once the calculation has been completed and output presented to the console.
The system("pause"); will then pause the program and ask for user input to be taken back to the menu.
*/

void hoursToSeconds() // Stores the information to complete hoursToSeconds.
{
	cout << "Please input the hours you would like to convert to seconds: " << endl; // Output message to prompt the user as to what is required by their input below.

	cin >> fTimeIn; // User will input the hours they want to convert to seconds.

	while (fTimeIn <= 0.0) // While the user input is equal to or less than 0.0, it will print the below output and ask the user for input again for a number other than zero.
	{
		cout << "That is an invalid option. Please enter a new number other than zero: " << endl;
		cin >> fTimeIn;
	}

	fSecsOut = fTimeIn * (iHoursSecsMulti); // Calculation to work out how many seconds (output) there are in the amount of hours (input). (fTimeIn * (60*60) = fSecsOut) The * symbol indicates that multiplication will occur.
	cout << "After converting " << fTimeIn << " hours into seconds, the result is " << (int)fSecsOut << " seconds." << endl; // Message will confirm the users input once again and force the output to be an integer (no decimal points).

	system("pause"); // This will pause the statement and ask the user to input any key to continue back to the menu.
}

/*
The below void function will operate when the user selects option E(e) from the menu. When selected, this will advise the user that they would like to convert minutes to seconds and will ask the user to input the minutes.
If the user inputs a value of less than or equal to zero, the while loop will advise that this is an incorrect value and ask the user to input a new value which is greater than zero.
Once the user has input a calculable value (not zero) the input time will be multiplied by secsMulti (60), based on the calculation above the final cout.
The final cout statement will then remind the user of the seconds which were input (fTimeIn) and output the sum of the calculation (fSecsOut).
The forced integer (int)fSecsOut means that the result of the calculation will be presented as an integer rather than a float, once the calculation has been completed and output presented to the console.
The system("pause"); will then pause the program and ask for user input to be taken back to the menu.
*/


void minutesToSeconds() // Stores the information to complete minutesToSeconds.
{
	cout << "Please input the minutes you would like to convert to seconds: " << endl; // Output message to prompt the user as to what is required by their input below.

	cin >> fTimeIn; // User will input the minutes they want to convert to seconds.

	while (fTimeIn <= 0.0) // While the user input is equal to or less than 0.0, it will print the below output and ask the user for input again for a number other than zero.
	{
		cout << "That is an invalid option. Please enter a new number other than zero: " << endl;
		cin >> fTimeIn;
	}

	fSecsOut = fTimeIn * iSecsMulti; // Calculation to work out how many seconds (output) there are in the amount of minutes (input). (fTimeIn * 60 = fSecsOut)
	cout << "After converting " << fTimeIn << " minutes into seconds, the result is " << (int)fSecsOut << " seconds." << endl; // Message will confirm the users input once again and force the output to be an integer (no decimal points).

	system("pause"); // This will pause the statement and ask the user to input any key to continue back to the menu.
}

/*
The below void function 'quitProgram' is actioned when the user selects option 'F' from the menu to quit the program.
The user will be prompted to enter the letter 'Y' to quit the program or the letter 'N' to not. The user can use the upper or lower case letters for Y and N for their input when quitting the program.
If the user inputs any other letter or a number, they will be advised that that is an incorrect input, via the if and else statement and will run the quitProgram void again.
*/

void quitProgram() // Stores the information to complete quitProgram.
{

	cout << "Please confirm that you would like to exit program by entering [Y] for yes or [N] for no. " << endl; // User will be asked to input a Y to confirm they want to leave the program or an N to confirm they do not want to.
	cin >> cQuitOption; // User will input Y, N or another letter.

	if (cQuitOption == 'y' || cQuitOption == 'Y') // The if statement advises that something will occur if the user types in a y or Y, in the event it is true when it is compared to the user input. This will only run once. (Dawson, 2010. p.40)
	{
		cout << "You have selected to exit the program. " << endl; // Output will advise the customer they have selected to leave the program.
		bActive = false; // The bool bActive has been set to false to confirm that the user no longer wants the program to run and to quit.
	}
	else if (cQuitOption == 'n' || cQuitOption == 'N') // The else if statement advises that something will occur if the user types in an n or N and is tested to see if this statement is true, compared to the user input. This will only run once. (Dawson, 2010. p.45)
	{
		cout << "You have opted to remain in the program. " << endl; // Output to advise the user they have opted to remain in the program.
		bActive = true; // The bool bActive has been set to true in this part of the if else statement, to confirm that the program is still active.
		system("pause"); // The system is paused at this point and awaits user input to be taken back to the systemMenu.
	}
	else // The else statement will happen if the user does not input an n/N or y/Y. If the if and else if statements are found to not be true when compared to the user input, then the else statement is run. This will only run once, however, due to linking quitProgram at the end of the else statement, it will bring it back to the start of the void function. (Dawson, 2010. p.48)
	{
		cout << "That is an invalid input. Please review the below statement. " << endl; // The user will be informed that this is an invalid option.
		quitProgram(); // quitProgram will run again and ask the customer to input a y/Y or n/N.
	}


}

/*
The below void function contains the code for the programs menu.
When the program is initialised, the user will be presented with the following cout statements, where the user will input a letter from A to F to select the option they want to use.
For example, if the user selects A, they will be advising the program that they would like to convert seconds to hours. This will then prompt the user what they have selected and initialise the void secondsToHours.
The switch statement allows the user to input lower or upper case letters, via cases, when selecting the relevant letters which will then activate the associated data type void.
A break used at the end of each switch statement, advises that once the void has been run, it will then go back to the start of the systemMenu void, asking the user to again input a letter from A to F to select another conversion tool or to exit the program.
System("CLS"); advises the program to clear the screen once the switch statements have been completed and the console window will then once again only show the option menu and ask the user for their input.
*/

void systemMenu() // Stores the information for systemMenu.
{

	system("CLS"); // Will clear the screen after every switch statement has been completed.

	cout << "Welcome to the Simple Time Calculator program. Please select an option from A to F: " << endl; // The first message the user will see when they start the program.
	cout << "**********************************" << endl; // Used to separate the first message from the options.
	cout << "[A] Converting seconds to hours" << endl; // Advises user to input the letter A to convert seconds to hours.
	cout << "[B] Converting seconds to minutes" << endl; // Advises user to input the letter B to convert seconds to minutes.
	cout << "[C] Converting minutes to hours" << endl; // Advises user to input the letter C to convert minutes to hours.
	cout << "[D] Converting hours to seconds" << endl; // Advises user to input the letter D to convert hours to seconds.
	cout << "[E] Converting minutes to seconds" << endl; // Advises the user to input the E to convert minutes to seconds.
	cout << "**********************************" << endl; // Used to separate the quit function from the conversion choices.
	cout << "[F] Exit the program" << endl; // Advises the user to input the letter F to quit/exit the program.
	cout << "**********************************" << endl; // Used to separate the final option from the user's input.
	cin >> cMenuOption; // User will input the letter of the option they want to select.

	switch (cMenuOption) { // The switch will take the user to the particular void statement associated with the option which was selected, as it will create different branching points in the code. (Dawson, 2010. p.51) For example, a/A will take the user to secondsToHours() and b/B will take the user to secondsToMinutes()..
	case 'a': // Will allow the user to input a lower case a.
	case 'A': // Will allow the user to input an upper case A.
		cout << "You have selected to convert seconds to hours." << endl; // Output statement to confirm the user's choice.
		secondsToHours(); // Will run the secondsToHours() void until its contents have been completed.
		break; // Breaks the program out of the loop and presents the user with the menu above to select a new option.

	case 'b': // Will allow the user to input a lower case b.
	case 'B': // Will allow the user to input an upper case B.
		cout << "You have selected to convert seconds to minutes." << endl; // Output statement to confirm the user's choice.
		secondsToMinutes(); // Will run the secondsToMinutes() void until its contents have been completed.
		break; // Breaks the program out of the loop and presents the user with the menu above to select a new option.

	case 'c': // Will allow the user to input a lower case c.
	case 'C': // Will allow the user to input an upper case C.
		cout << "You have selected to convert minutes to hours." << endl; // Output statement to confirm the user's choice.
		minutesToHours(); // Will run the minutesToHours() void until its contents have been completed.
		break; // Breaks the program out of the loop and presents the user with the menu above to select a new option.

	case 'd': // Will allow the user to input a lower case d.
	case 'D': // Will allow the user to input an upper case D.
		cout << "You have selected to convert hours to seconds." << endl; // Output to confirm the user's choice.
		hoursToSeconds(); // Will run the hoursToSeconds() void until its contents have been completed.
		break; // Breaks the program out of the loop and presents the user with the menu above to select a new option.

	case 'e': // Will allow the user to input a lower case e.
	case 'E': // Will allow the user to input an upper case E.
		cout << "You have selected to convert minutes to seconds" << endl; // Output to confirm the user's choice.
		minutesToSeconds(); // Will run the minutesToSeconds() void until its contents have been completed.
		break; // Breaks the program out of the loop and presents the user with the menu above to select a new option.

	case 'f': // Will allow the user to input a lower case f.
	case 'F': // Will allow the user to input an upper case F.
		cout << "You have selected to exit the program." << endl; // Output to confirm the user's choice.
		quitProgram(); // Will run the quitProgram() void until its contents have been completed to stay in or quit the program.
		break; // Breaks the program out of the loop in the event that the user selected "Yes" to quit the program.

	default: // Default is used in the event the user inputs anything which is not the letters a/A to f/F.
		cout << "That is not a valid option. Please select an option from A through F. " << endl; // Output confirms an incorrect choice.
		system("pause"); // Pauses the program so that the user can read the output statement.
		break; // Breaks the program out of the loop so that the user can once again try and input a letter from a/A to f/F.

		system("CLS"); // Is used to clear the screen of any messages and brings up the menu awaiting user input again.
	}

}



int main() // int main indicates the main integer and is where the main program is initialised. (Dawson, 2010. p.35)
{

	bActive = true; // The bool bActive in the true state will mean that the program is running.
	do {
		systemMenu();
	} while (bActive); // The do while loop will run the program on the basis that bActive is true and will continue to run until the user changes the bool to false, via the quitProgram void. This will always run the code first and then check to see if it is true or false after. (Gregoire, 2014. p.21)


	cout << "Thank you for using the Simple Time Calculator. Goodbye. " << endl; // Final output message will confirm that the user has finished using the program.

	system("pause"); // This will pause the program until the user presses any key to continue.
	return 0; // When the program has been completed, it will return 0; to confirm that it has ran successfully.
}
