#include "Bar.h"

void Bar::Draw(double &value, double &maxValue) {
    DrawRectangle(posX, posY, sizeX, sizeY, backgroundColor);
    DrawRectangle(posX, posY, sizeX * (value / maxValue), sizeY, fillColor);
}

Bar::Bar(int posX, int posY, int sizeX, int sizeY, const Color &fillColor, const Color &backgroundColor) : posX(posX), posY(posY), sizeX(sizeX), sizeY(sizeY), fillColor(fillColor), backgroundColor(backgroundColor) {

}

int Bar::getPosX() const {
    return posX;
}

int Bar::getPosY() const {
    return posY;
}

int Bar::getSizeX() const {
    return sizeX;
}

int Bar::getSizeY() const {
    return sizeY;
}

const Color &Bar::getFillColor() const {
    return fillColor;
}

const Color &Bar::getBackgroundColor() const {
    return backgroundColor;
}
