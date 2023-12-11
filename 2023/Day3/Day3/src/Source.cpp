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


void SolveChallenge1() {
    vector<vector<char>> matrix;
    vector<string> answers;
    int sum = 0;

    for (int column = 0; column < input.size(); column++) {
        vector<char> temp;
        for (int row = 0; row < input[column].size(); row++) {
            temp.push_back(input[column][row]);
        }
        matrix.push_back(temp);
    }

    // go through each character in the matrix
    for (int column = 0; column < input.size(); column++) {
        for (int row = 0; row < input[column].size(); row++) {

            // if the given char is a symbol
            if ((int)matrix[column][row] % 33 < 15 && (int)matrix[column][row] % 33 !=13 || (int)matrix[column][row] % 61 == 0 || (int)matrix[column][row] % 64 == 0) {
                
                // go through the adjacent characters to find if any of them is a number between 0 and 9
                for (int i = column - 1; i <= column + 1; i++) {
                    string number = "";
                    for (int j = row - 1; j <= row + 1; j++) {
                        
                        char temp = matrix[i][j];
                        bool loop = true;
                        // checks if any of the chars is a number
                        if ((int)temp % 48 < 10) {
                            // if the number is on the left side then search all adjacent numbers to the left until dot or index 0
                            if (j < row) {
                                int count = 0;
                                while (loop) {
                                    if ((j - count) >= 0) {
                                        if ((int)matrix[i][j - count] % 48 < 10) {
                                            number = matrix[i][j - count] + number;
                                            count++;
                                        }
                                        else {
                                            loop = false;
                                        }
                                    }
                                    else {
                                        loop = false;
                                    }
                                }
                            }
                            // if the number is on the right side then search all adjacent numbers to the right until dot or max size index
                            else if (row < j) {
                                int count = 0;
                                while (loop) {
                                    if ((j + count) < matrix[i].size()) {
                                        if ((int)matrix[i][j + count] % 48 < 10) {
                                            number += matrix[i][j + count];
                                            count++;
                                        }
                                        else {
                                            loop = false;
                                            answers.push_back(number);
                                            number = "";
                                        }
                                        
                                    }
                                    else {
                                        loop = false;
                                        answers.push_back(number);
                                        number = "";
                                    }

                                }
                            }
                            // if middle of the 3 values and a number, just add the charcter.
                            else {
                                number += temp;
                            }
                        }
                        // if dot or any of the symbols, add the number to the array of gear numbers.
                        else if ((int)temp % 46 == 0 || (int)temp % 33 < 15) {
                            if (number != "") {
                                answers.push_back(number);
                                number = "";
                            }
                        }
                    }
                }
            }
        }
    }
    // sum the answers and print the final value.
    for (int i = 0; i < answers.size(); i++) {
        sum += stoi(answers[i]);
        //cout << answers[i] << endl;
    }

    cout << "The answer to part 1: " << sum << endl << endl;

}

