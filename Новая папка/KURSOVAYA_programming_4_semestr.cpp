#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Arena.h"
#include "Point2D.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m" 


class Character {
protected:
    Point2D pos;

public:
    Character(int x, int y) : pos(x, y) {}

    virtual void move(char key) = 0;

    Point2D getPos() const { return pos; }
};


class Prey : public Character {
public:
    Prey(int x, int y) : Character(x, y) {}

    void move(char key) override {
        switch (key) {
        case 'w':
            pos.y -= 1;
            break;
        case 'W':
            pos.y -= 1;
            break;
        case 's':
            pos.y += 1;
            break;
        case 'S':
            pos.y += 1;
            break;
        case 'a':
            pos.x -= 1;
            break;
        case 'A':
            pos.x -= 1;
            break;
        case 'd':
            pos.x += 1;
            break;
        case 'D':
            pos.x += 1;
            break;
        case 'q':
            pos.x -= 1;
            pos.y -= 1;
            break;
        case 'Q':
            pos.y -= 1;
            pos.x -= 1;
            break;
        case 'e':
            pos.x += 1;
            pos.y -= 1;
            break;
        case 'E':
            pos.x += 1;
            pos.y -= 1;
            break;
        case 'z':
            pos.x -= 1;
            pos.y += 1;
            break;
        case 'Z':
            pos.x -= 1;
            pos.y += 1;
            break;
        case 'c':
            pos.x += 1;
            pos.y += 1;
            break;
        case 'C':
            pos.x += 1;
            pos.y += 1;
            break;
        default:
            std::cout << "error???" << std::endl;
            break;
        }

        if (pos.x < 0)
            pos.x = Arena::getWDTH() - 1;
        if (pos.y < 0)
            pos.y = Arena::getHGHT() - 1;
        if (pos.x >= Arena::getWDTH())
            pos.x = 0;
        if (pos.y >= Arena::getHGHT())
            pos.y = 0;
    }
};


class Predator : public Character {
public:
    Predator(int x, int y) : Character(x, y) {}

    void move(char key) override {
        switch (key) {
        case 'w':
            pos.y -= 1 + (rand() % 3);
            break;
        case 'W':
            pos.y -= 1 + (rand() % 3);
            break;
        case 's':
            pos.y += 1 + (rand() % 3);
            break;
        case 'S':
            pos.y += 1 + (rand() % 3);
            break;
        case 'a':
            pos.x -= 1 + (rand() % 3);
            break;
        case 'A':
            pos.x -= 1 + (rand() % 3);
            break;
        case 'd':
            pos.x += 1 + (rand() % 3);
            break;
        case 'D':
            pos.x += 1 + (rand() % 3);
            break;
        case 'q':
            pos.x -= 1;
            pos.y -= 1;
            break;
        case 'Q':
            pos.x -= 1;
            pos.y -= 1;
            break;
        case 'e':
            pos.x += 1;
            pos.y -= 1;
            break;
        case 'E':
            pos.x += 1;
            pos.y -= 1;
            break;
        case 'z':
            pos.x -= 1;
            pos.y += 1;
            break;
        case 'Z':
            pos.x -= 1;
            pos.y += 1;
            break;
        case 'c':
            pos.x += 1;
            pos.y += 1;
            break;
        case 'C':
            pos.x += 1;
            pos.y += 1;
            break;
        default:
            std::cout << "error???" << std::endl;
            break;
        }

        if (pos.x < 0)
            pos.x = 0;
        if (pos.y < 0)
            pos.y = 0;
        if (pos.x >= Arena::getWDTH())
            pos.x = Arena::getWDTH() - 1;
        if (pos.y >= Arena::getHGHT())
            pos.y = Arena::getHGHT() - 1;
    }
};

Arena* Arena::instance = nullptr;

void Arena::startGame() {
    srand(time(nullptr));
    int movesLeft = MOVES_LIMIT;
    while (movesLeft > 0) {
        system("cls");
        for (int y = 0; y < HGHT; ++y) {
            for (int x = 0; x < WDTH; ++x) {
                if (x == preypos.x && y == preypos.y)
                    std::cout << GREEN << "* " << RESET; 
                else if (x == predatorpos.x && y == predatorpos.y)
                    std::cout << RED << "# " << RESET; 
                else
                    std::cout << YELLOW << ". " << RESET; 
            }
            std::cout << std::endl;
        }

        Prey prey(preypos.x, preypos.y);
        Predator predator(predatorpos.x, predatorpos.y);

        if (playerType == PT::PREY) {
            prey.move(_getch());
            predator.move(_getch());
        }
        else if (playerType == PT::PREDATOR) {
            predator.move(_getch());
            prey.move(_getch());
        }

        preypos = prey.getPos();
        predatorpos = predator.getPos();

        if (abs(preypos.x - predatorpos.x) <= 1 &&
            abs(preypos.y - predatorpos.y) <= 1) {
            std::cout << "Game over You got caught!" << std::endl;
            break;
        }

        _getch();
        --movesLeft;
    }

    if (movesLeft == 0)
        std::cout << "Game over The moves are over." << std::endl;
}

int main() {
    PT choose;
    int ch;
    std::cout << "Choose hero:" << std::endl;
    std::cout << "1. Predator" << std::endl;
    std::cout << "2. Prey" << std::endl;
    std::cin >> ch;
    if (ch == 1)
        choose = PT::PREDATOR;
    else
        choose = PT::PREY;
    Arena::getInstance().setPT(choose);
    Arena::getInstance().startGame();
    return 0;
}