// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

vector<string> stringInput;

int heightmap[100][100];

vector<int> lowPoints;
vector<pair<int,int>> lowPointCoords;

int currentBasinSize;
vector<int> basinSizes;

void convertToInt() {
    for (int i = 0; i < stringInput.size(); i++) {
        
        for (int j = 0; j < stringInput.at(i).length(); j++) {
            heightmap[i][j] = atoi(stringInput.at(i).substr(j, 1).c_str());
        }  
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
            stringInput.push_back(tp);
        }
        inputFile.close();
    };

    convertToInt();
}

void findLowPoints() {
    for (int i = 0; i < stringInput.size(); i++) {

        for (int j = 0; j < stringInput.at(i).length(); j++) {
            int thisValue = heightmap[i][j];
            if (i == 0 && j == 0) {
                if (heightmap[i][j + 1] > thisValue && heightmap[i + 1][j] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i,j));
                }
            }
            else if (i == (stringInput.size() - 1) && j == 0) {
                if (heightmap[i][j + 1] > thisValue && heightmap[i - 1][j] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (i == 0 && j == (stringInput.at(i).length() - 1)) {
                if (heightmap[i][j - 1] > thisValue && heightmap[i + 1][j] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (i == (stringInput.size() - 1) && j == (stringInput.at(i).length() - 1)) {
                if (heightmap[i][j - 1] > thisValue && heightmap[i - 1][j] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (i == (stringInput.size() - 1)) {
                if (heightmap[i - 1][j] > thisValue && heightmap[i][j + 1] > thisValue && heightmap[i][j - 1] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (j == (stringInput.at(i).length() - 1)) {
                if (heightmap[i + 1][j] > thisValue && heightmap[i - 1][j] > thisValue && heightmap[i][j - 1] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (j == 0) {
                if (heightmap[i + 1][j] > thisValue && heightmap[i - 1][j] > thisValue && heightmap[i][j + 1] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else if (i == 0) {
                if (heightmap[i + 1][j] > thisValue && heightmap[i][j + 1] > thisValue && heightmap[i][j - 1] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }
            else {
                if (heightmap[i][j + 1] > thisValue && heightmap[i + 1][j] > thisValue && heightmap[i - 1][j] > thisValue && heightmap[i][j - 1] > thisValue) {
                    cout << "i: " << i << " j: " << j << " val: " << thisValue << "\n";
                    lowPoints.push_back(thisValue);
                    lowPointCoords.push_back(make_pair(i, j));
                }
            }

        }

    }
}

// finds all the possible neighbors.
vector<pair<int, int>> findNeighbours(pair<int,int> current) {
    vector<pair<int, int>> neighbors;

    if (current.first != 0) {
        neighbors.push_back(make_pair(current.first - 1, current.second));
    }
    if (current.first != (stringInput.size() - 1)) {
        neighbors.push_back(make_pair(current.first + 1, current.second));
    }
    if (current.second != 0) {
        neighbors.push_back(make_pair(current.first, current.second - 1));
    }
    if (current.second != (stringInput.at(0).length() - 1)) {
        neighbors.push_back(make_pair(current.first, current.second + 1));
    }

    return neighbors;
}

// BFS flood fill algorithm to find the basin size.
void floodFill(pair<int,int> start) {
    queue<pair<int, int>> frontier;
    map<pair<int, int>, bool> reached;

    pair<int, int> current;
    currentBasinSize = 0;

    vector< pair<int, int>> neighbors;

    frontier.push(start);
    reached[start] = true;

    while (!frontier.empty()) {
        current = frontier.front();
        neighbors = findNeighbours(current);

        for (int i = 0; i < neighbors.size(); i++) {
            if (heightmap[neighbors.at(i).first][neighbors.at(i).second] < 9 && !reached[neighbors.at(i)]) {
                frontier.push(neighbors.at(i));
                reached[neighbors.at(i)] = true;
            }
        }

        frontier.pop();
        currentBasinSize += 1;
    }
    basinSizes.push_back(currentBasinSize);

}

// performs the BFS flood fill algorithm and finds the size of each basin for each low point
void findBasins() {
    for (int i = 0; i < lowPointCoords.size(); i++) {
        floodFill(lowPointCoords.at(i));
    }
}

void solvePart1() {
    readInput();
    findLowPoints();
    
    int sum = 0;

    for (int i = 0; i < lowPoints.size(); i++) {
        sum += lowPoints.at(i) + 1;
    }

    for (int i = 0; i < lowPointCoords.size(); i++) {
        cout << "LowPointCoords at " << i << ": [" << lowPointCoords.at(i).first << ", " << lowPointCoords.at(i).second << "] \n";
    }
    cout << "The sum of the risk levels of all low points is: " << sum << "\n";
}

void solvePart2() {
    readInput();
    findLowPoints();
    findBasins();
    sort(basinSizes.begin(), basinSizes.end(), greater<int>());
    
    int sum = 0;

    sum += basinSizes.at(0) * basinSizes.at(1) * basinSizes.at(2);

    cout << "The multiplied total of the three largest basins is: " << sum << "\n";
}

int main()
{
    //solvePart1();
    solvePart2();
}
