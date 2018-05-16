#include "entity.h"
#include "trap.h"
#include "room.h"
#include <string>
using namespace std;

int trap::currentID = 0;

//default constructor
trap::trap() : entity(){
	name = "Trap";
	health = 1;
	currentID += 1;
}

//With input name constructor
trap::trap(string InName) : entity(InName){
	name = InName;
	health = 1;
	currentID += 1;
}

//if the player enters a room with the trap in it, they both take damage and the trap destroys itself
void trap::destroy_trap() : entity(){
	if(If_player_in_room == true){
		player.damage();
		trap.damage();
		delete::trap;
	}
}

//returns the ID/# of the trap
int trap::get_ID(){
	return currentID;
}

