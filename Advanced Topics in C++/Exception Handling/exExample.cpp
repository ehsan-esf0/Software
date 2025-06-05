#include <iostream>
#include <stdexcept>


void checkBalance(int balance, int amount) {
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds");
    }
}


void withdraw(int balance, int amount) {
    std::cout << "Trying to withdraw " << amount << " from balance " << balance << "\n";
    checkBalance(balance, amount);
    std::cout << "Withdrawal successful!\n";
}


void performBankOperation() {
    int balance = 1000;
    int amountToWithdraw = 1500;

    withdraw(balance, amountToWithdraw);
}


int main() {
    try {
        performBankOperation();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << '\n';
    }

    std::cout << "Program continues after exception...\n";
    return 0;
}
