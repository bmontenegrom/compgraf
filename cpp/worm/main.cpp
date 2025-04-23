/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <iostream>
#include <SDL_opengl.h>
#include <GL/glu.h>

#include "Snake.h" // Cambiar <Snake.h> a "Snake.h" para incluir el archivo local correctamente
#include "Snake3D.h" // Cambiar <Snake3D.h> a "Snake3D.h" para incluir el archivo local correctamente

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Posición inicial del cuadrado
float posX = 0.0f;
float posY = 0.0f;
float speed = 0.05f; // Velocidad de movimiento






bool init(SDL_Window** window, SDL_GLContext* context) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error al inicializar SDL: %s\n", SDL_GetError());
		return false;
	}

	*window = SDL_CreateWindow("Cuadrado con OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!*window) {
		printf("Error al crear ventana: %s\n", SDL_GetError());
		return false;
	}

	*context = SDL_GL_CreateContext(*window);
	if (!*context) {
		printf("Error al crear contexto OpenGL: %s\n", SDL_GetError());
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glViewport(0, 0, 800, 600);
	return true;
}


void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Dibujar un cuadrado en la posición actual
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
	glVertex2f(posX - 0.1f, posY - 0.1f); // Esquina inferior izquierda
	glVertex2f(posX + 0.1f, posY - 0.1f); // Esquina inferior derecha
	glVertex2f(posX + 0.1f, posY + 0.1f); // Esquina superior derecha
	glVertex2f(posX - 0.1f, posY + 0.1f); // Esquina superior izquierda
	glEnd();

}


int main(int argc, char* args[]){
	//inicializacion

	SDL_Window* window = nullptr;
	SDL_GLContext context = nullptr;
	if (!init(&window, &context)) {
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Configuración ortográfica
	glMatrixMode(GL_MODELVIEW);


	//glClear(GL_COLOR_BUFFER_BIT)
	Snake3D snake(0.0f, 0.0f, -2.0f, 0.3f, 5); // Comienza con 5 segmentos

	Cube cube(0.0f, 0.0f, -2.0f, 0.3f); // Crear un cubo en la posición inicial

    bool running = true;
    SDL_Event event;

    while (running) {
        // Manejar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        snake.move('U');
                        break;
                    case SDLK_DOWN:
                        snake.move('D');
                        break;
                    case SDLK_LEFT:
                        snake.move('L');
                        break;
                    case SDLK_RIGHT:
                        snake.move('R');
                        break;
                }
            }
        }

		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity(); // Reiniciar la matriz de modelo-vista
		cube.render(); // Renderizar el cubo
		SDL_GL_SwapWindow(window); // Actualizar pantalla

    }


	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
