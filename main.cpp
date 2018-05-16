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
}
