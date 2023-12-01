// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> input;

vector<string> direction;
vector<int> amount;

int depth = 0;
int horizontal = 0;
int aim = 0;

void splitInstruction() {
    string delimiter = " ";
    string instruction;
    size_t pos = 0;

    for (string i : input) {
        pos = i.find(delimiter);
        instruction = i.substr(0, pos);
        direction.push_back(instruction);
        i.erase(0, pos + delimiter.length());

        int num = atoi(i.c_str());
        amount.push_back(num);
    }
}

void readInput() {
    fstream inputFile;

    inputFile.open("input.txt", ios::in);
    if (!inputFile) {
        cout << "File not found!";
    }
    else if (inputFile.is_open()) {
        string tp;
        while (getline(inputFile, tp)) {
            input.push_back(tp);
        }
        inputFile.close();
    };

    splitInstruction();
}

void solvePart1() {
    readInput();
    
    for (int i = 0; i < direction.size(); i++) {
        if (direction.at(i) == "up") {
            depth -= amount.at(i);
        }
        else if (direction.at(i) == "down") {
            depth += amount.at(i);
        }
        else if (direction.at(i) == "forward") {
            horizontal += amount.at(i);
        }
    }

    cout << "The final horizontal position multiplied by the final depth for part 1 is: " << (depth * horizontal) << "\n";

    depth = 0;
    horizontal = 0;
}

void solvePart2() {

    for (int i = 0; i < direction.size(); i++) {
        if (direction.at(i) == "up") {
            aim -= amount.at(i);
        }
        else if (direction.at(i) == "down") {
            aim += amount.at(i);
        }
        else if (direction.at(i) == "forward") {
            horizontal += amount.at(i);
            depth += aim * amount.at(i);
        }
    }

    cout << "The final horizontal position multiplied by the final depth for part 2 is: " << (depth * horizontal) << "\n";

}

int main()
{
    solvePart1();
    solvePart2();

    return 0;
}
