#include <SFML/Graphics.hpp>
#include <time.h>

#include "ship.h"

using namespace sf;

Ship::Ship() {
    trace.push_back(new position(0, 0));
    current_pos = trace.back();
    v = 1;
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile("E:/study/1/xonix/images/spaceship2.png");

    ship_ = new sf::Sprite(*texture);
    undo_ = false;
}

void Ship::up() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        int x = prev_pos->first;
        int y = prev_pos->second - i;
        for (auto pos : trace) {
            if (pos->first == x && pos->second == y) {
                undo_ = true;
            }
            else {
                trace.push_back(new position(x, y));
            }
        }
    }
    current_pos = trace.back();
}

void Ship::down() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        int x = prev_pos->first;
        int y = prev_pos->second + i;
        for (auto pos : trace) {
            if (pos->first == x && pos->second == y) {
                undo_ = true;
            } else {
                trace.push_back(new position(x, y));
            }
        }
    }
    current_pos = trace.back();
}
void Ship::left() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        int x = prev_pos->first - i;
        int y = prev_pos->second;
        for (auto pos : trace) {
            if (pos->first == x && pos->second == y) {
                undo_ = true;
            } else {
                trace.push_back(new position(x, y));
            }
        }
    }
}
void Ship::right() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        int x = prev_pos->first + i;
        int y = prev_pos->second;
        for (auto pos : trace) {
            if (pos->first == x && pos->second == y) {
                undo_ = true;
            }
            else {
                trace.push_back(new position(x, y));
            }
        }
    }
    current_pos = trace.back();
}


ZetShip::ZetShip() {
    v = 2;
}

BattleShip::BattleShip() {
    v = 1;
}

void Ship::drawShip(sf::RenderWindow* window, int tile_size) {
    ship_->setPosition(current_pos->first*tile_size, current_pos->second*tile_size);
    window->draw(*ship_);
}