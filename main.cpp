/*
Team Name: Discrete Bois
Team Members: Grant Duchars, Morgan Purcell, Romyal Swarnkar
October 10, 2022 - Applied Discrete Structures, Fall 2022, Dr. J

Description: A menu-driven program to convert user entered numbers
Possible convertions include: Decimal to Binary,
                              Hexadecimal to Binary,
                              Binary to Decimal,
                              Binary to Hexadecimal
*/
#include <string.h>
#include <math.h>
#include <iostream>
#include <unordered_map>

using namespace std;

void convertDecimalToBinary(string input);
void convertDecimalToBinaryHelper(int num, char *result);
void convertBinaryToDecimal(string input);
void convertHexToBinary(string input);
void convertBinaryToHex(string input);
void buildConversionMaps();

unordered_map<char, string> hexToBinaryTable;
unordered_map<string, string> binaryToHexTable;

int main()
{
    buildConversionMaps();
    // Clear out terminal output
    cout << "\033[1;1H\033[2J\n\n"
         << endl;
    while (true)
    {
        // Prompt user with menu
        cout << "\033[1;35mDiscrete Bois' Conversion Program\n\n\033[0;36m1. Convert decimal to binary\n2. Convert binary to decimal\n3. Convert hexadecimal to binary\n4. Convert binary to hexadecimal\n5. End program\n\n\033[33mPlease enter your selection:\033[0m ";
        // Get user input
        string input;
        string number;
        cin >> input;
        // Check which option user selected
        if (input == "")
        {
            cout << "\033[1;1H\033[2J\033[4;31m\nERROR: Please enter a number from the list\033[0m\n"
                 << endl;
        }
        else if (input == "1")
        {
            cout << "\033[1;1H\033[2J\033[33m\nPlease enter your decimal number to convert to binary:\033[0m ";
            cin >> number;
            convertDecimalToBinary(number);
        }
        else if (input == "2")
        {
            cout << "\033[1;1H\033[2J\033[33m\nPlease enter your binary number to convert to decimal:\033[0m ";
            cin >> number;
            convertBinaryToDecimal(number);
        }
        else if (input == "3")
        {
            cout << "\033[1;1H\033[2J\033[33m\nPlease enter your hexadecimal number to convert to binary:\033[0m ";
            cin >> number;
            convertHexToBinary(number);
        }
        else if (input == "4")
        {
            cout << "\033[1;1H\033[2J\033[33m\nPlease enter your binary number to convert to hexadecimal:\033[0m ";
            cin >> number;
            convertBinaryToHex(number);
        }
        else if (input == "5")
        {
            cout << "\033[1;1H\033[2J\033[1;32m\nThank you for using Discrete Bois' Conversion Program\033[0m\n"
                 << endl;
            return 0;
        }
        else
        {
            cout << "\033[1;1H\033[2J\033[4;31m\nERROR: Please enter a number from the list\033[0m\n"
                 << endl;
        }
    }
}

/**
 * Function to convert a decimal integer to a binary integer
 * @param input A string of the number you wish to convert
 */
void convertDecimalToBinary(string input)
{
    // Check if input is a valid decimal number
    if (input.find_first_not_of("0123456789") < input.length())
    {
        cout << "\033[1;1H\033[2J\033[4;31m\nERROR: The number you entered is not a valid decimal number\033[0m\n"
             << endl;
        return;
    }
    // Convert string to integer
    int num = atoi(input.c_str());
    // Allocate space for result string
    char *result = (char *)malloc(1024);
    // Clear out the result string
    strcpy(result, "");
    // Recursively run the function until num is zero
    convertDecimalToBinaryHelper((num / 2), result);
    // After recursion append last digit
    (num % 2) ? strcat(result, "1") : strcat(result, "0");
    // Print out the binary number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour binary number is:\033[0m " << result << "\n"
         << endl;
    // FREE THE MEMORY
    free(result);
}

/**
 * Helper method for convertDecimalToBinary()
 */
void convertDecimalToBinaryHelper(int num, char *result)
{
    // If num is not zero
    if (num)
    {
        // Recursively run the function until num is zero
        convertDecimalToBinaryHelper((num / 2), result);
        // On the way up append the correct digit to result string
        (num % 2) ? strcat(result, "1") : strcat(result, "0");
    }
}

/**
 * Function to convert a binary integer to a decimal integer
 * @param input A string of the number you wish to convert
 */
