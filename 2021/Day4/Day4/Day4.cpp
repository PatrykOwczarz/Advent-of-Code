// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> input;

/* test numbers from example on advent of code
vector<int> bingoNumbers = { 7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1 };
*/

vector<int> bingoNumbers =
{ 6,69,28,50,36,84,49,13,48,90,1,33,71,0,94,59,53,58,60,96,30,34,29,91,11,41,77,95,17,80,85,93,7,9,74,89,18,25,26,8,87,38,68,5,12,43,27,46,62,73,16,
55,22,4,65,76,54,52,83,10,21,67,15,47,45,40,35,66,79,51,75,39,64,24,37,72,3,44,82,32,78,63,57,2,86,31,19,92,14,97,20,56,88,81,70,61,42,99,23,98 };


int bingoBoard[5][5];
int boardCount = 0;

int counter = 0;
int bingoCount = 0;
int sum = 0;

string bestOutcome;
int bestBingoBoard;
string worstOutcome;
int worstBingoBoard;

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
                input.push_back(tp);
            }
        }
        inputFile.close();
    };

}

void createBingoBoard() {
    for (int i = counter; i < (counter + 5); i++) {
        size_t pos = 0;
        string space_delim = " ";
        int row = 0;

        while ((pos = input.at(i).find(space_delim)) != string::npos) {
            if (pos != 0) {
                bingoBoard[row][(i - (boardCount * 5))] = atoi(input.at(i).substr(0, pos).c_str());
                row++;
            }
            input.at(i).erase(0, pos + space_delim.length());
        }
        bingoBoard[4][(i - (boardCount * 5))] = atoi(input.at(i).substr(0, 2).c_str());
    }
    counter += 5;
    boardCount += 1;
}

bool checkIfSolved() {
    for (int row = 0; row < 5; row++) {
        if (bingoBoard[row][0] == bingoBoard[row][1] && bingoBoard[row][1] == bingoBoard[row][2]  && bingoBoard[row][2] == bingoBoard[row][3] && bingoBoard[row][3] == bingoBoard[row][4] && bingoBoard[row][4] == 404) {
            return true;
        }
    }
    for (int column = 0; column < 5; column++) {
        if (bingoBoard[0][column] == bingoBoard[1][column] && bingoBoard[1][column] == bingoBoard[2][column] && bingoBoard[2][column] == bingoBoard[3][column] && bingoBoard[3][column] == bingoBoard[4][column] && bingoBoard[4][column] == 404) {
            return true;
        }
    }
    return false;
}

void sumBoard() {
    sum = 0;
    for (int column = 0; column < 5; column++) {
        for (int row = 0; row < 5; row++) {
            if (bingoBoard[row][column] != 404) {
                sum += bingoBoard[row][column];
            }
        }
    }

}

void solveBingo() {
    bool solved = false;
    bingoCount = 0;
    for (int i = 0; i < bingoNumbers.size(); i++) {
        for (int column = 0; column < 5; column++) {
            for (int row = 0; row < 5; row++) {
                if (bingoBoard[row][column] == bingoNumbers.at(i)) {
                    //cout << "test: " << bingoNumbers.at(i) << " " << bingoBoard[row][column] << "\n";
                    bingoBoard[row][column] = 404;
                }
                
            }
        }
        if (checkIfSolved()) {
            bingoCount = i;
            break;
        }
        bingoCount++;
    }
    if (checkIfSolved()) {
        sumBoard();
        cout << "\n" << boardCount << ": board solved by number " << bingoCount << ": " << bingoNumbers.at(bingoCount) << ". The sum is: " << (sum * bingoNumbers.at(bingoCount)) << "\n\n";
        if (bestBingoBoard == 0) {
            bestBingoBoard = bingoCount;
            bestOutcome = to_string(boardCount) + ": board solved by number " + to_string(bingoCount) + ": " + to_string(bingoNumbers.at(bingoCount)) + ". The sum is: " + to_string((sum * bingoNumbers.at(bingoCount)));

        }
        else if (bestBingoBoard > bingoCount) {
            bestBingoBoard = bingoCount;
            bestOutcome = to_string(boardCount) + ": board solved by number " + to_string(bingoCount) + ": " + to_string(bingoNumbers.at(bingoCount)) + ". The sum is: " + to_string((sum * bingoNumbers.at(bingoCount)));
        }

        if (worstBingoBoard < bingoCount) {
            worstBingoBoard = bingoCount;
            worstOutcome = to_string(boardCount) + ": board solved by number " + to_string(bingoCount) + ": " + to_string(bingoNumbers.at(bingoCount)) + ". The sum is: " + to_string((sum * bingoNumbers.at(bingoCount)));
        }
    }
}

void solvePart1() {
    readInput();
    // limit create bingo board so that it doesnt overflow;
    cout << input.size() << "\n\n";

    for (int i = 0; i < bingoNumbers.size(); i++) {
        cout << bingoNumbers.at(i) << " ";
    }
    cout << "\n\n";

    while (counter < input.size()) {

        cout << "---------------------------------------------------------- \n\n";
        createBingoBoard();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << bingoBoard[j][i] << " ";
            }
            cout << "\n";
        }

        solveBingo();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << bingoBoard[j][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "The best outcome is:\n";
    cout << bestOutcome << "\n";
}

void solvePart2() {
    readInput();
    // limit create bingo board so that it doesnt overflow;
    cout << input.size() << "\n\n";

    for (int i = 0; i < bingoNumbers.size(); i++) {
        cout << bingoNumbers.at(i) << " ";
    }
    cout << "\n\n";

    while (counter < input.size()) {

        cout << "---------------------------------------------------------- \n\n";
        createBingoBoard();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << bingoBoard[j][i] << " ";
            }
            cout << "\n";
        }

        solveBingo();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << bingoBoard[j][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "The worst outcome is:\n";
    cout << worstOutcome << "\n";
}

int main()
{
    //solvePart1();
    solvePart2();
}