#ifndef _Ship_
#define _Ship_

#include <vector>

typedef std::pair<int,int> position;

namespace sf {
    class Sprite;
    class RenderWindow;
}

class Ship {

public:
    Ship();
    ~Ship();

    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();
    std::vector<position*> getTrace() {
        return trace;
    }

    bool undo() {
        if (trace.size() > 1) {
            trace.pop_back();
            current_pos = trace.back();
            return true;
        } else {
            return false;
        }
    }

    position* getCurrentPos() {
        return current_pos;
    }
    position* setCurrentPos() {
        if (!trace.empty()) {
            return trace.back();
        } else {
            return nullptr;
        }
    }
    bool undo_;
    void Ship::drawShip(sf::RenderWindow* window, int tile_size);
protected:
    int v;
    std::vector<position*> trace;
    position* current_pos;
    sf::Sprite* ship_;
};

class ZetShip : public Ship {
public:
    ZetShip();
    ~ZetShip();
};

class BattleShip : public Ship {
public:
    BattleShip();
    ~BattleShip();

    std::vector<position*> misile;
};

#endif