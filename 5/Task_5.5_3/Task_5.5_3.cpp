#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool isNumber(string& str) {
    bool hasDecimalPoint = false;
    for (char c : str) {
        if (c == '.') {
            if (hasDecimalPoint) return false; 
            hasDecimalPoint = true;
        }
        else if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void analyzeConstants(string& inputFile, string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;
    map<string, pair<int, vector<int>>> constantsMap; 

    int lineNumber = 0;

    while (getline(inFile, line)) {
        lineNumber++;
        string currentNumber;
        for (char c : line) {
            if (isdigit(c) || (c == '.' && !currentNumber.empty() && isNumber(currentNumber))) {
                currentNumber += c;
            }
            else {
                if (!currentNumber.empty() && isNumber(currentNumber)) {
                    constantsMap[currentNumber].first++;
                    constantsMap[currentNumber].second.push_back(lineNumber);
                    currentNumber.clear(); 
                }
            }
        }
        if (!currentNumber.empty() && isNumber(currentNumber)) {
            constantsMap[currentNumber].first++;
            constantsMap[currentNumber].second.push_back(lineNumber);
        }
    }

    for (auto& entry : constantsMap) {
        outFile << "Константа: " << entry.first << ", Количество: " << entry.second.first
            << ", Номера строк: ";
        for (auto& lineNum : entry.second.second) {
            outFile << lineNum << " ";
        }
        outFile << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input.cpp"; 
    string outputFile = "output.txt"; 

    analyzeConstants(inputFile, outputFile);

    cout << "Analysis complete. View results in " << outputFile << endl;
    return 0;
}