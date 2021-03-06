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
void displayFloatingPointInMemory(int d);
// SUMMARY: Takes input integer, and displays how it's stored as floating-point in memory
// PRECONDITIONS: Takes in user-input to be converted to binary
// POSTCONDITIONS: 14-bit model will output to command line (1-Sign)(5-Exponent)(8-Significand)
// *************************************
//
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
    //====================================================
    //1. Take an integer value as input. (Using integers to simplify program.)
    cout << "Welcome. To begin, enter an integer value: ";
    cin >> userNumber;
    //====================================================
    //2. Error check, if number is too large to be stored in our system, cout message
    //   Integers that are more than 8 bits cannot be held in this system.
    if (isIntegerOver8Bits(userNumber))
    {
        cout << "Sorry, " << userNumber << " is too large to be stored in our system. Try another number!" << endl;
    }
    else
    {//====================================================
    //3. Display a diagram that demonstrates how user's number will be stored in memory.
        displayFloatingPointInMemory(userNumber);
    //  ______________________________________________________
    //  | 1-bit, Sign | 5-bit, Exponent | 8-bit, Significand |
    //  ------------------------------------------------------
    }
    return EXIT_SUCCESS;
}//END MAIN

void displayFloatingPointInMemory(int d)
{
    string sign,
           exponent,
           shortSignificand,
           eightBitSignificand;
    int excess15;
    const int BIAS = 15;
    //====================================================
    //0. The case that it's zero
    if (d == 0)
    {
        cout << "________________________" << endl;
        cout << "| 0 | 00000 | 00000000 |" << endl;
        cout << "------------------------" << endl;
        return;
    }
    //====================================================
    //1. Determine sign, positive (0) or negative (1)
    if (d < 0)
    {
        sign = "1";
        d = positiveVersion(d); //treat integer like a positive
    }
    else
    {
        sign = "0";
    }
    //====================================================
    //2. Determine significand; Convert integer to binary
    shortSignificand = decimalBecomesBinary(d);
    eightBitSignificand = shortSignificand; //make a copy for excess15 calculation
    //Extra spaces are concatenated with 0's to ensure significand 8-bit length
    for (int i = shortSignificand.length(); i < 8; i++)
    {
        eightBitSignificand += '0';
    }
    //====================================================
    //3. Determine excess15 Bias Formula: (2^(n-1)) - 1
    //   (Take the original exponent from 0.1..... * 2^original)
    //   Original is: How many decimal places move over, or length() of bit string
    //   Bias is: 15. Because there're 5 bits in exponent, n = 5 in Bias Formula
    //   Excess-15-exponent = original + Bias
    excess15 = shortSignificand.length() + BIAS;
    //====================================================
    //4. Convert excess-15 exponent into binary
    exponent = decimalBecomesBinary(excess15);
    //====================================================
    //5. Voilà! Now, display everything. (:
    cout << "_______________________" << endl;
    cout << "| " << sign << " | " << exponent << " | " << eightBitSignificand << " |" << endl;
    cout << "-----------------------" << endl;
    return;
}//END DISPLAY FLOATING POINT IN MEMORY

bool isIntegerOver8Bits(int d)
{
    string checkBinary;
    //====================================================
    //1. Make sure integer d is positive.
    d = positiveVersion(d);
    //====================================================
    //2. Convert from positive integer to binary.
    checkBinary = decimalBecomesBinary(d);
    //====================================================
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
