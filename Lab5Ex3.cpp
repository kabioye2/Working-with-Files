//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Summer 2021 												//
//																									//
//	Type of Assignment:		Lab 5																    //
//	Problem Number:			Exercise 3																//
//	Section Number			700																		//
//	Author:					Kehinde Abioye														    //
//	Date Assigned:			July 5, 2021														    //
//	Project Name:			File comparing											                //
//	File Name:				Lab5Ex3.cpp			                                                    //
// 		 													                                        //
//  Program Purpose:                                                                                //
//   The program compares two files and prints a message if the files are                           //
//   the same or different.  If the files are different,                                            //   
//   the program will print the line numbers for lines that are not the same.                       //
//																							        //
//  Algorithm:																						//
// 	  1. Read two files                                                                             //
//    2. Display line number that is different                                                      //
//    3. Display if files are the same or different                                                 //                                    //								
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;


int main()
{
    /*  Declare and initialize variables.  */
    ifstream aFile, bFile;
    char a, b;
    int count = 0;
    bool aeof; //end of file for aFile
    bool beof;//end of file for bFile

    // Open input files.
    aFile.open("File1.txt"); //check if file opens

    if (aFile.fail())
    {
        cout << "error opening file" << endl;
        exit(1);
    }

    bFile.open("File4.txt");
    if (bFile.fail())
    {
        cout << "error opening file" << endl;
        exit(1);
    }


    do
    {
        //Get the character from each file
        aFile.get(a);
        bFile.get(b);


        //initialize boolean variables for end of file
        aeof = aFile.eof();
        beof = bFile.eof();

        //  If we are the end of a file or 
        if ((a != b) || (aeof != beof))//if lines are not the same and end of file for both file are not equal
        {
            count++; //add one to counter
            cout << "line " << count << " is not the same." << endl;
        }
        if ((aeof || beof) && (aeof != beof))//end of file for at least one file and end of file is not equal for both files
        {
            cout << endl;
            cout << "There was an error on this line\n\n";
        }
        //cout << a << endl;
        //cout << b << endl;

    } while (!aeof && !beof); //if end of file for either exit do-while loop

    if (count == 0)//if counter is 0 then no line were different and at least one file ended
    {
        cout << "The files are the same." << endl;
    }
    else
    {
        cout << "The files differ in length." << endl;
    }

    //Close files and exit prgram.
    aFile.close();
    bFile.close();

    return 0;
}


