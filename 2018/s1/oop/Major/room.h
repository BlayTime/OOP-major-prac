#ifndef ROOM_H
#define ROOM_H

//Class definition for room

class room
{
public:
	room();
	room(int index, bool trapYN, bool playerYN);
	int get_room_num();
	bool is_player_in_room(int index);
	int room_index;
	bool isTrap;
	bool playerLocation;
};

#endif