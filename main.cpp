#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class VendingMachine {

    string snacks[7] = {"Starburst", "Skittles", "Takis", "Welch Berry Gummy",
                         "Trolli Sour Worms", "Hot Cheetos", "Water"};

public:
    double currentBalance;
    double money;

    void menu() {

        string userContinue;
        cout << "Starburst - (001)" << " ||" << " Skittles - (002)" << " ||" << " Takis - (003)"
             << " ||" << " Welch Berry Gummy - (004)" << " ||" << " Trolli Sour Worms - (005)" << endl;
        deposit();
        cout << "Current Balance: " << "$" << balance(currentBalance) << endl;
        cout << "Insert more cash? (Yes || No): ";
        cin >> userContinue;
        while(userContinue == "yes" || userContinue == "Yes") {
            deposit();
            cout << "Current Balance: " << "$" << balance(currentBalance) << endl;
            if (balance(currentBalance) >= 5.00) {
                cout << "Limit Reached." << endl;
                break;
            } else {
                cout << "Insert Cash? (Yes || No): ";
                cin >> userContinue;
            }
        }
        cout << "\nEnter Selection Code: " << endl;
    }

    // Starting Function
    void deposit() {
        double cash;
        cout << "Insert Cash ($1.25): ";
        cin >> cash;
        if (cash >= 5.00) {
            cout << "Limit Reached." << endl;
        }
        currentBalance = currentBalance + cash;
    }

    // Users Current Balance
    double balance(double userMoney) {
        return money + userMoney;
    }
};

// Driver Code
int main() {
    VendingMachine vendingMachine;
    vendingMachine.menu();

    return 0;
}
