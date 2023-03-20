#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class VendingMachine {

private:
    int code{};
    double currentBalance{};
    double money{};
    std::string userInput{};

public:
    void menu() {
        items();
        deposit();
        std::cout << "\nCurrent Balance: " << "$" << balance(currentBalance) << std::endl;
        std::cout << "Insert more cash? (Yes || No): ";
        std::cin >> userInput;
        while (userInput == "yes" || userInput == "Yes") {
            deposit();
            std::cout << "\nCurrent Balance: " << "$" << balance(currentBalance) << std::endl;
            if (balance(currentBalance) >= 5.00) {
                std::cout << "Limit Reached." << std::endl;
                break;
            } else {
                std::cout << "Insert Cash? (Yes || No): ";
                std::cin >> userInput;
            }
        }
        std::cout << "\nEnter Code: ";
        std::cin >> code;
        getItem(code);
    }

private:
    // Starting Function
    void deposit() {
        double cash;
        std::cout << "\n\nInsert Cash (Accepts $1 and $5): ";
        std::cin >> cash;
        if (cash == 1.00) {
            currentBalance++;
        } else {
            printf("%s", "Invalid Currency.");
        }
    }

    // Users current balance
    double balance(double userMoney) {
        return money + userMoney;
    }

    // the current list of items
    static void items() {
        printf("%s", "Starburst - $1.25 (001)"
                     "\nSkittles - $1.25 (002)"
                     "\nTrolli Sour Octopuses - $1.50 (003)"
                     "\nWelch's Fruit Snacks - $1.50 (004)"
                     "\nGatorade - $1.75 (005)");
    }

    static void getItem(int numbCode) {
        int userCode = numbCode;
        std::string snacks[6] = {"Starburst", "Skittles", "Welch Berry Gummy",
                                 "Trolli Sour Octopuses", "Hot Cheetos", "Gatorade"};

        if (userCode == 001) {
            printf("%s", "Processing Order...");
            sleep();
            std::cout << "\nItem Chosen:" << " " << snacks[0] << std::endl;
        }
    }

    // Delays execution.
    static void sleep() {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
    }
};

// Driver Code
int main() {
    VendingMachine vendingMachine;
    vendingMachine.menu();

    return 0;
}
