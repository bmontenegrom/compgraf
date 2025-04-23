#include "Square.h"  
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>

Square::Square(float x, float y , float size)
: x(x), y(y), size(size) {  
}  


float Square::getX() {
	return x;
}
float Square::getY() {
	return y;
}
float Square::getSize() {
	return size;
}

void Square::setX(float newX) {
	x = newX;
}
void Square::setY(float newY) {
	y = newY;
}
void Square::setSize(float newSize) {
	size = newSize;
}
void Square::render() const { 
glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // Verde
glVertex2f(x - size / 2, y - size / 2); // Esquina inferior izquierda
glVertex2f(x + size / 2, y - size / 2); // Esquina inferior derecha
glVertex2f(x + size / 2, y + size / 2); // Esquina superior derecha
glVertex2f(x - size / 2, y + size / 2); // Esquina superior izquierda
glEnd();

}