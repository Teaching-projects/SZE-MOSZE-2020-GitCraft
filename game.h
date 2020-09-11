#pragma once
#ifndef GAME_H
#define GAME_H

class Game{
private:
    bool running;
public:
    Game();
    ~Game();
    void start();
    void run();
    void end();
};

#endif // !GAME_H
