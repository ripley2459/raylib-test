#ifndef RAYLIB_TEST_PLAYER_H
#define RAYLIB_TEST_PLAYER_H

#include "raylib.h"

class Player {
public:
    Player();

    void Tick();

    void DrawGUI();

    Camera _camera = {0};
};


#endif
