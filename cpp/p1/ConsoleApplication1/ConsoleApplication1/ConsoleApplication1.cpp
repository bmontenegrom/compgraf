// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "./SDL2-2.0.12/include/SDL.h"
#include "./SDL2-2.0.12/include/SDL_opengl.h"
#include <iostream>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>

bool initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "No se pudo iniciar SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	//SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_OPENGL | SDL_DOUBLEBUF);
	//no funciona
	SDL_Window* window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		std::cerr << "No se pudo crear la ventana: " << SDL_GetError() << std::endl;
		return false;
	}
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	return true;
}


bool handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!initSDL())
	{
		return -1;
	}

	bool running = true;
	while (running)
	{
		running = handleEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
	}

	return 0; 
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
