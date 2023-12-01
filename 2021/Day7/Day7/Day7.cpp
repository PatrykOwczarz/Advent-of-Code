// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// example input
//vector<int> input{ 16,1,2,0,4,2,7,1,2,14 };

// my input
vector<int> input;
vector<string> stringInput;

vector<int> fuel;
int maxValue;
int sum;

int bestValue;
string bestResult;

void convertToInt() {
    for (string i : stringInput) {
        int num = atoi(i.c_str());
        input.push_back(num);
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
        while (getline(inputFile, tp, ',')) {
            stringInput.push_back(tp);
        }
        inputFile.close();
    };

    convertToInt();
}

void solvePart1() {
    for (int i = 0; i < input.size(); i++) {
        sum += input.at(i);
        if (maxValue < input.at(i)) {
            maxValue = input.at(i);
        }
    }

    vector<int> fuel(maxValue);
    bestValue = 0;

    for (int i = 0; i < maxValue; i++) {
        for (int j = 0; j < input.size(); j++) {
            int temp = input.at(j) - i;
            if (temp < 0) {
                temp = -temp;
            }
            fuel.at(i) += temp;
        }
        if (bestValue == 0) {
            bestValue = fuel.at(i);
            bestResult = "The best fuel result for part 1 is at value : " + to_string(i) + " of  " + to_string(fuel.at(i));
        }
        else if (bestValue > fuel.at(i)) {
            bestValue = fuel.at(i);
            bestResult = "The best fuel result for part 1 is at value : " + to_string(i) + " of  " + to_string(fuel.at(i));
        }
        //cout << "The fuel at value: " << i << " is " << fuel.at(i) << "\n";
    }

    cout << "\n" << bestResult << "\n";

}

void solvePart2() {
    for (int i = 0; i < input.size(); i++) {
        sum += input.at(i);
        if (maxValue < input.at(i)) {
            maxValue = input.at(i);
        }
    }

    vector<int> fuel(maxValue);
    bestValue = 0;

    for (int i = 0; i < maxValue; i++) {
        for (int j = 0; j < input.size(); j++) {
            int temp = input.at(j) - i;
            if (temp < 0) {
                temp = -temp;
            }
            fuel.at(i) += (temp*(temp+1))/2;
        }

        if (bestValue == 0) {
            bestValue = fuel.at(i);
            bestResult = "The best fuel result for part 2 is at value : " + to_string(i) + " of  " + to_string(fuel.at(i));
        }
        else if (bestValue > fuel.at(i)) {
            bestValue = fuel.at(i);
            bestResult = "The best fuel result for part 2 is at value : " + to_string(i) + " of  " + to_string(fuel.at(i));
        }
        //cout << "The fuel at value: " << i << " is " << fuel.at(i) << "\n";
    }

    cout << "\n" << bestResult << "\n";

}

int main()
{
    readInput();
    solvePart1();
    solvePart2();
}

