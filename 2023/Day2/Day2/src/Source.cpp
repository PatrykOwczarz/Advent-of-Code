#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

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

void solveChallenge1() {
    string gameID;
    bool isPossible = true;
    int total = 0;
    int count = 1;

    vector<int> powers;
    uint64_t totalPowers = 0;
    int minRed, minBlue, minGreen;

    for (string s : input) {
        minRed = 0;
        minBlue = 0;
        minGreen = 0;

        if (count < 10) {
            gameID = s.substr(5, 1);
        }
        else if(count > 10 && count < 100) {
            gameID = s.substr(5, 2);
            cout << gameID << endl;
        }
        else {
            gameID = s.substr(5, 3);
        }
        auto index = s.find(":");
        s.erase(s.begin(), s.begin() + index+1);
        //cout << s << endl;
        
        stringstream ss(s);
        
        while (ss.good()) {
            string substr;
            getline(ss, substr, ';');
            //cout << substr << endl;

            stringstream ss2(substr);

            while (ss2.good()) {
                string substr2;
                getline(ss2, substr2, ',');

                if (substr2[0] == ' ') {
                    substr2.erase(substr2.begin(), substr2.begin()+1);
                }
                //cout << substr2 << endl;

                stringstream ss3(substr2);
                string num = "";
                string color = "";
                bool isNum = true;

                while(ss3.good()) {
                    string substr3;
                    getline(ss3, substr3, ' ');
                    //cout << substr3 << endl;
                    if (isNum) {
                        num = substr3;
                        isNum = false;
                    }
                    else {
                        color = substr3;
                    }

                }

                 // ------- Solution to Challenge 2 --------------------------
                if (color == "red" && minRed < stoi(num)) {
                    minRed = stoi(num);
                }
                else if (color == "blue" && minBlue < stoi(num)) {
                    minBlue = stoi(num);
                }
                else if (color == "green" && minGreen < stoi(num)) {
                    minGreen = stoi(num);
                }
                // -----------------------------------------------------------


                if (color == "red" && stoi(num) > 12) {
                    isPossible = false;
                }
                else if (color == "green" && stoi(num) > 13) {
                    isPossible = false;
                }
                else if (color == "blue" && stoi(num) > 14) {
                    isPossible = false;
                }

                //cout << "num: " << num << ", color: " << color << endl;

            }
            
            //cout << endl;
        }
        if (isPossible) {
            total += stoi(gameID);
        }
        else {
            isPossible = true;
        }
        // ------- Solution to Challenge 2 --------------------------
        //cout << "Power of " << gameID << " is: " << minRed << " * "  << minGreen <<  " * "<< minBlue << endl;
        powers.push_back(minRed * minGreen * minBlue);
        // -----------------------------------------------------------

        count++;
        
    }

    // ------- Solution to Challenge 2 --------------------------
    for (int i = 0; i < powers.size(); i++) {
        totalPowers += powers[i];
    }
    // -----------------------------------------------------------

    cout << "Part 1 Solution: " << total << endl;
    cout << "Part 2 Solution: " << totalPowers << endl;

}

int main() 
{
    readInput();
    solveChallenge1();
    return 0;
}