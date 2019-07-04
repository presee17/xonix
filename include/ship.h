#ifndef _Ship_
#define _Ship_

#include <vector>

typedef std::pair<int,int> position;

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
    bool undo;
protected:
    int v;
    std::vector<position*> trace;
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