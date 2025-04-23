#pragma once
#include <vector>
#include "Square.h"
class Snake {
private:
    std::vector<Square> body;  // Lista de segmentos (cuadrados)
    float speed;               // Velocidad de movimiento
    char direction;            // Dirección actual ('U', 'D', 'L', 'R')

public:
    Snake(float startX, float startY, float segmentSize, int initialLength);

    void move(char direction);


    //void changeDirection(char newDirection);

    void grow();

    void render() const;
};