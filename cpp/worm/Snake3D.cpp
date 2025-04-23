#include "Snake3D.h"

Snake3D::Snake3D(float startX, float startY, float startZ, float segmentSize, int initialLength)
	: speed(0.1f), currentDirection('R') {
	for (int i = 0; i < initialLength; ++i) {
		body.push_back(Cube(startX - i * segmentSize, startY, startZ, segmentSize));
	}
}
void Snake3D::move(char newDirection) {
	// Cambia la dirección solo si no es opuesta a la actual
	if ((currentDirection == 'U' && newDirection == 'D') ||
		(currentDirection == 'D' && newDirection == 'U') ||
		(currentDirection == 'L' && newDirection == 'R') ||
		(currentDirection == 'R' && newDirection == 'L')) {
		return;
	}
	currentDirection = newDirection;
	// Desplaza los segmentos siguiendo la cabeza
	for (int i = body.size() - 1; i > 0; --i) {
		body[i].setX(body[i - 1].getX());
		body[i].setY(body[i - 1].getY());
		//body[i].setZ(body[i - 1].getZ());
	}
	// Mueve la cabeza en la dirección actual
	switch (currentDirection) {
	case 'U':
		body[0].setY(body[0].getY() + speed);
		break;
	case 'D':
		body[0].setY(body[0].getY() - speed);
		break;
	case 'L':
		body[0].setX(body[0].getX() - speed);
		break;
	case 'R':
		body[0].setX(body[0].getX() + speed);
		break;
	default:
		break;
	}
}

void Snake3D::grow() {
	// Agrega un nuevo segmento al final del cuerpo
	Cube tail = body.back();
	body.push_back(Cube(tail.getX(), tail.getY(), tail.getZ(), tail.getSize()));
}

void Snake3D::render() const {
	for (const Cube& cube : body) {
		cube.render();
	}
}

void Snake3D::setDirection(char newDirection) {
	currentDirection = newDirection;
}
char Snake3D::getDirection() const {
	return currentDirection;
}

