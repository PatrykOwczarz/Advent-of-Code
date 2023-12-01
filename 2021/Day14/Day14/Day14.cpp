// Day14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string initialTemplate = "VCOPVNKPFOOVPVSBKCOF";
string initialTemplateEx = "NNCB";

vector<string> input;
vector<string> output;

map<string, int> countMap;

void readInput() {

    ifstream inputFileStream;
    inputFileStream.open("exampleInput.txt");

    if (!inputFileStream.is_open()) {
        cout << "File doesn't exist!";
    }

    while (inputFileStream) {
        string line;
        getline(inputFileStream, line);

        istringstream lineStream(line);

        string arrow;

        string temp1;
        string temp2;

        getline(lineStream, temp1, ' ');
        getline(lineStream, arrow, ' ');
        getline(lineStream, temp2);

        if (!inputFileStream) {
            break;
        }

        input.push_back(temp1);
        output.push_back(temp2);

        cout << temp1 << " " << arrow << " " << temp2  << "\n";
    }
    
}

//Use frequency map.

void solvePart1() {
    readInput();
    for (int i = 0; i < initialTemplateEx.length(); i ++) {
        countMap[initialTemplateEx.substr(i, 1)] += 1;
    }

    for () {

    }

    for (auto it = countMap.begin(); it != countMap.end(); it++) {
        cout << it->first << " => " << it->second << '\n';
    }

}

int main()
{
    solvePart1();
}

