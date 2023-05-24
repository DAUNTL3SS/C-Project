/*
	CS230 Project - Vaggelis Chasiotis, 20200101
	--------------------------------------------
	Baseball Statistics for Boston Red Sox
	--------------------------------------------
	Spring 1 Semester, 2022
*/

#include <iostream>  	// Required for cin, cout, cerr
#include <limits> 		// Required for error trapping: numeric_limits<streamsize>::max()
#include <fstream>      // Required for ifstream and ofstream
#include <string>       // Required for string
#include <iomanip>      // Required for setw

using namespace std;  
using std::ifstream;

//Declaring the functions
void bubbleSort(int[], int[], int[], int[], double[], double[], string[]);
void bubbleSort2(double[], int[], int[], int[], double[], double[], string[]);
void reverse(string[], int[], int[], int[], double[], double[]);

//Program Starts Here!

int main()
{
	//Variables Area
	int option(0);                                      //Variable for the user input for the initial menu
	string player[12];                                  //String variable for the player's column
	int games[12];                                      //Integer variable for the games column
	int homeruns[12];                                   //Integer variable for the home runs column
	int strikeouts[12];                                 //Integer variable for the strikouts column
	double hrpg[12];                                    //HomeRuns per game
	double sopg[12];                                    //Strikeouts per game
	ifstream fin;                                       //Variable for taking the data from the text file
	ofstream fout;                                      //Variable for displaying the data in the text file
	string filename = "Chasiotis_red_sox.txt";          
	string outputfile = "Chasiotis_red_sox_stats.txt";
	bool choice3 = false;                               //Variable for the condition in Option 4
	int arr[12];                                        //Variable for the integer sorting function
	double arr2[12];                                    //Variable for the double sorting function
	string arr3[12];                                    //Variable for the string sorting function

			
	
	do //Choosing a do-while loop because its easier for me to use and also to execute the program up until the user enters a key that's not in the menu
	{
		//Creating the Interface of the Menu
		cout << "\n|====================================================================================|" << endl;
		cout << "|         USER MENU: MAJOR LEAGUE BASEBALL STATISTICS FOR THE BOSTON RED SOX         |" << endl;
		cout << "|====================================================================================|" << endl;
		
		cout <<"\n1) Read and Display stats for the players with the most HRs" << endl;
		cout <<"\n2) Display players with home runs above a certain threshold, in alphabetical order" << endl;
		cout <<"\n3) Calculate HR/G & SO/G, save into a new file along with original stats, display" << endl;
		cout <<"\n4) Sort by any field indicated by the user" << endl;
		cout <<"\n5) Exit the program" << endl;
		cout <<"\n=====================================================================================" << endl;
		
		cout <<"\nPlease select an option: " << endl;
		cin >> option;
		
		cin.sync(); 				// Clears the cin buffer
    
		while(cin.fail()) 			// Error trapping begins
		{
			cin.clear();
    		cin.ignore(numeric_limits<streamsize>::max(),'\n'); // helps survive text char input
        	cout << "Invalid entry. Please enter a number of the option you want to select: ";
        	cin >> option;
        	cin.sync(); 			// Clears the cin buffer
    	}
		
		if(option == 1)
		{
			
			cout << "\nYou selected option 1!" << endl<< endl;
			cout << "In this option, the program reads the data from the team, and displays the players with the most Home Runs (HR). \n" << endl;
			
			fin.open(filename.c_str()); //Command for opening the file and take its data
			
			if(fin.is_open()) //Condition to display data only when the file is open
			{
				//Using setw command to leave blank spaces in between the characters used, and the number within the parentheses represents the amount of characters we need to leave after the last character of the previous word.
				cout << "|============================================================|" << endl;
				cout << "|" << setw(13) << "Player" << setw(8) << "|" 
					 		<< setw(7) << "G" << setw(7) << "|" 
					 		<< setw(7) << "HR" << setw(6) << "|" 
					 		<< setw(7) << "SO" << setw(6) << "|" <<endl;
				cout << "|============================================================|" << endl;
				for (int i=1; i<12; i++)
				{
					fin >> player[i] >> games[i] >> homeruns[i] >> strikeouts[i];
					cout << "|" << setw(20) << player[i] << "|"
					<< setw(5) << " " << setw(8) << games[i] << "|"
					<< setw(5) << " " << setw(7) << homeruns[i] << "|"
					<< setw(5) << " " << setw(7) << strikeouts[i] << "|" << endl;
					cout << "--------------------------------------------------------------" << endl;
				}
				fin.close();
			}
	    }
		else if(option == 2)
		{
			cout << "\n\nYou selected option 2! \n" << endl;
			cout << "In this option, the program asks the user to enter a limit on the Home Runs (HR)." << endl;
			cout << "It then displays the players who have hit the number entered (or more), in an alphabetical order. \n" << endl;
			
			int limit; //Variable for the user to set the limit
			
			cout << "Please enter a number for limiting the HR: " << endl; //Asking for user's input
			cin >> limit;
			
			while(cin.fail()) 			// Error trapping begins
			{
				cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(),'\n'); // helps survive text char input
        		cout << "Invalid entry. Please enter a number of the option you want to select: ";
        		cin >> option;
        		cin.sync(); 			// Clears the cin buffer
    		}
			
			fin.open(filename.c_str());
			
			if(fin.is_open())
			{
				cout << "|============================================================|" << endl;
				cout << "|" << setw(13) << "Player" << setw(8) << "|" 
			 				<< setw(7) << "G" << setw(7) << "|" 
			 				<< setw(7) << "HR" << setw(6) << "|" 
			 				<< setw(7) << "SO" << setw(6) << "|" <<endl;
				cout << "|============================================================|" << endl;
				
				for (int i=0; i<=11; i++)
				{
					fin >> player[i] >> games[i] >> homeruns[i] >> strikeouts[i];
				}
				for (int i=0; i<=11; i++)
				{	
					if(limit <= homeruns[i])
					{
						cout << "|" << setw(20) << player[i] << "|"
							<< setw(5) << " " << setw(8) << games[i] << "|"
							<< setw(5) << " " << setw(7) << homeruns[i] << "|"
							<< setw(5) << " " << setw(7) << strikeouts[i] << "|" << endl;							
						cout << "--------------------------------------------------------------" << endl;
					}
				}
			}
			fin.close();	
		}
		else if(option == 3)
		{
			cout << "\n\nYou selected option 3! \n" << endl;
			cout << "In this option, the program calculates the number of Home Runs (HR) per game and the Strike Outs (SO) per game for each player." << endl;
			cout << "It then displays those two additional calculations together with the original data\n" << endl;
			
			choice3 = true; //Activating the boolean because of the execution of this option
			
			fin.open(filename.c_str());
			fout.open(outputfile.c_str());
			
			if(fin.is_open())
			{
				cout << "|======================================================================================|" << endl;
				cout << "|" << setw(13) << "Player" << setw(8) << "|" 
					 		<< setw(7) << "G" << setw(7) << "|" 
					 		<< setw(7) << "HR" << setw(6) << "|" 
					 		<< setw(7) << "SO" << setw(6) << "|" 
							<< setw(7) << "HR/G" << setw(6) << "|"
							<< setw(7) << "SO/G" << setw(6) << "|" << endl;
				cout << "|======================================================================================|" << endl;
				for (int i=0; i<=11; i++)
				{
					fin >> player[i] >> games[i] >> homeruns[i] >> strikeouts[i];
					hrpg[i] = (double) homeruns[i] / (double) games[i];
					sopg[i] = (double) strikeouts[i] / (double) games[i];
					cout << "|" << setw(20) << player[i] << "|"
					<< setw(5) << " " << setw(8) << games[i] << "|"
					<< setw(5) << " " << setw(7) << homeruns[i] << "|"
					<< setw(5) << " " << setw(7) << strikeouts[i] << "|"
					<< setw(5) << " " << setw(7) << fixed << setprecision(2) << hrpg[i] << "|" //Using setprecision command to basically reduce the decimal number into showing less decimal degits and cover less space.
					<< setw(5) << " " << setw(7) << fixed << setprecision(2) << sopg[i] << "|" << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					fout << player[i] << " " << games[i] << " " << homeruns[i] << " " << strikeouts[i] << " " << fixed << setprecision(2) << hrpg[i] << " " << fixed << setprecision(2) << sopg[i] << endl; 
				}
				fin.close();
				fout.close();
			}
		}
		else if(option == 4)
		{
			cout << "\n\nYou selected option 4! \n" << endl;
			cout << "In this option, the program asks the user to:\n \n1)Choose a field to sort it by and\n\n2)Choose ascending or descending to sort the outcome of the option 3 (new data).\n" << endl;
			cout << "Then it displays all data sorted."<< endl;
			cout << "--------------------------------------------------------------------------\n\n"<<endl;
			
				// Condition about the trigger of the boolean.
				if (choice3 != true)
			{
				cout << "Option 4 requires the execution of Option 3 beforehand, so please do Option 3 before coming here!" << endl;
			}
			else 
			{
			
				int choice;                             //Variable for the first entry
				int choice2;                            //Variable for the second entry
			
				cout << "Enter a number to sort:\n" << endl;
				cout << "\nType 1 for Players" << endl;
				cout << "\nType 2 for Games" << endl;
				cout << "\nType 3 for Home Runs" << endl;
				cout << "\nType 4 for Strike Outs" << endl;
				cout << "\nType 5 for Home Runs per Game" << endl;
				cout << "\nType 6 for Strike Outs per Game" << endl;
				cin >> choice;
			
				while(cin.fail()) 			// Error trapping begins
				{
					cin.clear();
    				cin.ignore(numeric_limits<streamsize>::max(),'\n'); // helps survive text char input
        			cout << "Invalid entry. Please enter a number of the option you want to select: ";
        			cin >> option;
        			cin.sync(); 			// Clears the cin buffer
    			}
				
				cout << "\nType 1 for Ascending" << endl;
				cout << "\nType 2 for Descending" << endl;
				cin >> choice2;
				
				while(cin.fail()) 			// Error trapping begins
				{
					cin.clear();
    				cin.ignore(numeric_limits<streamsize>::max(),'\n'); // helps survive text char input
        			cout << "Invalid entry. Please enter a number of the option you want to select: ";
        			cin >> option;
        			cin.sync(); 			// Clears the cin buffer
    			}
				
				fin.open(outputfile.c_str()); //Taking the data from the New txt file of Option 3 output.
				
				//This loop takes all the data from each column and row
				for (int i=0; i < 12; i++)
				{
					fin >> player[i] >> games[i] >> homeruns[i] >> strikeouts[i] >> hrpg[i] >> sopg[i]; 
				}
				
				//Functionality of the choices start here!
				if (choice == 1)
				{
					//Sort by name
					for (int i=0; i < 12; i++)
					{
						arr3[i] = player[i];
					}
					//Calls the function to sort the column
					bubbleSort(arr, games, homeruns, strikeouts, hrpg, sopg, player);
				}
				if (choice == 2)
				{
					//Taking all data from the Games column
					for (int i=0; i < 12; i++)
					{
						arr[i] = games[i];
					}
					//Calls the function to sort the column
					bubbleSort(arr, games, homeruns, strikeouts, hrpg, sopg, player);
					
				}
				else if (choice == 3)
				{
					for (int i=0; i < 12; i++)
					{
						arr[i] = homeruns[i];
					}
					
					bubbleSort(arr, games, homeruns, strikeouts, hrpg, sopg, player);
				}
				else if (choice == 4)
				{
					for (int i=0; i < 12; i++)
					{
						arr[i] = strikeouts[i];
					}
					
					bubbleSort(arr, games, homeruns, strikeouts, hrpg, sopg, player);
					
				}
				else if (choice == 5)
				{
					for (int i=0; i < 12; i++)
					{
						arr2[i] = hrpg[i];
					}
					
					 //This is where the double type sorting is being used, since hrpg is a double.
					 bubbleSort2(arr2, games, homeruns, strikeouts, hrpg, sopg, player);
					
				}
				else if (choice == 6)
				{
					
					for (int i=0; i < 12; i++)
					{
						arr2[i] = sopg[i];
					}
				
					 bubbleSort2(arr2, games, homeruns, strikeouts, hrpg, sopg, player);
				
				}
				//Condition for Ascending form
				if (choice2 == 1)
				{
				
				cout << "\n\n|======================================================================================|" << endl;
				cout << "|" << setw(13) << "Player" << setw(8) << "|" 
					 		<< setw(7) << "G" << setw(7) << "|" 
					 		<< setw(7) << "HR" << setw(6) << "|" 
					 		<< setw(7) << "SO" << setw(6) << "|" 
							<< setw(7) << "HR/G" << setw(6) << "|"
							<< setw(7) << "SO/G" << setw(6) << "|" << endl;
				cout << "|======================================================================================|" << endl;
					for (int i=0; i<=11; i++)
						{
							cout << "|" << setw(20) << player[i] << "|"
							<< setw(5) << " " << setw(8) << games[i] << "|"
							<< setw(5) << " " << setw(7) << homeruns[i] << "|"
							<< setw(5) << " " << setw(7) << strikeouts[i] << "|"
							<< setw(5) << " " << setw(7) << fixed << setprecision(2) << hrpg[i] << "|"
							<< setw(5) << " " << setw(7) << fixed << setprecision(2) << sopg[i] << "|" << endl;
							cout << "----------------------------------------------------------------------------------------" << endl;
						}
				
				}
				//Condition for Descending form
				else if(choice2 == 2)
				{
					//Calling the reverse function
					reverse(player, games, homeruns, strikeouts, hrpg, sopg);
				}
			}
			fin.close();
		}
		else if(option == 5)
		{
			cout << endl << "Exiting..." << endl;
		}
		else 
		{
			cout << "\nInvalid entry. Please enter 1, 2, 3, 4 or 5 to proceed. \n" << endl;
		}
	} while (option != 5); //Condition of do-while loop
	
	return 0;
}

