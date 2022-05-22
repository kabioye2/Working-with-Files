//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Summer 2021 												//
//																									//
//	Type of Assignment:		Lab 5																    //
//	Problem Number:			Exercise 1																//
//	Section Number			700																		//
//	Author:					Kehinde Abioye														    //
//	Date Assigned:			July 5, 2021														    //
//	Project Name:			Output Formatting											            //
//	File Name:				Lab5Ex1.cpp													            //
//																									//
//	Purpose of Program:																				//
//		The purpose of this program is to read two floating point numbers and print the sum,        //
//      product and difference.																        //
//																							        //
//  Algorithm:																						//
// 	  1. Read two-floating point numbers                                                            //
//    2. Print sum, product, and difference in fixed-point notation                                 //
//    3. Print sum, product, and difference in scientific notation								    //						
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> //input and output data
#include <fstream> //work with files
#include <iomanip>
using namespace std;

int main()
{
    ifstream myFile;
    myFile.open("outputFormatting.txt");

    //check for error
    if (myFile.fail())//if file doesn't open print following
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    //Declare variable
    float num1, num2, sum, product, difference;

    

    myFile >> num1 >> num2; //>> goes to next line. assign numbers in file to corresponding variables

    cout << "Read the first number: " << num1 << endl; // print first number in file

    cout << "Read the second number: " << num2 <<endl;//print second number in file

    sum = num1 + num2;
    product = num1 * num2;
    difference = num1 - num2;

    cout << "The sum is";
    cout.width(22);//space between prior statement and value
    cout << fixed << showpoint << setprecision(3) << sum;//fixed-point notation
    cout << ".\n";

    cout << "The product is";
    cout.width(18);
    cout << fixed << showpoint << setprecision(3) << product << ".\n";

    cout << "The difference is";
    cout.width(15);
    cout << fixed << showpoint << setprecision(3) << difference << ".\n\n";

    cout << "Here is the same data in scientific notation:" << endl;

    cout << "The sum is";
    cout.width(22);
    cout << scientific << setprecision(3) << sum;//scientific notation
    cout << ".\n";

    cout << "The product is";
    cout.width(18);
    cout << scientific << setprecision(3) << product << ".\n";

    cout << "The difference is";
    cout.width(15);
    cout << scientific << setprecision(3) << difference << ".\n\n";

    
    myFile.close();


     return 0;
}

