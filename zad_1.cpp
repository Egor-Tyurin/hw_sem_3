#include <iostream>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() {
        cashOnHand = 500;
    }

    cashRegister(int cash) {
        cashOnHand = cash;
    }

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int TypeCost;
public:
    dispenserType() {
        numberOfItems = 50;
        TypeCost = 1;
    }

    dispenserType(int items, int cost) {
        numberOfItems = items;
        TypeCost = cost;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return  TypeCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
    }
};

void showSelection() {
    std::cout << "Welcome to the Vending Machine!" << std::endl;
    std::cout << "1. Candy" << std::endl;
    std::cout << "2. Chips" << std::endl;
    std::cout << "3. Gum" << std::endl;
    std::cout << "4. Cookies" << std::endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& register1) {
    int choice;
    std::cout << "Enter the number corresponding to the item you want to purchase: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "You selected Candy. Price: $" << dispenser.getCost() << std::endl;
        break;
    case 2:
        std::cout << "You selected Chips. Price: $" << dispenser.getCost() << std::endl;
        break;
    case 3:
        std::cout << "You selected Gum. Price: $" << dispenser.getCost() << std::endl;
        break;
    case 4:
        std::cout << "You selected Cookies. Price: $" << dispenser.getCost() << std::endl;
        break;
    default:
        std::cout << "Invalid selection." << std::endl;
        return;
    }

    int amount;
    std::cout << "Please enter the amount: $";
    std::cin >> amount;

    if (amount >= dispenser.getCost()) {
        register1.acceptAmount(amount);
        dispenser.makeSale();
        std::cout << "Thank you for your purchase! Enjoy your snack." << std::endl;
    }
    else {
        std::cout << "Insufficient funds. Transaction canceled." << std::endl;
    }
}

int main() {
    cashRegister register1(1000); // Создаем кассу с начальным балансом 1000
    dispenserType candyDispenser(30, 1); // Создаем диспенсер для конфет с 30 штук по цене $1

    showSelection();
    sellProduct(candyDispenser, register1);

    return 0;
}