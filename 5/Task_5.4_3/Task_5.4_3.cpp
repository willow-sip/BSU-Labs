#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


int whichOperator(string& op) {
    if (op == "&&") return 1;
    if (op == "||") return 0;
    return -1;
}

bool useOperator(bool left, bool right, string& op) {
    if (op == "&&") return left && right;
    if (op == "||") return left || right;
    return false;
}

bool numComp(int left, int right, string& op) {
    if (op == "<") return left < right;
    if (op == ">") return left > right;
    if (op == "==") return left == right;
    if (op == "!=") return left != right;
    if (op == "<=") return left <= right;
    if (op == ">=") return left >= right;
    return false;
}

bool evaluate(vector<int>& values, vector<string>& ops) {
    vector<bool> boolValues;

    for (size_t i = 0; i < values.size(); i++) {
        boolValues.push_back(static_cast<bool>(values[i]));
    }

    for (size_t i = 0; i < ops.size(); i++) {
        if (ops[i] == "&&" || ops[i] == "||") {
            bool left = boolValues[i];
            bool right = boolValues[i + 1];
            bool result = useOperator(left, right, ops[i]);
            boolValues[i] = result;
            boolValues.erase(boolValues.begin() + i + 1);
            ops.erase(ops.begin() + i);
            i--;
        }
    }

    return boolValues[0];
}

bool evaluateExpression(string& expression) {
    vector<int> values;
    vector<string> ops;
    string token;
    size_t i = 0;

    while (i < expression.length()) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }


        if (isdigit(expression[i]) || (expression[i] == '-' || expression[i] == '+')) {
            size_t start = i;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '-' || expression[i] == '+')) {
                i++;
            }
            values.push_back(stoi(expression.substr(start, i - start)));
        }
        else if (expression[i] == 'T') {
            values.push_back(1);
            i++;
        }
        else if (expression[i] == 'F') {
            values.push_back(0);
            i++;
        }
        else if (expression[i] == '(') {
            ops.push_back("(");
            i++;
        }
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.back() != "(") {
                string op = ops.back();
                ops.pop_back();
                int right = values.back(); values.pop_back();
                int left = values.back(); values.pop_back();
                values.push_back(numComp(left, right, op));
            }
            ops.pop_back();
            i++;
        }
        else {
            size_t start = i;
            while (i < expression.length() && !isspace(expression[i]) && expression[i] != '(' && expression[i] != ')') {
                i++;
            }
            string op = expression.substr(start, i - start);
            while (!ops.empty() && whichOperator(ops.back()) >= whichOperator(op)) {
                string topOp = ops.back();
                ops.pop_back();
                int right = values.back(); values.pop_back();
                int left = values.back(); values.pop_back();
                values.push_back(numComp(left, right, topOp));
            }
            ops.push_back(op);
        }
    }

    while (!ops.empty()) {
        string op = ops.back();
        ops.pop_back();
        int right = values.back(); values.pop_back();
        int left = values.back(); values.pop_back();
        values.push_back(numComp(left, right, op));
    }

    return values.back() != 0;
}

int main() {
    string expression = "3 >= 2 && 1 || 0";
    cout << expression << endl << "Result: " << (evaluateExpression(expression) ? "true" : "false") << endl;
    return 0;
}