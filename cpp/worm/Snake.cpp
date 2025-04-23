#include "Snake.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>

Snake::Snake(float startX, float startY, float segmentSize, int initialLength)
        : speed(0.05f), direction('R') {
        for (int i = 0; i < initialLength; ++i) {
            body.push_back(Square(startX - i * segmentSize, startY, segmentSize));
        }
    }

    void Snake::move(char newDirection) {
		// Cambia la dirección solo si no es opuesta a la actual
        if ((direction == 'U' && newDirection == 'D') ||
            (direction == 'D' && newDirection == 'U') ||
            (direction == 'L' && newDirection == 'R') ||
            (direction == 'R' && newDirection == 'L')) {
            return;
        }
		direction = newDirection;
        // Desplaza los segmentos siguiendo la cabeza
        for (int i = body.size() - 1; i > 0; --i) {
            body[i].setX(body[i - 1].getX());
			body[i].setY(body[i - 1].getY());
        }

        // Mueve la cabeza en la dirección actual
        switch (direction) {
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
        }
    }


   

    void Snake::grow() {
        // Agrega un nuevo segmento al final del cuerpo
        Square tail = body.back();
        body.push_back(Square(tail.getX(), tail.getY(), tail.getSize()));
    }

    void Snake::render() const {
        for (const Square& square : body) {
            square.render();
        }
    }
