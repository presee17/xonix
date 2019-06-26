#ifndef _Input_Handler_
#define _Input_Handler_

#include "object.h"

class Command {
public:
    virtual ~Command() {}
    virtual void execute(object* obj) = 0;
};

class UpCommand : public Command {
public:
    virtual void execute(object* obj);
};

class DownCommand : public Command {
public:
    virtual void execute(object* obj);
};

class LeftCommand : public Command {
public:
    virtual void execute(object* obj);
};

class RightCommand : public Command {
public:
    virtual void execute(object* obj);
};

class InputHandler {
public:
    InputHandler() {
        button_up_ = new UpCommand();
        button_down_ = new DownCommand();
        button_left_ = new LeftCommand();
        button_right_ = new RightCommand();
    }
    ~InputHandler() {
        delete button_up_;
        delete button_down_;
        delete button_left_;
        delete button_right_;
    }
    void handleInput(object* obj);

private:

    Command* button_up_;
    Command* button_down_;
    Command* button_left_;
    Command* button_right_;
};
#endif