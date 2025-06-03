#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//4.1
string deleteSymbols(string str) {
    int len = str.length();
    int* countReps = new int[len]();

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (j != i && str[i] == str[j]) {
                countReps[i]++;
            }
        }
    }
    string result;
    for (int i = 0; i < len; i++) {
        if (countReps[i] > 0) {
            result += str[i];
        }
    }

    delete[] countReps;
    return result;
}

//4.2
double binFloatToDecimal(string binary) {
    int pointPos = binary.find('.');
    double decimalValue = 0.0;

    if (pointPos != string::npos) {
        string integerPart = binary.substr(0, pointPos);
        for (int i = 0; i < integerPart.length(); ++i) {
            if (integerPart[integerPart.length() - 1 - i] == '1') {
                decimalValue += pow(2, i);
            }
        }
        string fractionalPart = binary.substr(pointPos + 1);
        for (int i = 0; i < fractionalPart.length(); ++i) {
            if (fractionalPart[i] == '1') {
                decimalValue += pow(2, (-i - 1));
            }
        }
    }
    else {
        for (int i = 0; i < binary.length(); ++i) {
            if (binary[binary.length() - 1 - i] == '1') {
                decimalValue += pow(2, i);
            }
        }
    }

    return decimalValue;
}

//4.3

bool isSymmetric(string word) {
    int len = word.length();
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

string getNonSymWords(string text) {
    string result;
    string word;
    int len = text.length();

    for (int i = 0; i < len; i++) {
        if (text[i] != ' ' && text[i] != '.' && text[i] != ',') {
            word += text[i];
        }
        else {
            if (!word.empty()) {
                if (word.length() % 2 == 0 && !isSymmetric(word)) {
                    result += word + " ";
                }
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        if (word.length() % 2 == 0 && !isSymmetric(word)) {
            result += word + "\n";
        }
    }

    return result;
}

int main()
{
    string test1 = "hello world";
    cout << "String before shanges: " << test1 << "\nString after changes: " << deleteSymbols(test1) << endl;

    string test2 = "0.1011";
    cout << "\nBinary number: " << test2 << "\nDecimal number: " << binFloatToDecimal(test2) << endl;

    string test3 = "The quick brown fox jumps over the lazy dog. Some words like noon, level, and racecar are symmetric. However, apple, banana, and orange are not symmetric.";
    cout << "\nText before: " << test3 << "\nText after: " << getNonSymWords(test3) << endl;
}