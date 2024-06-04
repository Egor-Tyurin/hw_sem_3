
// ������������ ����������
#include <conio.h> // ��� ������� _getch, ������� ��������� �������� ������� �� ����� ��� ������� enter
#include <iostream> // ��� ������ � �������
#include <random> // ��� ��������� ��������� �����

//���������� ������� (� ��� ����� ������, ��� � ����������). ��� �����, ���� �������� ������� ����� � �������. 
// �������� ������� - ��� ����������� ����� � �����������
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"

// ��������� ��������� ��� ����� � ������������ 0.0
struct Point2D {
    int x, y;
    // � ��� �������������� �����
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
};

// ������� ���� ��� �������� ���� ���������, �� �������� ����� ������.
enum class PT { PREY, PREDATOR };

class Arena {
private:
    // ����������� ����������, �.�. ���������� �� ������ ������ ������
    static constexpr int WDTH = 30;
    static constexpr int HGHT = 30;
    static constexpr int MOVES_LIMIT = 100;
    // ��������� ���������� ������ � �������
    Point2D preypos;
    Point2D predatorpos;
    // � ��� ������
    PT playerType;

public:
    static Arena* instance; // ����������� ��������� �� ���������� ��������� ������ ����� �� �� ���� �� ����� ����� ��������� ��� ����� �� ������ 

    Arena()
        : preypos(WDTH / 2, HGHT / 2), predatorpos(0, 0),
        playerType(PT::PREY) {}
    // ����������� ����� �������, ����� ��� ���������� ������ �� �����, � ���� ��� �� ������� - ��������� ��.
    // ��� �������, ����� �� ������� �������� ��� �����
    static Arena& getInstance() {
        if (!instance) {
            // new ����� - �������� ������ �� ���� ������ ����� � ������� ��� ��������� �� ���� ������
            instance = new Arena();
        }
        return *instance;
    }
    // ������� ��� ��������� ������� ������ � �������. ����������� ��� ��������� �����������, 
    // ��� � ��� �� �� ��������� ������ �������� 
    Point2D getPreypos() const { return preypos; }
    Point2D getPredatorpos() const { return predatorpos; }

    // ������� ��� ��������� ������ � ������ �����
    static constexpr int getWDTH() { return WDTH; }
    static constexpr int getHGHT() { return HGHT; }

    // ������� ��� ����������� ���� ������
    void setPT(PT type) { playerType = type; }

    void startGame();
};

class Character {
protected:
    Point2D pos;

public:
    // ��������� �����������
    Character(int x, int y) : pos(x, y) {}

    // ��������� ������� ��������. 
    // �����������, ������ ��� �������� ��� ������ "��������" �� ����������. ��� ��������� ��������� ��-�������
    virtual void move(char key) = 0;

    Point2D getPos() const { return pos; }
};


class Prey : public Character {
public:
    Prey(int x, int y) : Character(x, y) {}

    void move(char key) override {
        // �������� ������� �������. ��� ������� ��������������� ������� ������ ����������
        if (key == 'w' or key == 'W') {
            pos.y -= 1 + (rand() % 3);
        }
        else if (key == 's' or key == 'S') {
            pos.y += 1 + (rand() % 3);
        }
        else if (key == 'a' or key == 'A') {
            pos.x -= 1 + (rand() % 3);
        }
        else if (key == 'd' or key == 'D') {
            pos.x += 1 + (rand() % 3);
        }
        else if (key == 'q' or key == 'Q') {
            pos.x -= 1;
            pos.y -= 1;
        }
        else if (key == 'e' or key == 'E') {
            pos.x += 1;
            pos.y -= 1;
        }
        else if (key == 'z' or key == 'Z') {
            pos.x -= 1;
            pos.y += 1;
        }
        else if (key == 'c' or key == 'C') {
            pos.x += 1;
            pos.y += 1;
        }
        // �������� �� ����� �� ������. ���� �� ����, ���������� ��������� � ������ �������, 
        // ��� ����� �� ����� �� ��������������� �����

        if (pos.x < 0)
            pos.x = Arena::getWDTH() - 1;
        if (pos.y < 0)
            pos.y = Arena::getHGHT() - 1;
        if (pos.x >= Arena::getWDTH())
            pos.x = 0;
        if (pos.y >= Arena::getHGHT())
            pos.y = 0;
    }
    void move_rand() {
        // ������� ���������� ��������. ���������� � ���� � ������ ��������� ����� �� ����
        pos.x -= rand() % 3;
        pos.y += rand() % 3;

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
        // �������� ������� �������. ��� ������� ��������������� ������� ������ ����������
        if (key == 'w' or key == 'W') {
            pos.y -= 1 + (rand() % 3);
        }
        else if (key == 's' or key == 'S') {
            pos.y += 1 + (rand() % 3);
        }
        else if (key == 'a' or key == 'A') {
            pos.x -= 1 + (rand() % 3);
        }
        else if (key == 'd' or key == 'D') {
            pos.x += 1 + (rand() % 3);
        }
        else if (key == 'q' or key == 'Q') {
            pos.x -= 1;
            pos.y -= 1;
        }
        else if (key == 'e' or key == 'E') {
            pos.x += 1;
            pos.y -= 1;
        }
        else if (key == 'z' or key == 'Z') {
            pos.x -= 1;
            pos.y += 1;
        }
        else if (key == 'c' or key == 'C') {
            pos.x += 1;
            pos.y += 1;
        }


        // �������� �� ����� �� ������. ���� �� ����, ���������� ��������� � ������ �������, 
        // ��� ����� �� ����� �� ��������������� �����

        if (pos.x < 0)
            pos.x = 0;
        if (pos.y < 0)
            pos.y = 0;
        if (pos.x >= Arena::getWDTH())
            pos.x = Arena::getWDTH() - 1;
        if (pos.y >= Arena::getHGHT())
            pos.y = Arena::getHGHT() - 1;
    }
    void moveTowards(const Point2D& target) {
        int dx = target.x - pos.x;
        int dy = target.y - pos.y;

        // �������� �����������, ����������� �� ���, �� ����� ��� ���������� ���������� �� ������
        int primaryDirectionX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
        int primaryDirectionY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;

        // �������� ��������� ��������� (1-3)
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(1, 3);

        int distanceToMove = dis(gen);

        // ���� �� ��� � ��������� ������, ��������� ������ �� ���
        if (abs(dx) > abs(dy)) {
            pos.x += primaryDirectionX * distanceToMove;
        }

        else {
            // � ��������
            pos.y += primaryDirectionY * distanceToMove;
        }
    }
};

