#include "Cube.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>

Cube::Cube(float x, float y, float z, float size)
	: x(x), y(y), z(z), size(size) {
}

float Cube::getX() {
	return x;
}
float Cube::getY() {
	return y;
}
float Cube::getZ() {
	return z;
}
float Cube::getSize() {
	return size;
}
void Cube::setX(float newX) {
	x = newX;
}
void Cube::setY(float newY) {
	y = newY;
}
void Cube::setZ(float newZ) {
	z = newZ;
}
void Cube::setSize(float newSize) {
	size = newSize;
}
void Cube::render() const  {
	float half = size / 2;

	// Dibujar las caras del cubo
	glBegin(GL_QUADS);

	// Cara frontal
	glColor3f(1.0f, 0.0f, 0.0f); // Rojo
	glVertex3f(x - half, y - half, z + half);
	glVertex3f(x + half, y - half, z + half);
	glVertex3f(x + half, y + half, z + half);
	glVertex3f(x - half, y + half, z + half);

	// Cara trasera
	glColor3f(0.0f, 1.0f, 0.0f); // Verde
	glVertex3f(x - half, y - half, z - half);
	glVertex3f(x + half, y - half, z - half);
	glVertex3f(x + half, y + half, z - half);
	glVertex3f(x - half, y + half, z - half);

	// Cara izquierda
	glColor3f(0.0f, 0.0f, 1.0f); // Azul
	glVertex3f(x - half, y - half, z - half);
	glVertex3f(x - half, y - half, z + half);
	glVertex3f(x - half, y + half, z + half);
	glVertex3f(x - half, y + half, z - half);

	// Cara derecha
	glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
	glVertex3f(x + half, y - half, z - half);
	glVertex3f(x + half, y - half, z + half);
	glVertex3f(x + half, y + half, z + half);
	glVertex3f(x + half, y + half, z - half);

	// Cara superior
	glColor3f(1.0f, 0.0f, 1.0f); // Magenta
	glVertex3f(x - half, y + half, z - half);
	glVertex3f(x + half, y + half, z - half);
	glVertex3f(x + half, y + half, z + half);
	glVertex3f(x - half, y + half, z + half);

	// Cara inferior
	glColor3f(0.0f, 1.0f, 1.0f); // Cian
	glVertex3f(x - half, y - half, z - half);
	glVertex3f(x + half, y - half, z - half);
	glVertex3f(x + half, y - half, z + half);
	glVertex3f(x - half, y - half, z + half);

	glEnd();
}