void convertBinaryToDecimal(string input)
{
    // Initialize decimal result variable
    int result = 0;
    // Calculate most significant bit's power
    int inputLen = input.length();
    int power = inputLen - 1;
    // Loop through binary number string
    for (int i = 0; i < inputLen; ++i)
    {
        // Check if digit is zero or one
        if (!(input[i] == '0' || input[i] == '1'))
        {
            cout << "\033[1;1H\033[2J\033[4;31m\nERROR: The number you entered is not a valid binary number\033[0m\n"
                 << endl;
            return;
        }
        // Only care about ones in binary number string
        if (input[i] == '1')
        {
            // Add two^power of the current bit to result
            result += pow(2, power);
        }
        // Decrement power of current bit by one
        --power;
    }
    // Print out the decimal number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour decimal number is:\033[0m " << result << "\n"
         << endl;
}

/**
 * Function to convert a hexadecimal integer to a binary integer
 * @param input A string of the number you wish to convert
 */
void convertHexToBinary(string input)
{
    // Check to see if input is a valid hexadecimal number
    if (input.find_first_not_of("0123456789ABCDEF") < input.length())
    {
        cout << "\033[1;1H\033[2J\033[4;31m\nERROR: The number you entered is not a valid hexadecimal number\033[0m\n"
             << endl;
        return;
    }
    string result;
    int inputLen = input.length();
    // Iterate through input and use lookup table to convert
    for (int i = 0; i < inputLen; ++i)
    {
        result += hexToBinaryTable[input[i]];
    }
    // Trim leading zeroes
    result.erase(0, result.find_first_not_of('0'));
    // Print out the binary number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour binary number is:\033[0m " << result << "\n"
         << endl;
}

/**
 * Function to convert a binary integer to a hexadecimal integer
 * @param input A string of the number you wish to convert
 */
void convertBinaryToHex(string input)
{
    int inputLen = input.length();
    string result;
    string temp;
    int index = 0;
    // Iterate through first (4 - n) bits if the length is not divisible by four
    for (int i = 0; i < (inputLen % 4); ++i)
    {
        // Check if digit is zero or one
        if (!(input[index] == '0' || input[index] == '1'))
        {
            cout << "\033[1;1H\033[2J\033[4;31m\nERROR: The number you entered is not a valid binary number\033[0m\n"
                 << endl;
            return;
        }
        temp += input[index];
        ++index;
    }
    // Append the converted string to result
    result += binaryToHexTable[temp];
    // Iterate through the rest of the input string by groups of four
    for (int i = 0; i < (inputLen / 4); ++i)
    {
        string temp;
        temp += input[index];
        temp += input[index + 1];
        temp += input[index + 2];
        temp += input[index + 3];
        // Check to see if four digits are binary
        if (binaryToHexTable.find(temp) == binaryToHexTable.end())
        {
            cout << "\033[1;1H\033[2J\033[4;31m\nERROR: The number you entered is not a valid binary number\033[0m\n"
                 << endl;
            return;
        }
        // Append the converted string to result
        result += binaryToHexTable[temp];
        index += 4;
    }
    // Print out the hexadecimal number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour hexadecimal number is:\033[0m " << result << "\n"
         << endl;
}

/**
 * Function to be run when the program first starts to populate hashmaps for hex <-> binary conversion
 */
void buildConversionMaps()
{
    hexToBinaryTable['0'] = "0000";
    hexToBinaryTable['1'] = "0001";
    hexToBinaryTable['2'] = "0010";
    hexToBinaryTable['3'] = "0011";
    hexToBinaryTable['4'] = "0100";
    hexToBinaryTable['5'] = "0101";
    hexToBinaryTable['6'] = "0110";
    hexToBinaryTable['7'] = "0111";
    hexToBinaryTable['8'] = "1000";
    hexToBinaryTable['9'] = "1001";
    hexToBinaryTable['A'] = "1010";
    hexToBinaryTable['B'] = "1011";
    hexToBinaryTable['C'] = "1100";
    hexToBinaryTable['D'] = "1101";
    hexToBinaryTable['E'] = "1110";
    hexToBinaryTable['F'] = "1111";
    binaryToHexTable["1"] = "1";
    binaryToHexTable["10"] = "2";
    binaryToHexTable["11"] = "3";
    binaryToHexTable["100"] = "4";
    binaryToHexTable["101"] = "5";
    binaryToHexTable["110"] = "6";
    binaryToHexTable["111"] = "7";
    binaryToHexTable["0000"] = "0";
    binaryToHexTable["0001"] = "1";
    binaryToHexTable["0010"] = "2";
    binaryToHexTable["0011"] = "3";
    binaryToHexTable["0100"] = "4";
    binaryToHexTable["0101"] = "5";
    binaryToHexTable["0110"] = "6";
    binaryToHexTable["0111"] = "7";
    binaryToHexTable["1000"] = "8";
    binaryToHexTable["1001"] = "9";
    binaryToHexTable["1010"] = "A";
    binaryToHexTable["1011"] = "B";
    binaryToHexTable["1100"] = "C";
    binaryToHexTable["1101"] = "D";
    binaryToHexTable["1110"] = "E";
    binaryToHexTable["1111"] = "F";
}