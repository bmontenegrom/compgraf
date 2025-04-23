#pragma once
#include <vector>
#include "Cube.h"
class Snake3D
{
private:
    std::vector<Cube> body;  // Lista de segmentos (cubos)
    float speed;             // Velocidad de movimiento
    char currentDirection;   // Dirección actual ('U', 'D', 'L', 'R')
public:
	Snake3D(float startX, float startY, float startZ, float segmentSize, int initialLength);
	void move(char newDirection);
	void grow();
	void render() const;
	void setDirection(char newDirection);
	char getDirection() const;

};

