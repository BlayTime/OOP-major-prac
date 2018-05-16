#ifndef ROOM_H
#define ROOM_H

//Class definition for room

class room
{
public:
	room(int index, bool trap, bool player);
	int room_index;
	bool isTrap;
	bool playerLocation;
}