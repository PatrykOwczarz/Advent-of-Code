// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> inputString;

vector<int> squareBrackets = { 0,0 };
vector<int> brackets = { 0,0 };
vector<int> curlyBrackets = { 0,0 };
vector<int> arrows = { 0,0 };

vector<int> illegal = { 0,0,0,0 }; 
// illegal[0] = square brackets
// illegal[1] = brackets
// illegal[2] = curly brackets
// illegal[3] = arrows

void readInput() {
    fstream inputFile;
    int column = 0;

    inputFile.open("exampleInput.txt", ios::in);
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
        for (int j = 0; j < inputString.at(i).length(); j++) {
            if (inputString.at(i).substr(j, 1) == "[") {
                squareBrackets.at(0) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == "]") {
                squareBrackets.at(1) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == "(") {
                brackets.at(0) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == ")") {
                brackets.at(1) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == "{") {
                curlyBrackets.at(0) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == "}") {
                curlyBrackets.at(1) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == "<") {
                arrows.at(0) += 1;
            }
            else if (inputString.at(i).substr(j, 1) == ">") {
                arrows.at(1) += 1;
            }
        }

        // write the logic of example: "[" = 4, "]" = 3, "{" = 3, "}" = 4 --> corrupted.
        if (brackets.at(0) == squareBrackets.at(1) || curlyBrackets.at(0) == squareBrackets.at(1) || arrows.at(0) == squareBrackets.at(1)) {
            illegal.at(0) += 1;
        }
        else if (squareBrackets.at(0) == brackets.at(1) || curlyBrackets.at(0) == brackets.at(1) || arrows.at(0) == brackets.at(1)) {
            illegal.at(1) += 1;
        }
        else if (brackets.at(0) == curlyBrackets.at(1) || squareBrackets.at(0) == curlyBrackets.at(1) || arrows.at(0) == curlyBrackets.at(1)) {
            illegal.at(0) += 1;
        }
        else if (squareBrackets.at(0) == arrows.at(1) || curlyBrackets.at(0) == arrows.at(1) || brackets.at(0) == arrows.at(1)) {
            illegal.at(1) += 1;
        }
    }

    int sum = 0;
    sum += illegal.at(0) * 27;
    sum += illegal.at(1) * 3;
    sum += illegal.at(2) * 1197;
    sum += illegal.at(3) * 25137;

    cout << "The total syntax error score is: " << sum << "\n";



}

int main()
{
    solvePart1();
    for (int i = 0; i < inputString.size(); i++) {
        cout << inputString.at(i) << "\n";
    }
    
}

