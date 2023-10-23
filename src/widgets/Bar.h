#ifndef RAYLIB_TEST_BAR_H
#define RAYLIB_TEST_BAR_H

#include "raylib.h"

class Bar {
public:
    Bar(int posX, int posY, int sizeX, int sizeY, const Color &fillColor, const Color &backgroundColor);

    void Draw(double &value, double &maxValue);

    int getPosX() const;

    int getPosY() const;

    int getSizeX() const;

    int getSizeY() const;

    const Color &getFillColor() const;

    const Color &getBackgroundColor() const;

private:
    int posX, posY, sizeX, sizeY;
    Color fillColor, backgroundColor;
};


#endif
