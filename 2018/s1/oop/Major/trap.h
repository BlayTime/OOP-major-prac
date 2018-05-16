#ifndef TRAP_H
#define TRAP_H
#include "entity.h"
#include "player.h"
#include "room.h"
using namespace std;

//trap is a subclass of entity
class trap: public entity{
	//allows trap to access the private and protected variables other classes
	friend class player;
	friend class rooms;
public:
	trap();
	trap(string InName);
	static int currentID;
	int get_ID();
	void destroy_trap();
};

#endif