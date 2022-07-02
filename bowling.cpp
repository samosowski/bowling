//Samantha Osowski 
//Week 6 Programming Assignment
//In this program we will calculate a bowling league's average bowling score.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

//defining the number of bowlers 
#define NumPlayers 10

//getting the data from the file and ending if failed to open file
bool GetBowlingData(char names[][100], int scores[][4], int& n) {
    ifstream infile;
    infile.open("BowlingScore.txt");
    if (infile.is_open()) {
        while (infile.is_open()) {
            infile >> names[n] >> scores[n][1] >> scores[n][2] >> scores[n][3];
            n++;
        }
        return true;
    }
    return false;
}
//getting the average score of all players
void GetAverageScore(int scores[][4], double avgScore[], int n) {
    for (int i = 0; i < n; i++) {
        avgScore[i] = 0;
        for (int j = 0; j < 4; j++) {
            avgScore[i] += scores[i][j];
        }
        avgScore[i] /= 4.0;
    }
}
//displaying the results in an array
void PrettyPrintResults(char names[][100], int scores[][4], double avgScore[], int n) {
    cout << left << setw(15) << "Name" << "Score 1\t Score 2\t Score 3\t Score 4\t Average Score" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << names[i] << "\t";
        for (int j = 0; j < 4; j++)
            cout << scores[i][j] << "\t";
        cout << avgScore[i] << endl;

    }
}
int main() {
    //declaring the variables
    char names[NumPlayers][100];
    int scores[NumPlayers][4];
    double avgScore[NumPlayers];
    int n = 0;
    //running the program
    if (GetBowlingData(names, scores, n)) {
        GetAverageScore(scores, avgScore, n);
        PrettyPrintResults(names, scores, avgScore, n);
    }
    return 0;
}

