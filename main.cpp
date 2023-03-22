#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class VendingMachine {

private:
    int code{0};
    double currentBalance{0.0}, money{0.0};
    std::string userInput{};

public:
    void menu() {
        items();
        for (int i = 0; i < 2; i++) {
            deposit();
            std::cout << "\nCurrent Balance: " << "$" << balance(currentBalance) << '\n';
        }
        std::cout << "\nInsert more cash? (Yes || No): ";
        std::cin >> userInput;
        while (userInput == "yes" || userInput == "Yes") {
            deposit();
            std::cout << "\nCurrent Balance: " << "$" << balance(currentBalance) << '\n';
            if (balance(currentBalance) == 5.00) {
                printf("\n%s", "Limit Reached");
                break;
            } else {
                std::cout << "\nInsert Cash? (Yes || No): ";
                std::cin >> userInput;
            }
        }
        std::cout << "\n\nEnter Code: ";
        std::cin >> code;
        getItem(code);
    }

private:
    // Starting Function
    void deposit() {
        double cash;
        std::cout << "\nInsert Cash (Accepts $1 and $5): ";
        std::cin >> cash;
        isCurrency(cash);
        if (cash == 1.00) {
            currentBalance++;
        } else {
            printf("\n%s", "Invalid Currency.");
        }
    }

    // Users current balance
    [[nodiscard]] double balance(double userMoney) const {
        return money + userMoney;
    }

    // The list of items
    static void items() {
        printf("%s", "Starburst - $1.25 (100)"
                     "\nSkittles - $1.25 (101)"
                     "\nWelch's Fruit Snacks - $1.50 (102)"
                     "\nTrolli Sour Octopuses - $1.50 (103)"
                     "\nHot Cheetos - $1.50 (104)"
                     "\nGatorade - $1.75 (105)"
                     "\n");
    }

    // Retrieves the item from the vending machine
    static void getItem(int numbCode) {
        int userCode = numbCode;
        std::string snacks[6] = {"Starburst", "Skittles", "Welch Berry Gummy",
                                 "Trolli Sour Octopuses", "Hot Cheetos", "Gatorade"};

        if (userCode == 100) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[0] << '\n'; // Starburst
        } else if (userCode == 101) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[1] << '\n'; // Skittles
        } else if (userCode == 102) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[2] << '\n'; // Welch's
        } else if (userCode == 103) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[3] << '\n'; // Trolli
        } else if (userCode == 104) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[4] << '\n'; // Hot Cheetos
        } else if (userCode == 105) {
            processOrder();
            std::cout << "\nChosen item:" << " " << snacks[5] << '\n'; // Gatorade
        }
    }

    // Delays execution.
    static void sleep() {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
    }

    static void processOrder() {
        printf("\n%s", "Processing Order...");
        sleep();
        printf("%s", "Transaction Complete!");
        sleep();
    }

    // (WORK-IN-PROGRESS) //
    static bool isCurrency(double cash) {
        double currency{};
        if (cash < currency) {
            return "\ninvalid currency";
        }
        return false;
    }
};

// Driver Code
int main() {
    VendingMachine vendingMachine;
    vendingMachine.menu();

    return 0;
}
