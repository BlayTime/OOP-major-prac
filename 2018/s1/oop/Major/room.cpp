#include <iostream>
#include "game.h"
#include "room.h"

room::room(int index, bool trap, bool player)
{
	room_index = index;
	isTrap = trap;
	playerLocation = player;
}