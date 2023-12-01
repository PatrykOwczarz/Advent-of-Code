// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> input;
vector<int> intInput;

void convertToInt() {
    for (string i : input) {
        int num = atoi(i.c_str());
        intInput.push_back(num);
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

    convertToInt();
}

void solveChallenge1() {
    int count = 0;
    int temp = 0;

    readInput();

    for (int i : intInput) {
        if (temp == 0) {
            cout << i << " (N / A - no previous measurement)\n";
        }
        else if (temp > i) {
            cout << i << " (decreased)\n";
        }
        else if (temp < i) {
            cout << i << " (increased)\n";
            count += 1;
        }

        temp = i;
    }

    cout << "\nThe amount of measurements that are larger than the previous measurement is: " << count << "\n";
};

void solveChallenge2() {
    queue<int> window;
    int count = 0;
    int temp = 0;
    vector<int> finalArray;

    readInput();

    for (int i : intInput) {
        int sum = 0;
        window.push(i);
        if (window.size() == 3) {
            sum += window.front();
            window.pop();
            sum += (window.front() + window.back());
            finalArray.push_back(sum);
        }
    }

    for (int i : finalArray) {
        if (temp == 0) {
            cout << i << " (N / A - no previous measurement)\n";
        }
        else if (temp > i) {
            cout << i << " (decreased)\n";
        }
        else if (temp < i) {
            cout << i << " (increased)\n";
            count += 1;
        }
        else if (temp == i) {
            cout << i << " (no change)\n";
        }

        temp = i;
    }

    cout << "\nThe amount of measurements that are larger than the previous measurement is: " << count << "\n";

}

int main()
{
    //solveChallenge1();
    solveChallenge2();
    return 0;
}
