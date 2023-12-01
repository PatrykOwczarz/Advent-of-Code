// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// example input:
vector<int> input{ 3,4,3,1,2 };
vector<uint64_t> fishes{ 0,0,0,0,0,0,0,0,0 };

/* my individual test input:
vector<int> input { 4,1,1,1,5,1,3,1,5,3,4,3,3,1,3,3,1,5,3,2,4,4,3,4,1,4,2,2,1,3,5,1,1,3,2,5,1,1,4,2,5,4,
3,2,5,3,3,4,5,4,3,5,4,2,5,5,2,2,2,3,5,5,4,2,1,1,5,1,4,3,2,2,1,2,1,5,3,3,3,5,1,5,4,2,2,2,1,4,2,5,2,3,3,2,3,4,
4,1,4,4,3,1,1,1,1,1,4,4,5,4,2,5,1,5,4,4,5,2,3,5,4,1,4,5,2,1,1,2,5,4,5,5,1,1,1,1,1,4,5,3,1,3,4,3,3,1,5,4,2,1,
4,4,4,1,1,3,1,3,5,3,1,4,5,3,5,1,1,2,2,4,4,1,4,1,3,1,1,3,1,3,3,5,4,2,1,1,2,1,2,3,3,5,4,1,1,2,1,2,5,3,1,5,4,3,
1,5,2,3,4,4,3,1,1,1,2,1,1,2,1,5,4,2,2,1,4,3,1,1,1,1,3,1,5,2,4,1,3,2,3,4,3,4,2,1,2,1,2,4,2,1,5,2,2,5,5,1,1,2,
3,1,1,1,3,5,1,3,5,1,3,3,2,4,5,5,3,1,4,1,5,2,4,5,5,5,2,4,2,2,5,2,4,1,3,2,1,1,4,4,1,5};
*/

uint64_t sum = 0;

void solvePart1() {

    cout << "Initial state: ";
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ",";
    }
    cout << "\n";
    
    for (int day = 1; day < 81; day++) {
        if (day == 1) {
            cout << "After  1 day:  ";
        }
        else if (day < 10) {
            cout << "After  " << day << " days: ";
        }
        else if(day < 21){
            cout << "After " << day << " days: ";
        }
        
        for (int i = 0; i < input.size(); i++) {
            if (input.at(i) == 0) {
                input.at(i) = 6;
                input.push_back(9);
            }
            else if (input.at(i) > 0) {
                input.at(i) -= 1;
            }
            if (day < 21) {
                cout << input.at(i) << ",";
            }
            
        }
        if (day < 21) {
            cout << "\n";
        }
    }
    cout << "\n" << "The amount of lanternfish after 80 days is: " << input.size() << "\n";
}

// some inspiration from the reddit and this: https://www.reddit.com/r/adventofcode/comments/r9z49j/2021_day_6_solutions/hnff05z/?utm_source=reddit&utm_medium=web2x&context=3
void solvePart2() {
    for (int i = 0; i < input.size(); i++) {
        fishes.at(input.at(i)) += 1;
    }

    for (int days = 0; days < 80; days++) {
        uint64_t babies = fishes[0];
        for (int i = 1; i < 9; i++) {
            fishes.at(i - 1) = fishes.at(i);
        }
        fishes[6] += babies;
        fishes[8] = babies;
    }
    
    for (int i = 0; i < fishes.size(); i++) {
        sum += fishes.at(i);
    }

    cout << "\n" << "The amount of lanternfish after 256 days is: " << sum << "\n";
}

int main()
{
    //solvePart1();
    solvePart2();
}

