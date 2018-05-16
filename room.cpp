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

void room::choose_door(char direction, room map[3][3]){

	switch (direction){
		case "W":
			if (room_Y == 0){
				std::cout << "don't." << std::endl;
				return;
			} 
			else { 
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move up" << std::endl;
			}
		case "A":
			if (room_X == 0 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move left" << std::endl;
			}

		case "S":
			if (room_Y == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y+1].playerLocation = 1;
				std::cout << "you move down" << std::endl;
			}

		case "D":
			if (room_X == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_x+1][room_Y].playerLocation = 1;
				std::cout << "you move right" << std::endl;
			}
	}

}
