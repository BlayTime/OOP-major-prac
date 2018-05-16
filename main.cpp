#include <iostream>
#include <string>
#include "room.h"
using namespace std;

void inputFunc(){

	char strInput; // wont work because of this
	
	cout << "Which way? ";
	cin >> strInput;
	// getline(cin , strInput)

	//stops taking input if "stop" is entered
	if(strInput != 'S'){
		
		//if input is valid, direction goes through
		if(strInput == 'w' || strInput == 'a' || strInput == 's' || strInput == 'd'){
			cout << "You went " << strInput << endl;
			inputFunc();
		}

		//tell player the input is invalid --> ask for new input
		else if(strInput != 'w' || strInput != 'a' || strInput != 's' || strInput != 'd' ){
			cout << "You entered " << strInput << endl;
			cout << "There's a time and a place for everything... but not now" << endl;
			inputFunc();
		}


		//suggested: draw an entity/person on top of the room and a trap on top of them
		/*void update(entity* e){
			e.draw()
		}*/
	}
	//if not finished/escaped --> call function again

}

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