void SolveChallenge2() {

    vector<vector<char>> matrix;
    vector<string> answers;
    vector<int> gearNumbers;
    int sum = 0;
    

    for (int column = 0; column < input.size(); column++) {
        vector<char> temp;
        for (int row = 0; row < input[column].size(); row++) {
            temp.push_back(input[column][row]);
        }
        matrix.push_back(temp);
    }

    // go through each character in the matrix
    for (int column = 0; column < input.size(); column++) {
        for (int row = 0; row < input[column].size(); row++) {

            // if the given char is a symbol
            if ((int)matrix[column][row] % 42 == 0 && (int)matrix[column][row] % 33 != 13) {

                // go through the adjacent characters to find if any of them is a number between 0 and 9;
                for (int i = column - 1; i <= column + 1; i++) {
                    string number = "";
                    for (int j = row - 1; j <= row + 1; j++) {

                        char temp = matrix[i][j];
                        bool loop = true;
                        // checks if any of the chars is a number
                        if ((int)temp % 48 < 10) {
                            // if the number is on the left side then search all adjacent numbers to the left until dot or index 0
                            if (j < row) {
                                int count = 0;
                                while (loop) {
                                    if ((j - count) >= 0) {
                                        if ((int)matrix[i][j - count] % 48 < 10) {
                                            number = matrix[i][j - count] + number;
                                            count++;
                                        }
                                        else {
                                            loop = false;
                                        }
                                    }
                                    else {
                                        loop = false;
                                    }
                                }
                            }
                            // if the number is on the right side then search all adjacent numbers to the right until dot or max size index
                            else if (row < j) {
                                int count = 0;
                                while (loop) {
                                    if ((j + count) < matrix[i].size()) {
                                        if ((int)matrix[i][j + count] % 48 < 10) {
                                            number += matrix[i][j + count];
                                            count++;
                                        }
                                        else {
                                            loop = false;
                                            answers.push_back(number);
                                            number = "";
                                        }

                                    }
                                    else {
                                        loop = false;
                                        answers.push_back(number);
                                        number = "";
                                    }

                                }
                            }
                            // if middle of the 3 values and a number, just add the charcter.
                            else {
                                number += temp;
                            }
                        }
                        // if dot or any of the symbols, add the number to the array of gear numbers.
                        else if ((int)temp % 46 == 0 || (int)temp % 33 < 15) {
                            if (number != "") {
                                answers.push_back(number);
                                number = "";
                            }
                        }
                    }
                }
                // if the size of the answer array is exactly 2, then multiply the gear numbers together and add to gear number vector.
                if (answers.size() == 2) {
                    
                    sum = stoi(answers[0]) * stoi(answers[1]);
                    
                    gearNumbers.push_back(sum);
                    sum = 0;
                }
                answers.clear();

            }
        }
    }
    // sum gear numbers and print the answer.
    sum = 0;
    for (int i = 0; i < gearNumbers.size(); i++) {
        sum += gearNumbers[i];
        //cout << gearNumbers[i] << endl;
    }

    cout << "The answer to part 2: " << sum << endl;

}

int main() {

    readInput();
    SolveChallenge1();
    SolveChallenge2();

    return 0;
}




/* Recursive solution that doesnt work

string RecursiveNeighbour(const vector<vector<char>> &matrix, int col, int row, int prevRow) {
    if (row == 0) {
        return to_string(matrix[col][row]);
    }
    if (row == matrix[col].size()-1) {
        return to_string(matrix[col][row]);
    }
    else {
        if (matrix[col][row - 1] % 48 < 10 && prevRow != row - 1) {
            return RecursiveNeighbour(matrix, col, row - 1, row) + to_string(matrix[col][row]);
        }
        else if (matrix[col][row + 1] % 48 < 10 && prevRow != row + 1) {
            return to_string(matrix[col][row]) + RecursiveNeighbour(matrix, col, row + 1, row);
        }
        else {
            return to_string(matrix[col][row]);
        }
    }


}

string LeftNeighbour(const vector<vector<char>>& matrix, int col, int row) {
    if (row == 0) {
        return &matrix[col][row];
    }
    else {
        if ((int)matrix[col][row - 1] % 48 < 10) {
            return LeftNeighbour(matrix, col, row - 1) + &matrix[col][row];
        }
        else {
            return &matrix[col][row];
        }
    }


}

string RightNeighbour(vector<vector<char>> matrix, int col, int row) {
    if (row == matrix[col].size() - 1) {
        return &matrix[col][row];
    }
    else {
        if ((int)matrix[col][row + 1] % 48 < 10) {
            return &matrix[col][row] + RightNeighbour(matrix, col, row + 1);
        }
        else {
            return &matrix[col][row];
        }
    }


}

for (int row = 0; row < input[column].size(); row++) {

            // if the given char is a symbol
            if ((int)matrix[column][row] % 33 < 15 && (int)matrix[column][row] % 33 !=13) {

                // go through the adjacent characters to find if any of them is a number between 0 and 9;
                for (int i = column - 1; i <= column + 1; i++) {
                    string number = "";
                    for (int j = row - 1; j <= row + 1; j++) {

                        char temp = matrix[i][j];

                        if ((int)temp % 48 < 10) {
                            if (j < row) {
                                number += LeftNeighbour(matrix, i, j);
                            }
                            else if (row < j) {
                                number += RightNeighbour(matrix, i, j);
                            }
                            else {
                                number += temp;
                            }
                        }
                        else if ((int)temp % 46 == 0) {
                            answers.push_back(number);
                            number = "";
                        }


                    }
                    //cout << number << endl;
                    //cout << endl;
                }
                //cout << endl;

            }

            //cout << matrix[column][row] << " ";
        }



*/