// This is a function that is executed in integer types of variables
void bubbleSort (int arr[], int games[], int homeruns[], int strikeouts[], double hrpg[], double sopg[], string player[])
{
	int i = 0; //Declaration of the variable for the outer loop
	int j = 0; //Declaration of the variable for the inner loop
	
	int temp;  //this variable is read the type of the array of the choice that we want to sort, in order to sort that one and then make the rest of the arrays to follow up.
	int temp1; //Temp variable to swap values for the games column
	int temp2; //Temp variable to swap values for the homeruns column
	int temp3; //Temp variable to swap values for the strikeouts column
	double temp4; //Temp variable to swap values for the homeruns per game column
	double temp5; //Temp variable to swap values for the strikeouts per game column
	string temp6; //Temp variable to swap values for the string column
	
	for (i = 11; i > 0; i--) 
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1]) //Condition that compares a specific value with its next, and in case the next is smaller, they swap
			{
				//Swapping area
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				temp1 = games[j];
				games[j] = games[j+1];
				games[j+1] = temp1;
				
				temp2 = homeruns[j];
				homeruns[j] = homeruns[j+1];
				homeruns[j+1] = temp2;
				
				temp3 = strikeouts[j];
				strikeouts[j] = strikeouts[j+1];
				strikeouts[j+1] = temp3;
				
				temp4 = hrpg[j];
				hrpg[j] = hrpg[j+1];
				hrpg[j+1] = temp4;
				
				temp5 = sopg[j];
				sopg[j] = sopg[j+1];
				sopg[j+1] = temp5;
				
				temp6 = player[j];
				player[j] = player[j+1];
				player[j+1] = temp6;
			
			}
		}
	}
}

