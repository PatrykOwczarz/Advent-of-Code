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
        return to_string(matrix[col][row]);
    }
    else {
        if (matrix[col][row - 1] % 48 < 10) {
            return LeftNeighbour(matrix, col, row - 1) + to_string(matrix[col][row]);
        }
        else {
            return to_string(matrix[col][row]);
        }
    }


}

string RightNeighbour(const vector<vector<char>>& matrix, int col, int row) {
    if (row == matrix[col].size() - 1) {
        return to_string(matrix[col][row]);
    }
    else {
        if (matrix[col][row + 1] % 48 < 10) {
            return to_string(matrix[col][row]) + RightNeighbour(matrix, col, row + 1);
        }
        else {
            return to_string(matrix[col][row]);
        }
    }


}


void SolveChallenge1() {

    vector<int> partNumbers;
    vector<vector<char>> matrix;

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
                            cout << number << endl;
                        }

                      
                    }
                    //cout << number << endl;
                    cout << endl;
                }
                //cout << endl;

            }

            //cout << matrix[column][row] << " ";
        }
       // cout << endl;
    }

    

}


int main() {

    readInput();
    SolveChallenge1();

    return 0;
}