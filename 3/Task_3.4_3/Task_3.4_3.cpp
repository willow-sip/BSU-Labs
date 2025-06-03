#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "data.h"

using namespace std;

void createTextFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error while opening file to write data." << endl;
        return;
    }

    for (int i = 0; i < sizeof(students)/sizeof(students[0]); ++i) {
        outFile << students[i].name << "," << students[i].age << "," << students[i].gender << ","
            << students[i].course << "," << students[i].performance << endl;
    }
    outFile.close();
}

void viewTextFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error while opening file to read data." << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}


void studentsOfCourseAndByName(const string& inputFile, const string& outputFile, int course, char letter) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error while opening file to read data." << endl;
        return;
    }
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error while opening file to write data." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos = 0;
        string token;
        string tokens[5];
        int index = 0;

        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        while ((pos = line.find(',')) != string::npos && index < 5) {
            token = line.substr(0, pos);
            tokens[index++] = token;
            line.erase(0, pos + 1);
        }

        if (!line.empty() && index < 5) {
            tokens[index++] = line;
        }

        if (index == 5) {
            string name = tokens[0];
            int studentCourse = stoi(tokens[3]);

            if (studentCourse == course && !name.empty() && name[0] == letter) {
                outFile << tokens[0] << ", " << tokens[1] << ", " << tokens[2] << ", "
                    << tokens[3] << ", " << tokens[4] << endl;
            }
        }
    }

    inFile.close();
    outFile.close();
}

int main() {

    string filename = "students.txt";
    string outputFilename = "filtered_students.txt";

    createTextFile(filename);

    cout << "Inside the created file:" << endl;
    viewTextFile(filename);

    int course;
    char letter;

    cout << "Input course number: ";
    cin >> course;
    cout << "Input the first letter of the name (for ex. 'A'): ";
    cin >> letter;

    studentsOfCourseAndByName(filename, outputFilename, course, letter);

    cout << "Result file created: " << outputFilename << endl;
    viewTextFile(outputFilename);
    return 0;
}