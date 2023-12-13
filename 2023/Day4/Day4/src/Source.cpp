#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> input;

// function to read each line of input and store it in a string input vector

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

void SolveChallenge1() {
    vector<int> winningNumbers;
    vector<int> playNumbers;
    vector<int> points;
    int sum = 0;

    for (int i = 0; i < input.size(); i++) {
        string currentString = input[i];
        
        if (i < 10) {
            currentString.erase(currentString.begin(), currentString.begin() + 9);
        }
        else if (i >= 100) {
            currentString.erase(currentString.begin(), currentString.begin() + 9);
        }
        else {
            currentString.erase(currentString.begin(), currentString.begin() + 9);
        }
        //cout << currentString << endl;

        stringstream ss(currentString);
        bool winning = true;
        while (ss.good()) {
            string substr;
            getline(ss, substr, '|');
            
            if (winning) {
                
                stringstream ss2(substr);
                while (ss2.good()) {
                    string substr2;
                    getline(ss2, substr2, ' ');
                    if (substr2 != "") {
                        winningNumbers.push_back(stoi(substr2)); 
                        
                    }
                    
                }

                winning = false;
            }
            else {
                stringstream ss3(substr);
                
                while (ss3.good()) {
                    string substr3;
                    getline(ss3, substr3, ' ');
                    if (substr3 != "") {
                        playNumbers.push_back(stoi(substr3));

                    }
                    
                }
            }
            
        }
        sum = 0;
        for (int i = 0; i < playNumbers.size(); i++) {
            for (int j = 0; j < winningNumbers.size(); j++) {
                if (playNumbers[i] == winningNumbers[j]) {
                    if (sum == 0) {
                        sum = 1;
                    }
                    else {
                        sum = sum * 2;
                    }
                }
            }
        }
        if (sum > 0) {
            points.push_back(sum);
        }
        playNumbers.clear();
        winningNumbers.clear();

        
    }
    sum = 0;
    for (int i : points) {
        sum += i;
    }

    cout << "Answer for part 1: " << sum << endl;
}


int main() {

    readInput();
    SolveChallenge1();

    return 0;
}