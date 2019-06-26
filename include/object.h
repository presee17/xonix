#ifndef _Object_
#define _Object_

#include <list>

class object {
public:
    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();

public:
    int getx();
    int gety();
    void refresh();

protected:
    int x;
    int y;
};

class Ship : public object {

public:
    Ship();
    ~Ship();

    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();

};

class Ship2 : public object {

public:
    Ship2();
    ~Ship2();

    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();

};

#endif