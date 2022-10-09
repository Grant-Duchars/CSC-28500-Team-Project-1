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

int main()
{
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
    // Convert string to integer
    int num = atoi(input.c_str());
    // Allocate space for result string
    char *result = (char *)malloc(512);
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
    // Create string to store output
    char *binaryNumber = (char *)malloc(512);
    strcpy(binaryNumber, "");
    // Iterate through input string and append matching binary digits to output string
    int inputLen = input.length();
    for (int i = 0; i < inputLen; ++i)
    {
        switch ((int)input[i])
        {
        case '0':
            strcat(binaryNumber, "0000");
            break;
        case '1':
            strcat(binaryNumber, "0001");
            break;
        case '2':
            strcat(binaryNumber, "0010");
            break;
        case '3':
            strcat(binaryNumber, "0011");
            break;
        case '4':
            strcat(binaryNumber, "0100");
            break;
        case '5':
            strcat(binaryNumber, "0101");
            break;
        case '6':
            strcat(binaryNumber, "0110");
            break;
        case '7':
            strcat(binaryNumber, "0111");
            break;
        case '8':
            strcat(binaryNumber, "1000");
            break;
        case '9':
            strcat(binaryNumber, "1001");
            break;
        case 'A':
            strcat(binaryNumber, "1010");
            break;
        case 'B':
            strcat(binaryNumber, "1011");
            break;
        case 'C':
            strcat(binaryNumber, "1100");
            break;
        case 'D':
            strcat(binaryNumber, "1101");
            break;
        case 'E':
            strcat(binaryNumber, "1110");
            break;
        case 'F':
            strcat(binaryNumber, "1111");
            break;
        default:
            break;
        }
    }
    // Count how many leading zeroes there are in the output string
    int cutIndex = 0;
    while (binaryNumber[cutIndex] != '1')
    {
        ++cutIndex;
    }
    // Make a pointer pointing to just after the leading zeroes
    char *result = binaryNumber + cutIndex;
    // Print out the binary number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour binary number is:\033[0m " << result << "\n"
         << endl;
    // FREE THE MEMORY
    free(binaryNumber);
}

/**
 * Function to convert a binary integer to a hexadecimal integer
 * @param input A string of the number you wish to convert
 */
void convertBinaryToHex(string input)
{
    // Create a hashmap lookup table for easy conversion
    unordered_map<string, string> m;
    m["1"] = "1";
    m["10"] = "2";
    m["11"] = "3";
    m["100"] = "4";
    m["101"] = "5";
    m["110"] = "6";
    m["111"] = "7";
    m["0000"] = "0";
    m["0001"] = "1";
    m["0010"] = "2";
    m["0011"] = "3";
    m["0100"] = "4";
    m["0101"] = "5";
    m["0110"] = "6";
    m["0111"] = "7";
    m["1000"] = "8";
    m["1001"] = "9";
    m["1010"] = "A";
    m["1011"] = "B";
    m["1100"] = "C";
    m["1101"] = "D";
    m["1110"] = "E";
    m["1111"] = "F";
    int inputLen = input.length();
    string result;
    string temp;
    int index = 0;
    // Iterate through first (4 - n) bits if the length is not divisible by four
    for (int i = 0; i < (inputLen % 4); ++i)
    {
        temp += input[index];
        ++index;
    }
    // Append the converted string to result
    result += m[temp];
    // Iterate through the rest of the input string by groups of four
    for (int i = 0; i < (inputLen / 4); i += 4)
    {
        string temp;
        temp += input[index];
        temp += input[index + 1];
        temp += input[index + 2];
        temp += input[index + 3];
        // Append the converted string to result
        result += m[temp];
        index += 4;
    }
    // Print out the hexadecimal number result
    cout << "\033[1;1H\033[2J\033[1;4;32m\nYour hexadecimal number is:\033[0m " << result << "\n"
         << endl;
}