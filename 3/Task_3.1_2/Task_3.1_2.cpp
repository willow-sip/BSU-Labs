#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 64 * 1024;

void processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return;
    }

    int positiveNumbers[MAX_SIZE];
    int negativeNumbers[MAX_SIZE];
    int posCount = 0, negCount = 0;

    int number;
    while (inFile >> number) {
        if (number >= 0) {
            if (posCount < MAX_SIZE) {
                positiveNumbers[posCount++] = number;
            }
        }
        else {
            if (negCount < MAX_SIZE) {
                negativeNumbers[negCount++] = number;
            }
        }
    }

    for (int i = 0; i < posCount; ++i) {
        outFile << positiveNumbers[i] << " ";
    }

    for (int i = 0; i < negCount; ++i) {
        outFile << negativeNumbers[i] << " ";
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "f.txt";  
    string outputFile = "g.txt";  

    processFile(inputFile, outputFile);

    cout << "Check the output file: " << outputFile << endl;

    return 0;
}