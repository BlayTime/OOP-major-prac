#ifndef ROOM_H
#define ROOM_H
#include "monster.h"
#include "player.h"
#include <string>

using namespace std;

class monster;
//Class definition for room
class room
{
friend class monster;

protected:
	int room_x;
	int room_y;
	bool player_location;

public:
	room();
	room(int index_x, int index_y, bool trapflag, bool playerflag);
	void create_map(int x, int y, bool trapflag, bool playerflag);
	void enter(player* pc);
	void entrance();
	void choose_door(string direction, int& x, int& y, player* pc); 
	void movement();
	void call_attack(player* pc);
	void room_desc();
	void roomlook();
	void add_monster();
	
	monster *room_monster;
	bool is_monster;
	bool is_exit;
	
};

#endif