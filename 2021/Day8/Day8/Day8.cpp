// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> inputString;

vector<string> inputValues; //the left side of the puzzle input before the '|'
vector<string> outputValues; // the right side of the puzzle input after the '|'

vector<int> digitsCount(10, 0);

vector<string> dictionary(7, " ");

vector<int> codes;

string fourSubstring;

void readInput() {
    fstream inputFile;
    int column = 0;

    inputFile.open("input.txt", ios::in);
    if (!inputFile) {
        cout << "File not found!";
    }
    else if (inputFile.is_open()) {
        string tp;
        while (getline(inputFile, tp)) {
            if (!tp.empty()) {
                inputString.push_back(tp);
            }
        }
        inputFile.close();
    };

}

void solvePart1() {

    readInput();

    for (int i = 0; i < inputString.size(); i++) {
        string line = inputString.at(i);
        istringstream lineStream(line);

        string left;
        string right;

        getline(lineStream, left, '|');

        // processing output strings
        lineStream.get();
        while (getline(lineStream, right, ' ')) {
            outputValues.push_back(right);
        }
        //cout << left << "\n";
        for (int i = 0; i < outputValues.size(); i++) {
            if (outputValues.at(i).size() == 2) {
                digitsCount.at(1) += 1;
            }
            else if (outputValues.at(i).size() == 3) {
                digitsCount.at(7) += 1;
            }
            else if (outputValues.at(i).size() == 4) {
                digitsCount.at(4) += 1;
            }
            else if (outputValues.at(i).size() == 7) {
                digitsCount.at(8) += 1;
            }
            //cout << outputValues.at(i) << " ";
        }
        //cout << "\n";
        
        outputValues.clear();
        inputValues.clear();
        
    }

    int sum = 0;
    for (int i = 0; i < digitsCount.size(); i++) {
        sum += digitsCount.at(i);
    }
    cout << "The number of times digits 1, 4, 7 and 8 appear is: " << sum << "\n";
    
}

// I need to use the value for 1 to store values in dictionary(5) and dictionary(2) and then use those to find the value for the top
// from the random order of 7 for dictionary(0), than do the same with the value for 4 to then work out the answer.
void findPattern() {
    string seven, four, one;
    vector<string> zeroOrTwoOrFive;

    for (int i = 0; i < inputValues.size(); i++) {
        if (inputValues.at(i).length() == 2) {
            one = inputValues.at(i);
            dictionary.at(2) = inputValues.at(i).substr(0, 1);
            dictionary.at(5) = inputValues.at(i).substr(1, 1);
        }
        else if (inputValues.at(i).length() == 3) {
            seven = inputValues.at(i);
        }
        else if (inputValues.at(i).length() == 4) {
            four = inputValues.at(i);
        }
        else if (inputValues.at(i).length() == 5) {
            zeroOrTwoOrFive.push_back(inputValues.at(i));
        }
    }

    for (int i = 0; i < seven.length(); i++) {
        if (seven.substr(i, 1) != dictionary.at(2) && seven.substr(i, 1) != dictionary.at(5)) {
            dictionary.at(0) = seven.substr(i, 1);
        }
    }
    
    // Since I cant identify which letter corresponds to the 2 wire segments of four, I will use both to compare with the string of 9 to diferentiate 9's from 0's
    for (int i = 0; i < four.size(); i++) {
        if (four.substr(i,1) != dictionary.at(2) && four.substr(i, 1) != dictionary.at(5)) {
            fourSubstring = fourSubstring + four.substr(i, 1);
        }
    }

    // this finds the number 5 based on the number four substring and then finds the order of wires for the number 1.
    for (int i = 0; i < zeroOrTwoOrFive.size(); i++) {
        if ( zeroOrTwoOrFive.at(i).find(fourSubstring.substr(0,1)) < zeroOrTwoOrFive.at(i).length() && zeroOrTwoOrFive.at(i).find(fourSubstring.substr(1, 1)) < zeroOrTwoOrFive.at(i).length() ) {
            if (zeroOrTwoOrFive.at(i).find(one.substr(0, 1)) < zeroOrTwoOrFive.at(i).length()) {
                dictionary.at(5) = one.substr(0, 1);
                dictionary.at(2) = one.substr(1, 1);
            }
            else if (zeroOrTwoOrFive.at(i).find(one.substr(1, 1)) < zeroOrTwoOrFive.at(i).length()) {
                dictionary.at(5) = one.substr(1, 1);
                dictionary.at(2) = one.substr(0, 1);
            }
        }
    }
    
}

string findOutputDigits() {
    string temp;
    for (int i = 0; i < outputValues.size(); i++) {
        string s = outputValues.at(i);
        if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) < s.length()  && s.find(dictionary.at(5)) < s.length() && s.length() == 6 && ((s.find(fourSubstring.substr(0, 1)) == -1) ^ (s.find(fourSubstring.substr(1, 1)) == -1)) ) {
            temp = temp + "0";
        }
        else if (s.length() == 2) {
            temp = temp + "1";
        }
        else if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) < s.length()  && s.find(dictionary.at(5)) == -1 && s.length() == 5) {
            temp = temp + "2";
        }
        else if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) < s.length()  && s.find(dictionary.at(5)) < s.length() && s.length() == 5) {
            temp = temp + "3";
        }
        else if (s.length() == 4) {
            temp = temp + "4";
        }
        else if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) == -1  && s.find(dictionary.at(5)) < s.length() && s.length() == 5) {
            temp = temp + "5";
        }
        else if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) == -1  && s.find(dictionary.at(5)) < s.length() && s.length() == 6) {
            temp = temp + "6";
        }
        else if (s.length() == 3) {
            temp = temp + "7";
        }
        else if (s.length() == 7) {
            temp = temp + "8";
        }
        else if (s.find(dictionary.at(0)) < s.length() && s.find(dictionary.at(2)) < s.length()  && s.find(dictionary.at(5)) < s.length() && s.length() == 6 && s.find(fourSubstring.substr(0,1)) < s.length() && s.find(fourSubstring.substr(1, 1)) < s.length()) {
            temp = temp + "9";
        }

    }

    return temp;
}

// I need to work out what letters make up 1, then 7, then 4 and use those worked out values to work out the other numbers.
void solvePart2() {
    readInput();

    int test= 0;
    for (int i = 0; i < inputString.size(); i++) {
        string line = inputString.at(i);
        istringstream lineStream(line);

        string left;
        string right;

        getline(lineStream, left, '|');

        // processing input strings
        istringstream leftStream(left);
        while (getline(leftStream, left, ' ')) {
            inputValues.push_back(left);
        }
        
        findPattern();


        // processing output strings
        lineStream.get();
        while (getline(lineStream, right, ' ')) {
            outputValues.push_back(right);
        }   
        
        codes.push_back(atoi(findOutputDigits().c_str()));

        outputValues.clear();
        inputValues.clear();
        fourSubstring = "";
        
        for (int i = 0; i < dictionary.size(); i++) {
            cout << i << ":" << dictionary.at(i) << "  ";
        }
        cout  << codes.back() << "\n";
    }

    cout << "\n";

    int sum = 0;
    for (int i = 0; i < codes.size(); i++) {
        sum += codes.at(i);
    }
    cout << "Adding all the output values equals: " << sum << "\n";

}

int main()
{   
    solvePart2();
    /*
    cout << "\n";
    for (int i = 0; i < inputString.size(); i++) {
        cout << inputString.at(i) << "\n";
    }
    */
}
