#ifndef ENTITY_H
#define ENTITY_H
#include <string>

using namespace std;

class entity{

protected:
	string name;
	int health;

public:
	entity();
	entity(string InName);
	string get_name();
	virtual void damage();
};

#endif