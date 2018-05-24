#include "game.h"
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib> // for srand()
#include <ctime> // for time()

using namespace std;


//default constructor
game::game()
{
	victory = false;
	death = false;
}


//Performs the action based on the player's input
void game::input(int x, int y, room map[][5], player pc){
	player * pc_ptr;
	pc_ptr = &pc;

	//Spaces between new actions for readbility
	cout << endl; 

	//ends function if win/lose
	if (death == true){
		return;
	}

	if (victory == true){
		return;
	}

	cout << "What do you do?" << endl;
	cin >> str_input;

	//stops taking input if "giveup" is entered
	if(str_input != "giveup"){
	
		//if input is valid, direction goes through
		if(str_input == "north" || str_input == "west" || str_input == "south" || str_input == "east")
		{
			map[x][y].choose_door(str_input, x, y, pc_ptr);
			death_check(pc);

			map[x][y].movement();
			map[x][y].enter(pc_ptr);
			death_check(pc);
			
		}
		
		//Input to attack monster	
		else if(str_input == "attack")
		{
			if (map[x][y].is_monster == 1)
			{
				map[x][y].call_attack(pc_ptr);
				death_check(pc);
				if (map[x][y].is_monster == 0)
				{
					delete map[x][y].room_monster;
				}

			}

			//If no monster is present, then nothing happens
			else 
			{
				cout << "You swing at the air." << endl;
				cout << "Your imaginary friend Steve winces and takes a step back." << endl;
			}
		}
	 	
	 	//user can review the description of the room
	 	else if (str_input == "look")
	 	{
	 		map[x][y].roomlook();
		}

		//restores health
		else if (str_input == "rest")
		{
			pc.rest(map, x, y); 
		}

		//reviews palyer's current health
		else if (str_input == "status")
		{
			pc.get_health();
		}

		//final prompt to finish the game
		else if (str_input == "escape")
		{
			victory = escape(map, x, y);
		}

		//User can review the controls
		else if (str_input == "help")
		{
			help();
		}
		
		//tell player the input is invalid --> ask for new input
		else
		{
			cout << "You tried to " << str_input << endl;
			cout << "There's a time and a place for everything... but not now" << endl;
			input(x, y, map, pc);
		}
		//recursively asks for new input until the end it reached
		input(x, y, map, pc);
	}

}


//Initialises the game
void game::start(int number, room map[][5]){
	
	//Variable to change size of map (mxn matrix)
	matSize = number; 

	//Populating the map with room objects
	for(int y=0; y< matSize; y++){
		for(int x = 0; x<matSize; x++){
			map[x][y].create_map(x, y, false, false);
			//cout << map[x][y].get_room_numX() << map[x][y].get_room_numY() << endl;
		}
	}

}


//Checks if player is dead or not and whether to end the game or not
void game::death_check(player pc){
	if (pc.player_death() == true)
	{
	death = true;
	}
}


//Escape prompt works for last/escape room, "error" for the rest
bool game::escape(room map[][5], int x, int y)
{
	//If prompted while in the room with the exit, player wins
	if (map[x][y].is_exit == true)
	{
		cout << "You climb the rope to the open air!" << endl;
		cout << "You've escaped!" << endl;
		return true;
	}
	
	//If 'escape' is typed outside the exit room
	else
	{
		cout << "If only it were that easy." << endl;
		return false;
	}
}


//Gives the player an idea of the game and goal
void game::intro(){
	cout << "You find yourself in a dungeon. It's dark and cold. You need to escape." << endl;
	cout << "Find the exit, but be wary of what lurks in the darkness." << endl;
	cout << endl;
	//calls the instructions
	help();
	cout << endl;
}


//Instructions of the possible inputs which can be called on anytime
void game::help(){
	cout << "To move input the directions 'north', 'south', 'east' and 'west'." << endl;
	cout << "In the event you need to defend yourself, input 'attack'." << endl;
	cout << "To remind yourself of your surroundings, input 'look'." << endl;
	cout << "To check your health, input 'status'." << endl;
	cout << "To recover your health, input 'rest'." << endl;
	cout << "In the event you find the exit, input 'escape'." << endl;
	cout << "Input 'help' to recall this information." << endl;

}


//Spawns and places monsters and exit into the map
void game::spawn(room map[][5])
{
	map[2][2].is_exit = true;
	map[1][0].add_monster();

	srand(time(0));
	int spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][2].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][3].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[1][2].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[1][4].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[2][3].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[3][0].add_monster();
	}

}