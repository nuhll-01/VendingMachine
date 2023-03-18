// Test Commit
#include <iostream>
#include <cmath>
#include <string>

class VendingMachine {

    std::string snacks[7] = {"Starburst", "Skittles", "Takis", "Welch Berry Gummy",
                         "Trolli Sour Worms", "Hot Cheetos", "Water"};

public:
    double currentBalance;
    double money;

    void menu() {

        std::string userContinue;
        std::cout << "Starburst - (001)" << " ||" << " Skittles - (002)" << " ||" << " Takis - (003)"
             << " ||" << " Welch Berry Gummy - (004)" << " ||" << " Trolli Sour Worms - (005)" << std::endl;
        deposit();
        std::cout << "Current Balance: " << "$" << balance(currentBalance) << std::endl;
        std::cout << "Insert more cash? (Yes || No): ";
        std::cin >> userContinue;
        while(userContinue == "yes" || userContinue == "Yes") {
            deposit();
            std::cout << "Current Balance: " << "$" << balance(currentBalance) << std::endl;
            if (balance(currentBalance) >= 5.00) {
                std::cout << "Limit Reached." << std::endl;
                break;
            } else {
                std::cout << "Insert Cash? (Yes || No): ";
                std::cin >> userContinue;
            }
        }
        std::cout << "\nEnter Selection Code: " << std::endl;
    }

    // Starting Function
    void deposit() {
        double cash;
        std::cout << "Insert Cash ($1.25): ";
        std::cin >> cash;
        if (cash >= 5.00) {
            std::cout << "Limit Reached." << std::endl;
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