// This is a function that is executed in double types of variables, and its only difference from the previous function is that it is used to read double types of variables.
void bubbleSort2 (double arr2[], int games[], int homeruns[], int strikeouts[], double hrpg[], double sopg[], string player[])
{
	int i = 0;
	int j = 0;
	
	double temp;
	int temp1;
	int temp2;
	int temp3;
	double temp4;
	double temp5;
	string temp6;
	
	for (i = 11; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr2[j] > arr2[j+1])
			{
				temp = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = temp;
				
				temp1 = games[j];
				games[j] = games[j+1];
				games[j+1] = temp1;
				
				temp2 = homeruns[j];
				homeruns[j] = homeruns[j+1];
				homeruns[j+1] = temp2;
				
				temp3 = strikeouts[j];
				strikeouts[j] = strikeouts[j+1];
				strikeouts[j+1] = temp3;
				
				temp4 = hrpg[j];
				hrpg[j] = hrpg[j+1];
				hrpg[j+1] = temp4;
				
				temp5 = sopg[j];
				sopg[j] = sopg[j+1];
				sopg[j+1] = temp5;
				
				temp6 = player[j];
				player[j] = player[j+1];
				player[j+1] = temp6;
			
			}
		}
	}
}


//Function for reversing the data that are going to be presented in a descending form
void reverse(string player[], int games[], int homeruns[], int strikeouts[], double hrpg[], double sopg[]) //here we choose the arrays (columns) we want to change
{
	//We declare new variables which are going to get the values of the already made up variables but in opposite form, eg. the first player of the reverse is gonna have the value of the last player of the normal form...
	string reverse_player[12];
	int reverse_games[12];
	int reverse_homeruns[12];
	int reverse_strikeouts[12];
	double reverse_hrpg[12];
	double reverse_sopg[12];
	
	//In this loop it is where the reverse values take place and then the display
	for (int i=0; i < 12; i++)
	{
		reverse_player[i] = player[11-i];
		reverse_games[i] = games[11-i];
		reverse_homeruns[i] = homeruns[11-i];
		reverse_strikeouts[i] = strikeouts[11-i];
		reverse_hrpg[i] = hrpg[11-i];
		reverse_sopg[i] = sopg[11-i];
	}
	cout << "|======================================================================================|" << endl;
				cout << "|" << setw(13) << "Player" << setw(8) << "|" 
					 		<< setw(7) << "G" << setw(7) << "|" 
					 		<< setw(7) << "HR" << setw(6) << "|" 
					 		<< setw(7) << "SO" << setw(6) << "|" 
							<< setw(7) << "HR/G" << setw(6) << "|"
							<< setw(7) << "SO/G" << setw(6) << "|" << endl;
	cout << "|======================================================================================|" << endl;
			for (int i=0; i<=11; i++)
			{
				cout << "|" << setw(20) << reverse_player[i] << "|"
							<< setw(5) << " " << setw(8) << reverse_games[i] << "|"
							<< setw(5) << " " << setw(7) << reverse_homeruns[i] << "|"
							<< setw(5) << " " << setw(7) << reverse_strikeouts[i] << "|"
							<< setw(5) << " " << setw(7) << fixed << setprecision(2) << reverse_hrpg[i] << "|"
							<< setw(5) << " " << setw(7) << fixed << setprecision(2) << reverse_sopg[i] << "|" << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
}