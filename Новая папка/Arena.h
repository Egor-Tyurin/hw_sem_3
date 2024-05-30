#pragma once

#include <iostream>

#include "Point2D.h"

enum class PT { PREY, PREDATOR };

class Arena {
private:
    static constexpr int WDTH = 30;
    static constexpr int HGHT = 30;
    static constexpr int MOVES_LIMIT = 100;

    Point2D preypos;
    Point2D predatorpos;
    PT playerType;

public:
    static Arena* instance;

    Arena()
        : preypos(WDTH / 2, HGHT / 2), predatorpos(0, 0),
        playerType(PT::PREY) {}

    static Arena& getInstance() {
        if (!instance) {
            instance = new Arena();
        }
        return *instance;
    }

    Point2D getPreypos() const { return preypos; }
    Point2D getPredatorpos() const { return predatorpos; }

    static int getWDTH() { return WDTH; }
    static int getHGHT() { return HGHT; }

    void setPT(PT type) { playerType = type; }

    void startGame();
};