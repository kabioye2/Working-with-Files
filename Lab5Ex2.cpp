//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Summer 2021 												//
//																									//
//	Type of Assignment:		Lab 5																    //
//	Problem Number:			Exercise 2																//
//	Section Number			700																		//
//	Author:					Kehinde Abioye														    //
//	Date Assigned:			July 5, 2021														    //
//	Project Name:			Working With Files											            //
//	File Name:				Lab5Ex2.cpp													            //
//																									//
//	Purpose of Program:																				//
//		The purpose of this program is to read a file and display its contents. Then,               //
//      display the largest number in the file and the avergae of all numbers in the file			//										        //
//																							        //
//  Algorithm:																						//
// 	  1. Ask user to input filename                                                                 //
//    2. Display filename                                                                           //
//    3. Open and read file until end of file                                                       //
//       If file doesnt open display error message                                                  //
//    4. Display contents of file                                                                   //
//    2. Display largest number and average of numbers in file.                                     //								
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream> //work with files
#include <cctype>
#include <string>
#include <iomanip> 
#include<cstdlib>

using namespace std;

int main()
{
    char repeat;
    string filename;
    double value, largest, average, sum;
    int count;

    do
    {
        //Initiate the variable sum and count
        sum = 0;
        count = 0;

        //Output formatting
        cout.precision(1);   //print result with the specified decimal precision. Displayed to 1 decimal point
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);

        //Prompt the user to read the file name
        cout << "Enter the file name : ";
        getline(cin, filename);
        //cin >> filename;
        cout << endl;
        //filename += ".txt"; if you dont want user to enter .txt

        //declare input stream
        ifstream fin;

        //Connect the input stream to the external file (call member function open ())
        fin.open(filename.c_str());

        //check if opening file failed
        if (fin.fail())//if file doesn't open print following
        {
            cout << "error opening file" << endl;
            exit(1);
        }
        cout << "The numbers in the file inData.txt are :\n";
        fin >> value; //get line by line
        cout << value << endl; //print number
        largest = value;             //initialize the largest 
        sum += value;                      //add the first number to the sum
        count++;                 // update the counter to 1

        while (!fin.eof()) //read the rest numbers from the file until end of file is reached
        {
            fin >> value;
            //determine the larger value by comparing the value to the current largest
           if (value > largest)         //If it is, assign largest to it
           {
               largest = value;
           }
           cout << value << endl;
           count++;
           sum += value;
        }

        //Calculate the average
        average = sum / count;

        //  Close file
        fin.close();

        //Display the result
        cout << endl;
        cout << "The largest number in the file is " << largest << endl;
        cout << "The average of all of the numbers in the file is " << average << endl << endl;



        //Ask user if they wish to repeat
         cout << "Do you want to repeat the program(y / n) ? ";
         cin >> repeat;
         cout << endl;

         if (repeat == 'N' || repeat == 'n')
         {
             //print end of program message
             cout << "\n--------------\n";
             cout << "END OF PROGRAM\n";
             exit(1); //exit program
         }
         else if (repeat == 'Y' || repeat == 'y')
         {
             cin.ignore(); //ignore newline after user enter Y
         }

    } while (repeat == 'Y' || repeat == 'y'); // repeat program as long as y is entered



    return 0;
}


