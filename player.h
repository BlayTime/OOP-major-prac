#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "entity.h"
using namespace std;

class room;

//player is a subclass of entity
class player: public entity{
private: 
	int restcount;

public:

	player();
	bool player_death();
	void get_health();
	void attacked();
	void rest(room map[][5], int x, int y);
};

#endif