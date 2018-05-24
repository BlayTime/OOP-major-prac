#ifndef GAME_H
#define GAME_H
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"
#include <string>

using namespace std;

class game 
{

friend class room;

protected:
	int matSize;
	bool victory;
	bool death;
	string str_input;

public:

	game();
	void input(int x, int y, room map[][5], player pc);
	void start(int number, room map[][5]);

	void death_check(player pc);
	void intro();
	void help();
	bool escape(room map[][5], int x, int y);
	void spawn(room map[][5]);

};

#endif