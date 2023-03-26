#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class VendingMachine {

public:
    int commandInput = {0};
    double balance = {0.0}, money = {0.0}, cash = {0.0};

public:
    void menu() {
        items();
        for (int i = 0; i < 2; i++) {
            deposit();
            getBalance();
        }
        std::cout << "\nCheckout? (1 --> Yes | 2 --> No): ";
        std::cin >> commandInput;
        switch (commandInput) {
            case 1:
                enterCode();
                break;
            case 2:
                while(commandInput == 2) {
                    deposit();
                    getBalance();
                    std::cout << "\nCheckout? (1 --> Yes | 2 --> No): ";
                    std::cin >> commandInput;
                    if (commandInput == 1) {
                        enterCode();
                    } else if (UserBalance(balance) == 5.00) {
                        printf("\n%s", "Limit Reached");
                        enterCode();
                    }
                }
                break;
            default:
                printf("\n%s", "Error, please try again.");
        }


        // while (commandInput == "yes" || commandInput == "Yes") {
        //     deposit();
        //     std::cout << "\nCurrent Balance: " << "$" << UserBalance(balance) << '\n';
        //     if (UserBalance(balance) == 5.00) {
        //         printf("\n%s", "Limit Reached");
        //         break;
        //     } else {
        //         std::cout << "\nInsert Cash? (Yes || No): ";
        //         std::cin >> userInput;
        //     }
        // }

    }

private:
    // The list of items
    static void items() {
        printf("%s", "Starburst - $1.25 (100)"
                     "\nSkittles - $1.25 (101)"
                     "\nWelch's Fruit Snacks - $1.50 (102)"
                     "\nTrolli Sour Octopuses - $1.50 (103)"
                     "\nHot Cheetos - $1.50 (104)"
                     "\nGatorade - $1.75 (105)"
                     "\n\n(Accepts $1 and $5)"
                     "\n");
    }

    // Starting Function
    void deposit() {
        std::cout << "\nInsert Cash: ";
        std::cin >> cash;
        checkBalance();
    }

    // Users current balance
    [[nodiscard]] double UserBalance(double userMoney) const {
        return money + userMoney;
    }

    // Returns current balance
    void getBalance() {
        std::cout << "\nBalance: " << "$" << UserBalance(balance) << '\n';
    }

    void checkBalance() {
        if (cash == 1.00) {
            balance = balance + 1;
        } else if (cash == 5.00) {
            balance = balance + 5;
            enterCode();
            exit(0);
        } else {
            printf("\n%s", "Invalid Input.");
            exit(0);
        }
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
        } else {
            std::cout << "\nInvalid Input" << "\n"; // if an invalid input is entered.
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
        printf("\n%s", "Transaction Complete!");
        sleep();
    }

public:
    static void enterCode() {
        int code = {0};
        std::cout << "\nEnter Code: ";
        std::cin >> code;
        getItem(code);
        exit(0);
    }
};

// Driver Code
int main() {
    VendingMachine vendingMachine;
    vendingMachine.menu();

    return 0;
}
