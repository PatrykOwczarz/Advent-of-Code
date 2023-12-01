// Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>

using namespace std;

vector<string> stringInput;

vector<int> x_1;
vector<int> y_1;
vector<int> x_2;
vector<int> y_2;

const int sizeMaze = 991;
int maze[sizeMaze][sizeMaze];

int maxX = 0, maxY = 0;

int finalCount;

// reference to learning https://www.youtube.com/watch?v=A9aNn6q-P6Y
void readInput() {
    
    ifstream inputFileStream;
    inputFileStream.open("input.txt");

    if (!inputFileStream.is_open()) {
        cout << "File doesn't exist!";
    }

    while(inputFileStream) {
        string line;
        getline(inputFileStream, line);

        istringstream lineStream(line);

        string arrow;

        string tempX1;
        string tempY1;
        string tempX2;
        string tempY2;

        getline(lineStream, tempX1, ',');
        getline(lineStream, tempY1, ' ');
        getline(lineStream, arrow, ' ');
        getline(lineStream, tempX2, ',');
        getline(lineStream, tempY2, ',');

        if (!inputFileStream) {
            break;
        }

        x_1.push_back(atoi(tempX1.c_str()));
        y_1.push_back(atoi(tempY1.c_str()));
        x_2.push_back(atoi(tempX2.c_str()));
        y_2.push_back(atoi(tempY2.c_str()));

        if (atoi(tempX1.c_str()) > maxX) {
            maxX = atoi(tempX1.c_str());
        }
        else if (atoi(tempX2.c_str()) > maxX) {
            maxX = atoi(tempX2.c_str());
        }
        else if (atoi(tempY1.c_str()) > maxY) {
            maxY = atoi(tempY1.c_str());
        }
        else if (atoi(tempY2.c_str()) > maxY) {
            maxY = atoi(tempY2.c_str());
        }

        cout << "(" << tempX1 << "," << tempY1 << ") to (" << tempX2 << "," << tempY2 << ") \n";
    }
    cout << "\nMax X = " << maxX << " Max Y = " << maxY << "\n\n";
}

void printMaze() {
    for (int i = 0; i < sizeMaze; i++) {
        for (int j = 0; j < sizeMaze; j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void populateMaze() {

    for (int i = 0; i < sizeMaze; i++) {
        for (int j = 0; j < sizeMaze; j++) {
            maze[i][j] = 0;
        }
    }
}

void solvePart1() {
    readInput();
    populateMaze();

    for (int i = 0; i < x_1.size(); i++) {

        if (x_1.at(i) == x_2.at(i)) {
            int num_to_move;
            if (y_1.at(i) < y_2.at(i)) {

                num_to_move = (y_2.at(i) - y_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) + moves][x_1.at(i)] += 1;
                }
            }
            else if (y_1.at(i) > y_2.at(i)){
                num_to_move = (y_1.at(i) - y_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_2.at(i) + moves][x_1.at(i)] += 1;
                }
            }
        }

        else if (y_1.at(i) == y_2.at(i)) {
            int num_to_move;
            if (x_1.at(i) < x_2.at(i)) {

                num_to_move = (x_2.at(i) - x_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i)][x_1.at(i) + moves] += 1;
                }
            }
            else if(x_1.at(i) > x_2.at(i)){
                num_to_move = (x_1.at(i) - x_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i)][x_2.at(i) + moves] += 1;
                }
            }
        }
        
    }


    //printMaze();

    for (int i = 0; i < sizeMaze; i++) {
        for (int j = 0; j < sizeMaze; j++) {
            if (maze[i][j] >= 2) {
                finalCount += 1;
            }
        }
    }

    cout << "Atleast 2 lines overlap at: " << finalCount << " points\n";
}


void solvePart2() {
    readInput();
    populateMaze();

    for (int i = 0; i < x_1.size(); i++) {

        int differenceX = x_1.at(i) - x_2.at(i);
        int differenceY = y_1.at(i) - y_2.at(i);


        if (x_1.at(i) == x_2.at(i)) {
            int num_to_move;
            if (y_1.at(i) < y_2.at(i)) {

                num_to_move = (y_2.at(i) - y_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) + moves][x_1.at(i)] += 1;
                }
            }
            else if (y_1.at(i) > y_2.at(i)) {
                num_to_move = (y_1.at(i) - y_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_2.at(i) + moves][x_1.at(i)] += 1;
                }
            }
        }

        else if (y_1.at(i) == y_2.at(i)) {
            int num_to_move;
            if (x_1.at(i) < x_2.at(i)) {

                num_to_move = (x_2.at(i) - x_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i)][x_1.at(i) + moves] += 1;
                }
            }
            else if (x_1.at(i) > x_2.at(i)) {
                num_to_move = (x_1.at(i) - x_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i)][x_2.at(i) + moves] += 1;
                }
            }
        }

        else if (differenceX == differenceY) {
            int num_to_move;

            if (x_1.at(i) < x_2.at(i)) {

                num_to_move = (x_2.at(i) - x_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) + moves][x_1.at(i) + moves] += 1;
                }
            }
            else if (x_1.at(i) > x_2.at(i)) {
                num_to_move = (x_1.at(i) - x_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) - moves][x_1.at(i) - moves] += 1;
                }
            }
        }

        else if (differenceX = -differenceY) {
            int num_to_move;

            if (x_1.at(i) < x_2.at(i)) {

                num_to_move = (x_2.at(i) - x_1.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) - moves][x_1.at(i) + moves] += 1;
                }
            }
            else if (x_1.at(i) > x_2.at(i)) {
                num_to_move = (x_1.at(i) - x_2.at(i));
                //cout << "moves: " << num_to_move << "\n";
                for (int moves = 0; moves <= num_to_move; moves++) {
                    maze[y_1.at(i) + moves][x_1.at(i) - moves] += 1;
                }
            }
        }
    }


    //printMaze();

    for (int i = 0; i < sizeMaze; i++) {
        for (int j = 0; j < sizeMaze; j++) {
            if (maze[i][j] >= 2) {
                finalCount += 1;
            }
        }
    }

    cout << "Atleast 2 lines overlap at: " << finalCount << " points\n";
}

int main()
{
    solvePart2();
    
}
