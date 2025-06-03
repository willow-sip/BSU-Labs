#include "RationalFraction.h"

int main()
{
    enum class Operation { Add = 1, Subtract, Multiply, Divide, Reduct, Compare, Exit };

    RationalFraction fract1;
    RationalFraction fract2;
    int operationChoice = 0;

    
    while (true) {
        system("cls");
        cout << "Input fraction 1 (in format m/n): ";
        cin >> fract1;
        cout << "Input fraction 2 (in format m/n): ";
        cin >> fract2;

        cout << "Choose an operation:\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Reduce\n6. Compare\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> operationChoice;

        Operation op = static_cast<Operation>(operationChoice);

        switch (op) {
        case Operation::Add: {
            cout << fract1 << " + " << fract2 << " = " << fract1 + fract2 << endl;
            break;
        }
        case Operation::Subtract: {
            cout << fract1 << " - " << fract2 << " = " << fract1 - fract2 << endl;
            break;
        }
        case Operation::Multiply: {
            cout << fract1 << " * " << fract2 << " = " << fract1 * fract2 << endl;
            break;
        }
        case Operation::Divide: {
            cout << fract1 << " : " << fract2 << " = " << fract1 / fract2 << endl;
            break;
        }
        case Operation::Reduct: {
            cout << fract1 << " -> " << fract1.reduct() << endl;
            cout << fract2 << " -> " << fract2.reduct() << endl;
            break;
        }
        case Operation::Compare: {
            char comparisonResult = fract1.comp(fract2);
            switch (comparisonResult) {
            case 'e':
                cout << fract1 << " = " << fract2 << endl;
                break;
            case 'b':
                cout << fract1 << " > " << fract2 << endl;
                break;
            case 's':
                cout << fract1 << " < " << fract2 << endl;
                break;
            default:
                break;
            }
            break;
        }
        case Operation::Exit: {
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Wish to do something else? (1 for yes, 0 for no): ";
        bool continueChoice;
        cin >> continueChoice;
        if (!continueChoice) {
            cout << "Exiting the calculator." << endl;
            return 0;
        }

    }

    return 0;
}
