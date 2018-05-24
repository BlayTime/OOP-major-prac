#ifndef ENTITY_H
#define ENTITY_H
#include <string>

using namespace std;

class entity{

protected:
	//health for both player and monsters
	int health;

public:
	entity();
	virtual void damage();
};

#endif