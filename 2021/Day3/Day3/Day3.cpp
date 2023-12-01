// Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> input;

int count1, count0;
string gamma, epsilon;

void findGamma() {
    for (int i = 0; i < input.at(0).size(); i++) {
        count1 = 0;
        count0 = 0;
        for (string inp : input) {
            if (inp.substr(i, 1) == "0") {
                count0 += 1;
            }
            else if (inp.substr(i, 1) == "1") {
                count1 += 1;
            }
        }
        if (count1 > count0) {
            gamma = gamma + "1";
        }
        else {
            gamma = gamma + "0";
        }
    }
}

void findEpsilon() {
    for (int i = 0; i < gamma.size(); i++) {
        if (gamma.substr(i,1) == "0") {
            epsilon = epsilon + "1";
        }
        else {
            epsilon = epsilon + "0";
        }
    }
}
    
string findOxygen(){
    vector<string> tempStrings = input;
    vector<string> tempTest;
    int i = 0;
    while (i < input.at(0).size() && tempStrings.size() > 1) {
        count0 = 0;
        count1 = 0;
        for (string inp : tempStrings) {
            if (inp.substr(i, 1) == "0") {
                count0 += 1;
            }
            else if (inp.substr(i, 1) == "1") {
                count1 += 1;
            }
        }

        if (count1 > count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "1") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        else if (count1 < count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "0") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        else if (count1 == count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "1") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        tempStrings = tempTest;
        tempTest.clear();
        i++;
    }
    cout << "size of Oxygen tempStrings: " << tempStrings.size() << "\n";

    return tempStrings.at(0);
}

string findCO2() {
    vector<string> tempStrings = input;
    vector<string> tempTest;
    int i = 0;
    while(i < input.at(0).size() && tempStrings.size() > 1){
        count0 = 0;
        count1 = 0;
        for (string inp : tempStrings) {
            if (inp.substr(i, 1) == "0") {
                count0 += 1;
            }
            else if (inp.substr(i, 1) == "1") {
                count1 += 1;
            }
        }
        if (count1 > count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "0") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        else if (count1 < count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "1") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        else if (count1 == count0) {
            for (int j = 0; j < tempStrings.size(); j++) {
                if (tempStrings.at(j).substr(i, 1) == "0") {
                    tempTest.push_back(tempStrings.at(j));
                }
            }
        }
        i++;
        tempStrings = tempTest;
        tempTest.clear();
        
    }
    cout << "size of CO2 tempStrings: " << tempStrings.size() << "\n";

    return tempStrings.at(0);
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

}

// reference: https://www.sanfoundry.com/cpp-program-binary-number-into-decimal/
int binaryToDecimal(long long int num) {
    long long int temp;
    int rem, dec = 0, b = 1;
    temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        dec = dec + rem * b;
        b *= 2;
        temp /= 10;
    }
    cout << "The decimal equivalent of " << num << " is " << dec << "\n";
    return dec;
}

void solvePart1() {
    int powerConsumption = 0;
    readInput();
    findGamma();
    findEpsilon();

    int temp1 = binaryToDecimal(atoi(gamma.c_str()));
    char* endptr = NULL;
    int temp2 = binaryToDecimal(strtoll(epsilon.c_str(), &endptr, 10));
    powerConsumption = temp1 * temp2;
    cout << "The power consumption is: " << powerConsumption << "\n";
}

void solvePart2() {
    int lifeSupport = 0;
    readInput();
    long long int tempOxy = strtoll(findOxygen().c_str(), NULL, 10);
    long long int tempCO2 = strtoll(findCO2().c_str(), NULL, 10);

    lifeSupport = binaryToDecimal(tempOxy) * binaryToDecimal(tempCO2);
    cout << "The Life Support rating is: " << lifeSupport << "\n";
}

int main()
{
    //solvePart1();
    solvePart2();

}