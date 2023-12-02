#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
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

// Part 1 solution, convert each individual string character to int and work out if its an integer in the range 1-9.
// Construct a number string which can be used to find the first and last digits.

void solveChallenge1() {
    char ch;
    string number = "";
    vector<int> sum;
    for (string s : input) {
        number = "";
        for (int i = 0; i < s.size(); i++) {
            ch = s[i];
            if (((int)ch - 48) < 10) {
                number = number + ch;
            }
        }
        if (number.size() == 1) {
            number = number + number;
            sum.push_back(stoi(number));
            //cout << stoi(number) << endl;
        }
        else {
            string temp = number.substr(0,1) + number.substr(number.size() - 1, 1);
            sum.push_back(stoi(temp));
            //cout << stoi(temp) << endl;
        }
    }

    // sums the total value for the answer.

    int total = 0;
    for (int i : sum) {
        total += i;
    }
    cout << "Answer to part 1: " << total << endl;

}

// change the solution to instead of just finding one instance of a word, change the existing word to the number it represents
// i.e eight -> 8, and then parse the string of numbers like in part 1.
// figure out edge cases such as eighthree -> to avoid issues, dont replace whole word but instead replace the middle, leaving the first and last
// like this -> eight -> e8t, so if the edge case eighthree occurrs -> you get e8three -> e8t3e and can parse the 8 and 3 like in part 1.

void solveChallenge2() {

    // map used to map the int to its string version.

    map<int, string> wordToInt;
    wordToInt[1] = "one";
    wordToInt[2] = "two";
    wordToInt[3] = "three";
    wordToInt[4] = "four";
    wordToInt[5] = "five";
    wordToInt[6] = "six";
    wordToInt[7] = "seven";
    wordToInt[8] = "eight";
    wordToInt[9] = "nine";

    vector<int> sum;

    // for each line of input, find each version the written number and convert it to its int version whilst leaving
    // the first and last character in case the edge case is present as described above the solveChallenge2 method.
    // example: my first line was threerznlrhtkjp23mtflmbrzq395three, on a first pass the algorithm will change the first "three" to "t3e"
    // threerznlrhtkjp23mtflmbrzq395three -> t3erznlrhtkjp23mtflmbrzq395three -> t3erznlrhtkjp23mtflmbrzq395t3e is the final string.
    for (string s : input) {
        for (int i = 1; i < 10; i++) {
            
            while (s.find(wordToInt[i]) != string::npos) {
                int pos = s.find(wordToInt[i]);
                s.replace(pos+1, wordToInt[i].size() - 2, to_string(i));
                //cout << s << endl;
            }
        }

        // same code below as part 1

        char ch;
        string number = "";

        for (int i = 0; i < s.size(); i++) {
            ch = s[i];
            if (((int)ch - 48) < 10) {
                number = number + ch;
            }
        }
        if (number.size() == 1) {
            number = number + number;
            sum.push_back(stoi(number));
            //cout << stoi(number) << endl;
        }
        else {
            string temp = number.substr(0, 1) + number.substr(number.size() - 1, 1);
            sum.push_back(stoi(temp));
            //cout << stoi(temp) << endl;
        }

    }

    // sums the total value for the answer.

    int total = 0;
    for (int i = 0; i < sum.size(); i++) {
        total += sum[i];
    }

    cout << "Answer to part 2: " << total << endl;

}

int main()
{
    readInput();
    solveChallenge1();
    solveChallenge2();
    return 0;
}
