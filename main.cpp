#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Aplikacja.h"

extern "C" {
#include"../SDL2-2.0.10/include/SDL.h"
#include"../SDL2-2.0.10/include/SDL_main.h"
}

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char** argv) {


	Aplikacja aplikacja;
	aplikacja.utworzAplikacje();
	aplikacja.wystartujGre();

	return 0;
};

