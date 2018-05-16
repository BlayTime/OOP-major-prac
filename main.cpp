#include <iostream>
#include <string>
#include "room.h"
using namespace std;

int main(){
	
	//Variable to change size of map (mxn matrix)
	const int matSize = 3;

	//Initialising map
	room **map = new room*[matSize];
	for(int i = 0; i < matSize; i++){
		map[i] = new room[matSize];
	}

	//Populating the map with room objects
	for(int x=0; x< matSize; x++){
		for(int y = 0; y<matSize; y++){
			map[x][y] = room(x,y,false,false);
			cout << map[x][y].get_room_numX() << map[x][y].get_room_numY() << endl;
		}
	}



	//tests
	map[1][1].playerLocation = true;
	cout << map[1][1].is_player_in_room(1,1) << endl;
	cout << map[1][0].is_player_in_room(1,0) << endl;
	cout << map[2][0].is_player_in_room(2,0) << endl;
}

void room::choose_door(char direction, int x, int y){

		/*if (direction == 'W'){
			if (room_Y == 0){
				std::cout << "don't." << std::endl;
				return;
			} 
			else { 
				matrix[room_X][room_Y].playerLocation = 0;
				matrix[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move up" << std::endl;
			}
		}
		if (direction == 'A'){
			if (room_X == 0 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				matrix[room_X][room_Y].playerLocation = 0;
				matrix[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move left" << std::endl;
			}
		}
		if (direction == 'S'){
			if (room_Y == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				matrix[room_X][room_Y].playerLocation = 0;
				matrix[room_X][room_Y+1].playerLocation = 1;
				std::cout << "you move down" << std::endl;
			}
		}*/
		if (direction == 'D'){
			if (room_X == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				playerLocation = 0;
				x +=1;
				//std::cout << "you move right" << std::endl;
			}
		}
}

void room::movement(char direction){
		if (direction == 'D'){
			if (room_X == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				playerLocation = 1;
				std::cout << "you move right" << std::endl;
			}
		}
}
