#include <SFML/Graphics.hpp>
#include <time.h>

#include "object.h"

using namespace sf;

void object::up() {
    --y;
}

void object::down() {
    ++y;
}
void object::left() {
    --x;
}
void object::right() {
    ++x;
}
int object::getx() {
    return x;
}

int object::gety() {
    return y;
}

void object::refresh() {
    x = 0;
    y = 0;
}

Ship::Ship() {
    this->x = 0;
    this->y = 0;
}

void Ship::up() {
     --y;
}

void Ship::down() {
     ++y;
}
void Ship::left() {
    --x;
}
void Ship::right() {
    ++x;
}

Ship2::Ship2() {
    this->x = 0;
    this->y = 0;
}

void Ship2::up() {
    y -= 2;
}

void Ship2::down() {
    y += 2;
}
void Ship2::left() {
    x -= 2;
}
void Ship2::right() {
    x += 2;
}
