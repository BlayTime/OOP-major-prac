#include <iostream>
#include "game.h"
#include "room.h"

room::room(){
	room_index = 0;
	isTrap = 0;
	playerLocation = 0;
}

room::room(int index, bool trapYN, bool playerYN)
{
	room_index = index;
	isTrap = trapYN;
	playerLocation = playerYN;
}

int room::get_room_num(){
	return room_index;
}

bool room::is_player_in_room(int index){
	return playerLocation;
}