#include "entity.h"
#include "player.h"
#include "trap.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	player p1 = player("Bob");
	cout << "Player health: " << p1.get_health() << ", Player name: " << p1.get_name() << endl;

	trap t1 = trap("trap 1");
	cout << "Trap name: " << t1.get_name() << ", Trap ID: " << t1.get_ID() << endl;

	trap t2 = trap("Alfonzo");
	cout << "Trap name: " << t2.get_name() << ", Trap ID: " << t2.get_ID() << endl;

}
