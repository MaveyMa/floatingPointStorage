// ***********************
// driver.cpp
//
// Summary: CSS3 Lab 4's Floating-Point Numbers: Emulate how floating point values are stored in memory
//          Implement a floating point number system. Use "simple model", 14-bit:
//          ______________________________________________________
//          | 1-bit, Sign | 5-bit, Exponent | 8-bit, Significand |
//          ------------------------------------------------------
// Author: Mavey Ma
// Due: September 10, 2016
// ***********************

#include <iostream> //I/O
#include <string>
#include <cstdlib> //EXIT_SUCCESS
using namespace std;

// *************************************
bool isIntegerOver8Bits(int d);
// SUMMARY: Checks if user's integer value is too large for the system
// PRECONDITIONS: Pass in user's integer value to be changed into binary
// POSTCONDITIONS: Returns true (if integer's binary is over 8 bits)
//                      o meaning integer will NOT work in our system
//                      o meaning error message printed, and no further execution
//                 Returns false otherwise (is not over 8 bits)
//                      o meaning integer will work in our system.
//                      o meaning integer is allowed to enter algorithm
// *************************************
//
// *************************************
int positiveVersion(int d);
// SUMMARY: Helper function to give the positive version
// PRECONDITIONS: Pass in an integer
// POSTCONDITIONS: If negative, returns positive version. Else stay the same.
// *************************************
//
// *************************************
string decimalBecomesBinary(int d);
// SUMMARY: Convert a decimal integer to a binary number
// PRECONDITIONS: Pass in a positive integer base 10
// POSTCONDITIONS: Returns a string binary (1's and 0's) base 2
// *************************************
//
// *************************************
string reverseString(string s);
// SUMMARY: Helper function to change the string s backwards
// PRECONDITIONS: Pass in a string
// POSTCONDITIONS: Returns the string now backwards
// *************************************

int main()
{
    int userNumber;

    //1. TODO: Take an integer value as input. (Using integers to simplify program.)
    cout << "Welcome. To begin, enter an integer value: ";
    cin >> userNumber;
    cout << "Great! You said: " << userNumber << endl;
    cout << endl;
    //2. TODO: Error check, if number is too large to be stored in our system, cout message
    //         Integers that are more than 8 bits cannot be held in this system.
    if (isIntegerOver8Bits(userNumber))
    {
        cout << "Sorry, " << userNumber << " is too large to be stored in our system. Try another number!" << endl;
    }
    else
    {
        cout << "Oh my stars! You passed! ^_^ " << userNumber << " turned out to be a great number." << endl;
    }
    //3. TODO: Display a diagram that demonstrates how the number will be stored in memory.
    /*
    cout << "______________________________________________________" << endl;
    cout << "| 1-bit, Sign | 5-bit, Exponent | 8-bit, Significand |" << endl;
    cout << "------------------------------------------------------" << endl;
    */
    return EXIT_SUCCESS;
}

bool isIntegerOver8Bits(int d)
{
    string checkBinary;
    //1. Make sure integer d is positive.
    d = positiveVersion(d);
    //2. Convert from positive integer to binary.
    checkBinary = decimalBecomesBinary(d);
    //3. If over 8 bits, return true. Acceptable bits are range [1, 8] inclusive.
    return (checkBinary.length() > 8);
}//END IS INTEGER OVER 8 BITS

int positiveVersion(int d)
{
    if (d < 0)
        return d * -1;
    return d;
}//END POSITIVE VERSION

string decimalBecomesBinary(int d)
{
    string binaryString = "";
    while (d != 0)
    {
        //concatenate the first remainder into the string, 1 or 0
        if (d % 2 == 1)
            binaryString += "1";
        else
            binaryString += "0";
        //divide d to make it smaller, closer to 0
        d /= 2;
    }//END WHILE LOOP
    binaryString = reverseString(binaryString);
    return binaryString;
}//END DECIMAL --> BINARY

string reverseString(string s)
{
    string backwards = "";
    for (int i = s.length() - 1; i >= 0; i--)
        backwards += s[i];
    return backwards;
}//END REVERSE STRING
