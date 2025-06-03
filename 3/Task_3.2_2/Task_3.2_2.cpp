#include <iostream>
#include <fstream>

using namespace std;

void processBinaryFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return;
    }

    int ch;

    while (inFile.read(reinterpret_cast<char*>(&ch), sizeof(int))) {
        if (ch >= 0) {
            outFile.write(reinterpret_cast<char*>(&ch), sizeof(int));
        }
    }

    inFile.clear();
    inFile.seekg(0, ios::beg);

    while (inFile.read(reinterpret_cast<char*>(&ch), sizeof(int))) {
        if (ch < 0) {
            outFile.write(reinterpret_cast<char*>(&ch), sizeof(int));
        }
    }

    inFile.close();
    outFile.close();
}

void printFile(const string& filename) {
    ifstream infile(filename, ios::binary);
    if (!infile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    int v;
    while (infile.read(reinterpret_cast<char*>(&v), sizeof(int))) {
        cout << v << " ";
    }
    cout << endl;

    infile.close();
}

int main() {
    ofstream outFile("f.bin", ios::binary);
    int numbers[] = { 10, -5, 20, -15, 0, 30, -25 };
    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    outFile.close();

    string inputFile = "f.bin";
    string outputFile = "g.bin";

    cout << "Check the first file: " << inputFile << endl;
    printFile(inputFile);

    processBinaryFile(inputFile, outputFile);
    cout << "Check the output file: " << outputFile << endl;
    printFile(outputFile);

    return 0;
}
