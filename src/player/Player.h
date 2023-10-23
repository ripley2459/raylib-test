#ifndef RAYLIB_TEST_PLAYER_H
#define RAYLIB_TEST_PLAYER_H

#include "raylib.h"
#include "../widgets/Bar.h"

class Bar;

class Player {
public:
    Player();

    void Tick();

    void Draw();

    Camera _camera = {0};
private:
    double _life, _maxLife, _exp, _maxExp;

    Bar _lifeBar = Bar(15, 15, 200, 15, GREEN, BLACK);
    Bar _expBar = Bar(_lifeBar.getPosX(), _lifeBar.getPosY() + _lifeBar.getSizeY(), _lifeBar.getSizeX(), 5, SKYBLUE, BLACK);

    void UpdateLife();
};


#endif
