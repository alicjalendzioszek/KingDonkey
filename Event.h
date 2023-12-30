#pragma once

#include"../SDL2-2.0.10/include/SDL.h"
#include"../SDL2-2.0.10/include/SDL_main.h"

class World;
class Okno;



class Event
{
public:
	SDL_Event eventKlikniety;

	void readEvents(World& world, Okno& okno);

};

