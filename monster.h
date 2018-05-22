#ifndef MONSTER_H
#define MONSTER_H
#include "entity.h"
#include "player.h"
#include "room.h"
using namespace std;

//monster is a subclass of entity
class monster: public entity{
	//allows trap to access the private and protected variables other classes
	friend class player;
	friend class rooms;
	
public:
	monster();
	monster(string InName);
	void destroy_monster();
	void attack_monster();
};

#endif
