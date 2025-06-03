#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "data.h"

using namespace std;


void createBinaryFile(const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error while opening file to write data." << endl;
        return;
    }

    for (const auto& student : students) {
        outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    outFile.close();
}

void viewBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error while opening file to read data." << endl;
        return;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Full name: " << student.name << ", Age: " << student.age
            << ", Gender: " << student.gender << ", Course: " << student.course
            << ", Grade: " << student.performance << endl;
    }

    inFile.close();
}

char getFirstNameLetter(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == ' ')
            return name[i+1];
    }
}

void studentsOfCourseAndByName(const string& inputFile, const string& outputFile, int course, char letter) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Error while opening file to read data." << endl;
        return;
    }
    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Error while opening file to write data." << endl;
        return;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.course == course && getFirstNameLetter(student.name) == letter) {
            outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    string filename = "students.bin";
    string outputFilename = "filtered_students.bin";

    createBinaryFile(filename);

    cout << "Inside the created file:" << endl;
    viewBinaryFile(filename);

    int course;
    char letter;

    cout << "Input course number: ";
    cin >> course;
    cout << "Input the first letter of the name (for ex. 'A'): ";
    cin >> letter;

    studentsOfCourseAndByName(filename, outputFilename, course, letter);

    cout << "Result file created: " << outputFilename << endl;
    viewBinaryFile(outputFilename);
    return 0;
}