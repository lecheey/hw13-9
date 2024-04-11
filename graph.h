#define SIZE 5
#include <string>

class Graph {
    
    struct Edge {  // структура ребра
        int vertexWhere; // в какую вершину ведет
        int weight; // вес ребра
        Edge() {}
        Edge(int vw, int w): vertexWhere(vw), weight(w) {}
    };
    
    struct Vertex {  // структура вершины
        std::string name;  // номер вершины
        Edge adj_vertexes[SIZE]; // ребра, ведущие из вершины
        int edgeCount = 0;
		
		void addEdge(int vertexWhere, int weight);
		int getFriends(int index);
		int getFriendsWeight(int index);
    };

    public:

        Graph() {
           vertexCount = 0;
        }
		void addVertex(std::string n);
		void showVertex();
		void friends();
		void findFriends();

    private:
        Vertex vertexes[SIZE];
        int vertexCount;
};
