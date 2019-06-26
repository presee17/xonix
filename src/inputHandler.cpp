#include <SFML/Graphics.hpp>
#include <time.h>

#include "InputHandler.h"
using namespace sf;

class object;

void UpCommand::execute(object* obj) { obj->up(); }
void DownCommand::execute(object* obj) { obj->down(); }
void LeftCommand::execute(object* obj) { obj->left(); }
void RightCommand::execute(object* obj) { obj->right(); }

void InputHandler::handleInput(object* obj) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        button_up_->execute(obj);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        button_down_->execute(obj);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        button_left_->execute(obj);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        button_right_->execute(obj);
    }
};
