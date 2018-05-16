#include <iostream>
#include "game.h"
#include "room.h"

game::game()
{

}

void game::start()
{
	// creates room matrix and puts room variables inside
	room map[9];
	for (int i = 0; i < 9; ++i)
	{
		std::fill(map, map+9, room(i,0,0)); //populates matrix with elements of room class
	}
	std::cout << map[0].room_index <<std::endl;
}

