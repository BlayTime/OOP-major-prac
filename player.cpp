#include "entity.h"
#include "player.h"
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

//default constructor
player::player() : entity(){
	name = "Player";
	health = 3;
}

//With input name constructor 
player::player(string InName) : entity(InName){
	name = InName;
	health = 3;
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

//allows player/controller to see current amount of health they haves
int player::get_health(){
	return health;
}

bool player::player_victory(){
	cout << "You've escaped!" << endl;
}