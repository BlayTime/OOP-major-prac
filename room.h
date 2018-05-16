#ifndef ROOM_H
#define ROOM_H

//Class definition for room

class room
{
public:
	room();
	room(int index, bool trapYN, bool playerYN);
	int get_room_numX();
	int get_room_numY();
	bool is_player_in_room(int index);
	void choose_door(char direction); 
	int room_X;
	int room_Y;
	bool isTrap;
	bool playerLocation;
};

#endif
