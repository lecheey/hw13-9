#include <iostream>
#include "graph.h"
#include <string>

void Graph::addVertex(std::string n){ // добавление вершин
	vertexes[vertexCount++].name = n;
}

void Graph::showVertex(){ // вывод списка существующих вершин
	for(int i = 0; i < SIZE; i++){
		std::cout << vertexes[i].name << '\n';
	}
}

void Graph::Vertex::addEdge(int vertexWhere, int weight){ // добавление граней
	adj_vertexes[edgeCount++] = Edge(vertexWhere, weight);
}

void Graph::friends(){ // поиск пар друзей до 3х рукопажатий включительно
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			// определение близости знакомства (колва рукопожатий)
			if((i - j == 1) || (j - i == 1)){
				vertexes[i].addEdge(j, 1);
			}
			else if((i - j == 2) || (j - i == 2)){
				vertexes[i].addEdge(j, 2);
			}
			else if((i - j == 3) || (j - i == 3)){
				vertexes[i].addEdge(j, 3);
			}
			else{
				continue;
			}
		}
	}
}

int Graph::Vertex::getFriends(int index){ // возвращает индекс друга их списка вершин
	return adj_vertexes[index].vertexWhere;
}

int Graph::Vertex::getFriendsWeight(int index){ // возвращает колво рукопожатий
	return adj_vertexes[index].weight;
}

void Graph::findFriends(){ // выводит все существующие связи (пары)
	int index = 0;
	int level = 0;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < vertexes[i].edgeCount; j++){
			index = vertexes[i].getFriends(j);
			level = vertexes[i].getFriendsWeight(j);
			std::cout << vertexes[i].name;
			if(level == 1){
				std::cout << " дружит с ";
			}
			else if(level == 2){
				std::cout << " пару раз видел ";
			}
			else if(level == 3){
				std::cout << " что-то слышал о ";
			}
			std::cout << vertexes[index].name << '\n';
		}
		std::cout << '\n';
	}
}
