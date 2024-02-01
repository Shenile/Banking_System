#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class BankingSystem {
private:
    double accountBalance;
    double interestRate;
    std::vector<std::string> transactionHistory;

public:
    // Constructor
    BankingSystem() : accountBalance(0), interestRate(0.05) {}

    // Public Methods
    void startOperation() {
        int choice;
        double amount;

        while (true) {
            std::cout << "Select an operation:\n"
                      << "1. Deposit\n"
                      << "2. Withdraw\n"
                      << "3. Check Account Balance\n"
                      << "4. View Transaction History\n"
                      << "5. Cancel Operation\n"
                      << "Enter Your Choice: ";

            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter amount: ";
                    std::cin >> amount;
                    deposit(amount);
                    break;

                case 2:
                    std::cout << "Enter amount: ";
                    std::cin >> amount;
                    withdraw(amount);
                    break;

                case 3:
                    showBalance();
                    break;

                case 4:
                    viewTransactionHistory();
                    break;

                case 5:
                    cancel();
                    return;

                default:
                    std::cerr << "Invalid choice. Please enter a valid option.\n";
            }
        }
    }

private:
    // Private Methods
    void deposit(double amount) {
        accountBalance += amount;
        addToTransactionHistory("Deposit: +" + std::to_string(amount));
        applyInterest();
        std::cout << "Your money is deposited.\n";
    }

    void withdraw(double amount) {
        if (amount > accountBalance) {
            std::cerr << "Insufficient funds.\n";
            return;
        }

        accountBalance -= amount;
        addToTransactionHistory("Withdrawal: -" + std::to_string(amount));
        applyInterest();
        std::cout << "Withdrawal successful.\n";
    }

    void showBalance() {
        std::cout << "Your account balance is: $" << std::fixed << std::setprecision(2) << accountBalance << "\n";
    }

    void cancel() {
        std::cout << "Thank you for using our bank. Have a nice day!\n";
    }

    void viewTransactionHistory() {
        std::cout << "Transaction History:\n";
        for (const auto& transaction : transactionHistory) {
            std::cout << transaction << "\n";
        }
    }

    void applyInterest() {
        double interest = accountBalance * interestRate;
        accountBalance += interest;
        addToTransactionHistory("Interest Applied: +" + std::to_string(interest));
    }

    void addToTransactionHistory(const std::string& transaction) {
        transactionHistory.push_back(transaction);
    }
};

int main() {
    BankingSystem bankingSystem;
    bankingSystem.startOperation();
    return 0;
}
