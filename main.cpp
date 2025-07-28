#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> // For rand()
#include <ctime>   // For time(), to seed rand()

struct User {
    std::string phone;
    std::string pin;
    double balance;
    std::vector<std::string> transactions; // Optional
};

bool login(const std::vector<User>& users, User& currentUser);
void displayMenu();
void sendMoney(User& sender, std::vector<User>& users);
void withdrawCash(User& user, std::vector<User>& users);
void buyAirtime(User& user, std::vector<User>& users);
void payBill(User& user, std::vector<User>& users);
void myAccount(User& user, std::vector<User>& users);
double calculateFee(double amount, const std::string& type);

int main() {
    std::srand(std::time(0)); // Seed for rand()

    std::vector<User> users = {
        {"0712345678", "1234", 1000.0},
        {"0723456789", "5678", 500.0}
    };
    User currentUser;
    if (!login(users, currentUser)) return 1;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: sendMoney(currentUser, users); break;
            case 2: withdrawCash(currentUser, users); break;
            case 3: buyAirtime(currentUser, users); break;
            case 4: payBill(currentUser, users); break;
            case 5: myAccount(currentUser, users); break;
            case 6: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

bool login(const std::vector<User>& users, User& currentUser) {
    std::string phone, pin;
    std::cout << "Enter phone number: ";
    std::cin >> phone;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    auto it = std::find_if(users.begin(), users.end(), [&](const User& u) {
        return u.phone == phone && u.pin == pin;
    });

    if (it != users.end()) {
        currentUser = *it;
        std::cout << "Login successful! Welcome.\n";
        return true;
    }
    std::cout << "Invalid phone number or PIN!\n";
    return false;
}

void displayMenu() {
    std::cout << "\nM-Pesa Simulator Menu\n";
    std::cout << "1. Send Money\n";
    std::cout << "2. Withdraw Cash\n";
    std::cout << "3. Buy Airtime\n";
    std::cout << "4. Pay Bill\n";
    std::cout << "5. My Account\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter choice: ";
}

double calculateFee(double amount, const std::string& type) {
    if (type == "send") {
        if (amount <= 100) return 0;
        else if (amount <= 500) return 7;
        else if (amount <= 1000) return 13;
        else if (amount <= 1500) return 23;
        else if (amount <= 2500) return 33;
        else if (amount <= 3500) return 53;
        else if (amount <= 5000) return 57;
        else if (amount <= 7500) return 78;
        else if (amount <= 10000) return 90;
        else if (amount <= 15000) return 100;
        else if (amount <= 20000) return 105;
        else return 108;
    } else if (type == "withdraw") {
        if (amount < 50) return 0; // Minimum withdrawal is Ksh 50
        else if (amount <= 100) return 11;
        else if (amount <= 2500) return 29;
        else if (amount <= 3500) return 52;
        else if (amount <= 5000) return 69;
        else if (amount <= 7500) return 87;
        else if (amount <= 10000) return 115;
        else if (amount <= 15000) return 167;
        else if (amount <= 20000) return 185;
        else if (amount <= 35000) return 197;
        else if (amount <= 50000) return 278;
        else return 309;
    } else if (type == "airtime") {
        return 0; // Placeholder, define appropriate fees
    } else if (type == "paybill") {
        return 0; // Placeholder, define appropriate fees
    }
    return 0;
}

void sendMoney(User& sender, std::vector<User>& users) {
    std::string recipientPhone, pin;
    double amount;
    std::cout << "Enter recipient phone number: ";
    std::cin >> recipientPhone;
    std::cout << "Enter amount (Ksh): ";
    std::cin >> amount;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    if (pin != sender.pin) {
        std::cout << "Invalid PIN!\n";
        return;
    }

    auto recipient = std::find_if(users.begin(), users.end(), [&](User& u) {
        return u.phone == recipientPhone;
    });

    if (recipient == users.end()) {
        std::cout << "Recipient not found!\n";
        return;
    }

    double fee = calculateFee(amount, "send");
    if (sender.balance < amount + fee) {
        std::cout << "Insufficient balance! (Including fee: Ksh " << fee << ")\n";
        return;
    }

    sender.balance -= (amount + fee);
    recipient->balance += amount;
    for (auto& user : users) {
        if (user.phone == sender.phone) {
            user = sender;
            break;
        }
    }
    std::cout << "Sent Ksh " << amount << " to " << recipientPhone
              << ". Fee: Ksh " << fee << ". New balance: Ksh " << sender.balance
              << ". Transaction ID: ABC" << std::rand() % 10000 << "\n";
}

void withdrawCash(User& user, std::vector<User>& users) {
    std::string agentNumber, pin;
    double amount;
    std::cout << "Enter agent number: ";
    std::cin >> agentNumber;
    std::cout << "Enter amount (Ksh): ";
    std::cin >> amount;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    if (pin != user.pin) {
        std::cout << "Invalid PIN!\n";
        return;
    }

    double fee = calculateFee(amount, "withdraw");
    if (user.balance < amount + fee) {
        std::cout << "Insufficient balance! (Including fee: Ksh " << fee << ")\n";
        return;
    }

    user.balance -= (amount + fee);
    for (auto& u : users) {
        if (u.phone == user.phone) {
            u = user;
            break;
        }
    }
    std::cout << "Withdrawn Ksh " << amount << " from agent " << agentNumber
              << ". Fee: Ksh " << fee << ". New balance: Ksh " << user.balance
              << ". Transaction ID: XYZ" << std::rand() % 10000 << "\n";
}

void buyAirtime(User& user, std::vector<User>& users) {
    std::string phoneNumber, pin;
    double amount;
    std::cout << "Enter phone number to buy airtime for: ";
    std::cin >> phoneNumber;
    std::cout << "Enter amount (Ksh): ";
    std::cin >> amount;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    if (pin != user.pin) {
        std::cout << "Invalid PIN!\n";
        return;
    }

    double fee = calculateFee(amount, "airtime");
    if (user.balance < amount + fee) {
        std::cout << "Insufficient balance! (Including fee: Ksh " << fee << ")\n";
        return;
    }

    user.balance -= (amount + fee);
    for (auto& u : users) {
        if (u.phone == user.phone) {
            u = user;
            break;
        }
    }
    std::cout << "Bought Ksh " << amount << " airtime for " << phoneNumber
              << ". Fee: Ksh " << fee << ". New balance: Ksh " << user.balance
              << ". Transaction ID: DEF" << std::rand() % 10000 << "\n";
}

void payBill(User& user, std::vector<User>& users) {
    std::string paybillNumber, accountNumber, pin;
    double amount;
    std::cout << "Enter paybill number: ";
    std::cin >> paybillNumber;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter amount (Ksh): ";
    std::cin >> amount;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    if (pin != user.pin) {
        std::cout << "Invalid PIN!\n";
        return;
    }

    double fee = calculateFee(amount, "paybill");
    if (user.balance < amount + fee) {
        std::cout << "Insufficient balance! (Including fee: Ksh " << fee << ")\n";
        return;
    }

    user.balance -= (amount + fee);
    for (auto& u : users) {
        if (u.phone == user.phone) {
            u = user;
            break;
        }
    }
    std::cout << "Paid Ksh " << amount << " to paybill " << paybillNumber << " account " << accountNumber
              << ". Fee: Ksh " << fee << ". New balance: Ksh " << user.balance
              << ". Transaction ID: GHI" << std::rand() % 10000 << "\n";
}

void myAccount(User& user, std::vector<User>& users) {
    int choice;
    std::cout << "\nMy Account\n";
    std::cout << "1. Check Balance\n2. Change PIN\n3. Back\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Balance: Ksh " << user.balance << "\n";
            break;
        case 2: {
            std::string oldPin, newPin;
            std::cout << "Enter old PIN: ";
            std::cin >> oldPin;
            if (oldPin != user.pin) {
                std::cout << "Invalid PIN!\n";
                return;
            }
            std::cout << "Enter new PIN: ";
            std::cin >> newPin;
            user.pin = newPin;
            for (auto& u : users) {
                if (u.phone == user.phone) {
                    u = user;
                    break;
                }
            }
            std::cout << "PIN changed successfully!\n";
            break;
        }
        case 3:
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
}
