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

}


void solveChallenge1() {
    readInput();
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

    int total = 0;
    for (int i : sum) {
        total += i;
    }
    cout << total << endl;

}

// change the solution to instead of just finding one instance of a word, change the existing word to the number it represents
// i.e eight -> 8, and then parse the string of numbers like in part 1.
// figure out edge cases such as eighthree -> to avoid issues, dont replace whole word but instead replace the middle, leaving the first and last
// like this -> eight -> e8t, so if the edge case eighthree occurrs -> you get e8three -> e8t3e and can parse the 8 and 3 like in part 1.

void solveChallenge2() {
    readInput();
    //int digits[10];
    vector<int> sums;
    char ch;
    int intFirst = 0;
    int intLast = 0;

    for (string s : input) {

        intFirst = s.size();
        intLast = 0;

        for (int i = 0; i < s.size(); i++) {
            ch = s[i];
            if (((int)ch - 48) < 10) {
                if (intFirst > i) {
                    intFirst = i;
                }
                if (intLast < i) {
                    intLast = i;
                }
            }
        }

        int digits[10];
        
        for (int i = 0; i < 10; i++) {
           digits[i] = 0;
        }

        
        digits[1] = s.find("one");
        digits[2] = s.find("two");
        digits[3] = s.find("three");
        digits[4] = s.find("four");
        digits[5] = s.find("five");
        digits[6] = s.find("six");
        digits[7] = s.find("seven");
        digits[8] = s.find("eight");
        digits[9] = s.find("nine");
        
        
        int first = 1; int last = 1;
        int firstIndex = s.size(); int lastIndex = 0;
        for (int i = 1; i < 10; i++) {
            if (digits[i] == -1) {

            }
            else {
                if (digits[i] < firstIndex) {
                    firstIndex = digits[i];
                    first = i*10;
                }
                if (digits[i] > lastIndex) {
                    lastIndex = digits[i];
                    last = i;
                }
            } 
        }
        int numToPush = 0;

        if (firstIndex < intFirst) {
            numToPush = first;
        }
        else {
            numToPush = stoi(s.substr(intFirst, 1)) * 10;
        }

        if (lastIndex > intLast) {
            numToPush += last;
        }
        else {
            numToPush += stoi(s.substr(intLast, 1));
        }

        //cout << "min: " << first << ", max: " << last << endl;
        cout << numToPush << endl;
        sums.push_back(numToPush);


    }
    
    int total = 0;
    for (int i : sums) {
        total += i;
    }

    cout << total << endl;


}

int main()
{
    //solveChallenge1();
    solveChallenge2();
    return 0;
}