Arena* Arena::instance = nullptr; // ��������� �����, ������� �������� ������ ������ �����, ������� �������� ���������� �� ����� ����� �������� ���������

void Arena::startGame() {
    // ������� srand ��������� ��� ������ ������� ��������� �������� ������ ��������� 
    // �����. ��� ���, ��������, std::cout << rand() ������ �� �������� 7
    srand(time(nullptr));
    int movesLeft = MOVES_LIMIT;
    while (movesLeft > 0) {
        // ���� �� ����������� ����
        system("cls");
        // ��������� ��������

        // ���������� ������� �� ������� �����, ���� ����� ��� �������, ������ * � ��������. 
        // �����, ������ ������ ���������� ������ �������, �� ������� �� ����� � �����, ��������� 
        // �� � ������������ ������ ��� �������
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
        // �������������� ������ � �������
        Prey prey(preypos.x, preypos.y);
        // const_prey �����, ����� �������� ���������� ������� moveTowards(������ 253) ����������� �����
        const Point2D const_prey(preypos.x, preypos.y);
        Predator predator(predatorpos.x, predatorpos.y);
        // ���� ������ �� ������, ��������� �� ���, � ������ ��������
        if (playerType == PT::PREY) {
            prey.move(_getch());
            predator.moveTowards(const_prey);
        }
        // ���� ��������, ������ �������� ��������� �� ����
        else if (playerType == PT::PREDATOR) {
            predator.move(_getch());
            prey.move_rand();
        }
        // �������� ������� ������� ������ � �������
        preypos = prey.getPos();
        predatorpos = predator.getPos();
        // ���� ���������� ����� ���� ������ 1, �� �� ���� �������� (������ �� �������), 
        // ���� ��������� (������ �� ������)
        if (abs(preypos.x - predatorpos.x) <= 1 &&
            abs(preypos.y - predatorpos.y) <= 1) {
            if (playerType == PT::PREY) {
                std::cout << "Game over You got caught!" << std::endl;
                break;
            }
            else {
                std::cout << "You win!" << std::endl;
                break;
            }
        }

        // ��������� ���-�� ���������� �����
        --movesLeft;
    }
    // ���� ���� ���������, ���� ��������
    if (movesLeft == 0)
        std::cout << "Game over The moves are over." << std::endl;
}

int main() {
    // �������������� ��� ������
    PT choose;
    // � ����� ������, ������� �� ������ � �������
    int ch;
    std::cout << "Choose hero:" << std::endl;
    std::cout << "1. Predator" << std::endl;
    std::cout << "2. Prey" << std::endl;
    std::cin >> ch;
    if (ch == 1)
        choose = PT::PREDATOR;
    else
        choose = PT::PREY;
    // ������� �����, ��� ��������� �� �������, ������ ������� setPT - set Player Type
    Arena::getInstance().setPT(choose);
    // ��������� ����
    Arena::getInstance().startGame();
    return 0;
}