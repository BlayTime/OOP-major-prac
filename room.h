#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "trap.h"

//Class definition for room
class room
{
public:
	room();
	room(int index_X, int index_Y, bool trapYN, bool playerYN);
	void create_map(int x, int y, bool trapflag, bool playerflag);
	void enter();
	void entrance();

	int get_room_numX();
	int get_room_numY();
	bool is_player_in_room();
	void choose_door(char direction, int& x, int& y); 
	void movement(char direction);
	void disarmTrap();

	int room_X;
	int room_Y;
	bool isTrap;
	bool playerLocation;
	bool isExit;
	
};

#endif
