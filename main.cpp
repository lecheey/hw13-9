#include <iostream>
#include <string>
#include "graph.h"

int main(){
	Graph g;
	
	// создаем группу потенциальных друзей (если нужно больше, изменить значение SIZE в graph.h)

	g.addVertex("Oleg");
	g.addVertex("Nikita");
	g.addVertex("Nasty");
	g.addVertex("Ivan");
	g.addVertex("Eugene");

//	g.showVertex();
//	std::cout << '\n';
 
	// поиск пар и вывод на экран

	g.friends();
	g.findFriends();	
	
	return 0;
}
