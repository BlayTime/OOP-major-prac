#include "entity.h"
#include <string>
using namespace std;

//default constructor
entity::entity(){
	name = "???";
	health = 1;
}

//With input name constructor
entity::entity(string InName){
	name = InName;
	health = 1;
}

//Returns entity's name
string entity::get_name(){
	return name;
}

//function decreases health of entities
int entity::damage(){
	health -= 1;
}


