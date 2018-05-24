#include <string>
#include <iostream>
#include <cstdio>
#include "entity.h"
#include "player.h"
#include "room.h"
using namespace std;

//default constructor
player::player() : entity(){
	health = 5;
	restcount = 3;
}

//if player's health reaches 0, the player "dies" and the game ends
bool player::player_death(){
	if(health == 0){
		cout << "You are dead. GAME OVER." << endl;
		//quit/leave the program
		return true;
	}

	else{
		return false;
	}
}


//allows player to see current amount of health they have
void player::get_health()
{
	cout << "Your health is at " << health << "." << endl;
}


//player receives damage when attack
void player::attacked()
{
	damage();
	get_health();
	return; 
}


//allows player to regain for a max of 3 times
void player::rest(room map[][5], int x, int y){
	
	if (map[x][y].is_monster == true)
	{
		cout << "You think about resting, but realise there's a monster in front of you.";
	}
	else
	{
		cout << "You sit down and rest for a bit." << endl;	

		if (health < 5 && restcount != 0)
		{ 
			health = 5;
			cout << "You feel a little better." << endl;
			get_health();
			restcount -= 1;
			cout << "You can rest " << restcount << " more times." << endl;
		}
		
		else if (restcount == 0){
			cout << "You can no longer rest, you have probably slept for a total of 19 hours in this dungeon now" << endl;
			cout << "Shouldn't you be trying to leave?" << endl;
		}

		else 
		{
			cout << "You feel fine right now. No need to rest." << endl;
		}		
	}
}