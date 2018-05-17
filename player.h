#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "entity.h"
using namespace std;

//player is a subclass of entity
class player: public entity{
public:
	player();
	player(string InName);
	bool player_death();
	int get_health();
	bool player_victory();
};

#endif