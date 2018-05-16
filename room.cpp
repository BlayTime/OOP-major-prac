#include <iostream>
#include "game.h"
#include "room.h"

room::room(){
	room_X = 0;
	room_Y = 0;
	isTrap = 0;
	playerLocation = 0;
}

room::room(int index_X, int index_Y, bool trapYN, bool playerYN)
{
	room_X = index_X;
	room_Y = index_Y;
	isTrap = trapYN;
	playerLocation = playerYN;
}

int room::get_room_numX(){
	return room_X;
}

int room::get_room_numY(){
	return room_Y;
}

bool room::is_player_in_room(int index_X, int index_Y){
	return playerLocation;
}
