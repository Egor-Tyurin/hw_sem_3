
// Подключаемые библиотеки
#include <conio.h> // для функции _getch, которая позволяет получать символы из ввода без нажатия enter
#include <iostream> // для вывода в консоль
#include <random> // для генерации рандомных чисел

//Определяем макросы (о них можно думать, как о переменных). Они нужны, чтоб выводить цветной текст в консоль. 
// Страшные символы - это обозначение цвета в операционке
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"

// Объявляем структуру для точки с координатами 0.0
struct Point2D {
    int x, y;
    // В ней инициализируем точку
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
};

// Создаем енам для хранения типа персонажа, за которого будем играть.
enum class PT { PREY, PREDATOR };

class Arena {
private:
    // Статическая переменная, т.к. используем ее только внутри класса
    static constexpr int WDTH = 30;
    static constexpr int HGHT = 30;
    static constexpr int MOVES_LIMIT = 100;
    // Объявляем координаты жертвы и хищника
    Point2D preypos;
    Point2D predatorpos;
    // и тип игрока
    PT playerType;

public:
    static Arena* instance; // Статический указатель на конкретный экземпляр класса Арена но мы пока не знаем какой конкретно это будет за обьект 

    Arena()
        : preypos(WDTH / 2, HGHT / 2), predatorpos(0, 0),
        playerType(PT::PREY) {}
    // Прописываем такую функцию, чтобы она возвращала ссылку на арену, а если она не создана - создавала ее.
    // Так сделано, чтобы не создать случайно две арены
    static Arena& getInstance() {
        if (!instance) {
            // new арена - выделить напять на весь обьект арены и вернуть нам указатель на этот обьект
            instance = new Arena();
        }
        return *instance;
    }
    // Функции для получения позиции жертвы и хищника. Константные как указатель компилятору, 
    // что в них мы не планируем ничего изменять 
    Point2D getPreypos() const { return preypos; }
    Point2D getPredatorpos() const { return predatorpos; }

    // Функции для получения ширины и высоты арены
    static constexpr int getWDTH() { return WDTH; }
    static constexpr int getHGHT() { return HGHT; }

    // Функция для выставления типа игрока
    void setPT(PT type) { playerType = type; }

    void startGame();
};

class Character {
protected:
    Point2D pos;

public:
    // Объявляем конструктор
    Character(int x, int y) : pos(x, y) {}

    // Объявляем функцию движения. 
    // Виртуальную, потому что движение для класса "персонаж" не существует. Все персонажи двигаются по-разному
    virtual void move(char key) = 0;

    Point2D getPos() const { return pos; }
};


class Prey : public Character {
public:
    Prey(int x, int y) : Character(x, y) {}

    void move(char key) override {
        // Проверка нажатой клавиши. При нажатии соответствующим образом меняем координаты
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
        // Проверка на выход из границ. Если он есть, перемещаем персонажа к другой стороне, 
        // как будто он вышел из противоположной стены

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
        // Функция рандомного движения. Прибавляем к иксу и игреку рандомное число до трех
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
        // Проверка нажатой клавиши. При нажатии соответствующим образом меняем координаты
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


        // Проверка на выход из границ. Если он есть, перемещаем персонажа к другой стороне, 
        // как будто он вышел из противоположной стены

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

        // Выбираем направление, основываясь на том, по какой оси наибольшее расстояние до жертвы
        int primaryDirectionX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
        int primaryDirectionY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;

        // Выбираем рандомную дистанцию (1-3)
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(1, 3);

        int distanceToMove = dis(gen);

        // Если по оси Х дистанция больше, двигаемся только по ней
        if (abs(dx) > abs(dy)) {
            pos.x += primaryDirectionX * distanceToMove;
        }

        else {
            // И наоборот
            pos.y += primaryDirectionY * distanceToMove;
        }
    }
};

Arena* Arena::instance = nullptr; // Экземпляр арены, который является членом класса АРЕНА, который является указателем на арену равен нулевому указателю

void Arena::startGame() {
    // Функция srand позволяет при каждом запуске программы получать другое рандомное 
    // число. Без нее, например, std::cout << rand() всегда бы выдавало 7
    srand(time(nullptr));
    int movesLeft = MOVES_LIMIT;
    while (movesLeft > 0) {
        // Пока не закончились ходы
        system("cls");
        // Обновляем терминал

        // Проходимся целиком по массивы арены, если видим там хищника, рисуем * и наоборот. 
        // Видим, значит чекаем координаты ячейки массива, на которой мы стоим в цикле, сравнивая 
        // их с координатами жертвы или хищника
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
        // Инициализируем жертву и хищника
        Prey prey(preypos.x, preypos.y);
        // const_prey нужно, чтобы передать координаты функции moveTowards(строка 253) константную точку
        const Point2D const_prey(preypos.x, preypos.y);
        Predator predator(predatorpos.x, predatorpos.y);
        // Если играем за жертву, двигаемся за нее, а хищник догоняет
        if (playerType == PT::PREY) {
            prey.move(_getch());
            predator.moveTowards(const_prey);
        }
        // Если наоборот, жертва рандомно двигается по полю
        else if (playerType == PT::PREDATOR) {
            predator.move(_getch());
            prey.move_rand();
        }
        // Получаем текущую позицию жертвы и хищника
        preypos = prey.getPos();
        predatorpos = predator.getPos();
        // Если расстояние между ними меньше 1, то мы либо выиграли (играли за хищника), 
        // либо проиграли (играли за жертву)
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

        // Сокращаем кол-во оставшихся ходов
        --movesLeft;
    }
    // Если шаги кончились, игра окончена
    if (movesLeft == 0)
        std::cout << "Game over The moves are over." << std::endl;
}

int main() {
    // Инициализируем тип игрока
    PT choose;
    // и выбор игрока, который он вводит в консоль
    int ch;
    std::cout << "Choose hero:" << std::endl;
    std::cout << "1. Predator" << std::endl;
    std::cout << "2. Prey" << std::endl;
    std::cin >> ch;
    if (ch == 1)
        choose = PT::PREDATOR;
    else
        choose = PT::PREY;
    // Говорим арене, что конкретно мы выбрали, засчет функции setPT - set Player Type
    Arena::getInstance().setPT(choose);
    // Запускаем игру
    Arena::getInstance().startGame();
    return 0;
}