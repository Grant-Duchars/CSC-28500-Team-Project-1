/*
Team Name: XXXXXX
Team Members: Grant Duchars,
October 10, 2022 - Applied Discrete Structures, Fall 2022, Dr. J

Description: A menu-driven program to convert user entered numbers
Possible convertions include: Decimal to Binary,
                              Hexadecimal to Binary,
                              Binary to Decimal,
                              Binary to Hexadecimal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertDecimalToBinary(char *input);
void convertDecimalToBinaryHelper(int num, char *result);
void convertBinaryToDecimal(char *input);
void convertHexToBinary(char *input);

int main()
{
    // Clear out terminal output
    printf("\033[1;1H\033[2J\n\n\n");
    while (true)
    {
        // Prompt user with menu
        printf("\033[1;35mCatchy Name Conversion Program\n\n\033[0;36m1. Convert base 10 to binary\n2. Convert binary to base 10\n3. Convert base 16 to binary\n4. Convert binary to base 16\n5. End program\n\n\033[33mPlease enter your selection:\033[0m ");
        char *inputBuffer = (char *)malloc(32);
        strcpy(inputBuffer, "");
        char *numBuffer = (char *)malloc(1024);
        strcpy(numBuffer, "");
        // Get user input
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        // Remove new line character from user input
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        // Check which option user selected
        if (inputBuffer == NULL) // ERROR: No command entered
        {
            printf("\033[1;1H\033[2J\033[4;31m\nERROR: Please enter a number from the list\033[0m\n\n");
        }
        else if (strcmp(inputBuffer, "1") == 0) // Convert Decimal to Binary
        {
            printf("\033[1;1H\033[2J\033[33m\nPlease enter your base 10 number to convert to binary:\033[0m ");
            fgets(numBuffer, sizeof(numBuffer), stdin);
            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
            convertDecimalToBinary(numBuffer);
        }
        else if (strcmp(inputBuffer, "2") == 0) // Convert Binary to Decimal
        {
            printf("\033[1;1H\033[2J\033[33m\nPlease enter your binary number to convert to base 10:\033[0m ");
            fgets(numBuffer, sizeof(numBuffer), stdin);
            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
            convertBinaryToDecimal(numBuffer);
        }
        else if (strcmp(inputBuffer, "3") == 0) // Convert Hexadecimal to Binary
        {
            printf("\033[1;1H\033[2J\033[33m\nPlease enter your base 16 number to convert to binary:\033[0m ");
            fgets(numBuffer, sizeof(numBuffer), stdin);
            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
            convertHexToBinary(numBuffer);
        }
        else if (strcmp(inputBuffer, "4") == 0) // Convert Binary to Hexadecimal
        {
            printf("\033[1;1H\033[2J\033[33m\nPlease enter your binary number to convert to base 16:\033[0m ");
            fgets(numBuffer, sizeof(numBuffer), stdin);
            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
            // TODO: convertBinaryToHex(numBuffer);
        }
        else if (strcmp(inputBuffer, "5") == 0) // Exit the program
        {
            printf("\033[1;1H\033[2J\033[1;32m\nThank you for using Catchy Name Conversion Program\033[0m\n\n");
            return 0;
        }
        else // ERROR: Wrong command entered
        {
            printf("\033[1;1H\033[2J\033[4;31m\nERROR: Please enter a number from the list\033[0m\n\n");
        }
        free(numBuffer);
        free(inputBuffer);
    }
}

/**
 * Function to convert a decimal integer to a binary integer
 * @param input A string of the number you wish to convert
 */
void convertDecimalToBinary(char *input)
{
    // Convert string to integer
    int num = atoi(input);
    // Allocate space for result string
    char *result = (char *)malloc(1024);
    // Clear out the result string
    strcpy(result, "");
    // Recursively run the function until num is zero
    convertDecimalToBinaryHelper((num / 2), result);
    // After recursion append last digit
    (num % 2) ? strcat(result, "1") : strcat(result, "0");
    // Print out the binary number result
    printf("\033[1;1H\033[2J\033[1;4;32m\nYour binary number is:\033[0m %s\n\n", result);
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
void convertBinaryToDecimal(char *input)
{
    // Initialize decimal result variable
    int result = 0;
    // Calculate most significant bit's power
    int power = strlen(input) - 2;
    // Loop through binary number string
    for (int i = 0; input[i] != '\0'; ++i)
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
    printf("\033[1;1H\033[2J\033[1;4;32m\nYour decimal number is:\033[0m %d\n\n", result);
}

void convertHexToBinary(char *input)
{
    char *binaryNumber = (char *)malloc(1024);
    strcpy(binaryNumber, "");
    for (int i = 0; input[i] != '\0'; ++i)
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
    int cutIndex = 0;
    while (binaryNumber[cutIndex] != '1')
    {
        ++cutIndex;
    }
    char *result = binaryNumber + cutIndex;
    printf("\033[1;1H\033[2J\033[1;4;32m\nYour binary number is:\033[0m %s\n", result);
    free(binaryNumber);
}

void convertBinaryToHex(char num[])
{
    // TODO: Implement this
}