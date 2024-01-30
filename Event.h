#pragma once

#include"../SDL2-2.0.10/include/SDL.h"
#include"../SDL2-2.0.10/include/SDL_main.h"

class World;
class Okno;



class Event
{
private:
	SDL_Event eventKlikniety;
public:
	
	void readEvents(World& world, Okno& okno);

};

