#include <iostream>
#include "entity.h"
#include <string>
using namespace std;

//default constructor
entity::entity()
{
	health = 1;
}

//function decreases health of entities
void entity::damage()
{
	health -= 1;
	return;
}
