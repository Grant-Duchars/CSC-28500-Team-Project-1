#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

void binaryToHex(string);
void hexToBinary(string);

int main(int argc, char **argv) {
    
    string str;
    cout << "Enter hexadecimal to be converted to binary (Enter a space between every number)" <<endl;
    //cout << "Enter binary to be converted to hexadecimal (Enter in four bits and with a space between every four bits)" <<endl;
    getline(cin, str); 
    
    hexToBinary(str);
    //binaryToHex(str);
    
    return 0;
}

void binaryToHex(string input) {
    
    unordered_map<string, string> m; //A map storing the conversion values.

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

    char del = ' ';         //character delimiter
     
    string temp = "";       
    string temp1 = "";
    
    //cout << input[2] <<endl;
    
    for(int i=0; i<(int)input.size(); i++) {
    // If current char is not delimiter (space in this case), then append it to the "temp" string, then look in the map for it's equivalent hex value and append it to "temp1" string. 
    // Otherwise you have completed the word, print it, and then start a new word.
    
        if (input[i] != '0' && input[i] != '1' && input[i] != ' ') {        //Checking for valid input
            cout << "Enter a valid binary number" <<endl;
        }
        
        else if (input[i] != del){
            temp += input[i];
            temp1 += m[temp];
        }
        
        else{
            if (temp.size() != 4) {                                         //Checking if the binary number is entered in four bits
                cout << "The Binary number is not in 4 bits" <<endl;
            }
            else {
                cout << temp1 << " ";
                temp = "";
                temp1 = "";
                
            }
        }
    }
    
    if (temp.size() != 4) {
        cout << "The Binary number is not in 4 bits" <<endl;
    }
    
    else {
        cout << temp1 <<endl;
    }
}


void hexToBinary(string input) {
    
    unordered_map<string, string> m;
    
    m["0"] = "0000";
    m["1"] = "0001";
    m["2"] = "0010";
    m["3"] = "0011";
    m["4"] = "0100";
    m["5"] = "0101";
    m["6"] = "0110";
    m["7"] = "0111";
    m["8"] = "1000";
    m["9"] = "1001";
    m["A"] = "1010";
    m["B"] = "1011";
    m["C"] = "1100";
    m["D"] = "1101";
    m["E"] = "1110";
    m["F"] = "1111";

    char del = ' '; 
     
    string temp = "";
    string temp1 = "";

    for(int i=0; i<(int)input.size(); i++) {
    // If current char is not delimiter (space in this case), then append it to the "temp" string, then look in the map for it's equivalent binary value and append it to "temp1" string. 
    // Otherwise you have completed the word, print it, and then start a new word.
    
        if (!isxdigit(input[i]) && input[i] != ' '  )  {        //Checking for valid input
            cout << "Enter a valid Hexadecimal number" <<endl;
        }
    
        else if(input[i] != del){
            temp += input[i];
            temp1 += m[temp];
        }
        else{
            cout << temp1 << " ";
            temp = "";
            temp1 = "";
        }
    } 

    cout << temp1 <<endl;
}

