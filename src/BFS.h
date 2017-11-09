#pragma once
#include "Graph.h"
#include <queue>
#include <list>
using std::cout;

Vector2D cell2pix(Vector2D cell)
{
	int offset = CELL_SIZE / 2;
	return Vector2D(cell.x*CELL_SIZE + offset, cell.y*CELL_SIZE + offset);
}

Vector2D pix2cell(Vector2D pix)
{
	return Vector2D((float)((int)pix.x / CELL_SIZE), (float)((int)pix.y / CELL_SIZE));
}

vector<Node> BFS(Node start, Node goal, Graph graph, Path p) {
	// Inicialitzar la frontera amb el node de la posici� inicial
	queue <Node> frontier;
	frontier.push(start);

	vector<pair<Node, Node>> came_from;
	came_from.push_back(pair<Node, Node>(start, NULL));

	vector <Node> neighbors, path, reversed;

	Node current(0, 0);
	Node next(0, 0);

	bool found;
	int auxSize = 0;

	while (!frontier.empty()) {
		current = frontier.front();
		frontier.pop();
		Node temp(current.coord);
		//cout << current.coord.x << " " << current.coord.y << endl;
		neighbors = graph.GetConnections(temp);
		//cout << neighbors.size() << endl; // se pasen com a posicions de cel�les. nice

		//if (current.coord == goal.coord)
			//break;

		cout << "Node start (" << current.coord.x << ", " << current.coord.y << ")" << endl;
		for (int i = 0; i < neighbors.size(); i++) {
			auxSize = 0;
			next = neighbors[i];
			cout << "	Node vei " <<  i << " (" << next.coord.x << ", " << next.coord.y << ")" << endl; //TODO no borrar els couts de moment si acas comentals poden ser utils :)
			//cout << i << endl;
			//cout << next.coord.x << ' ' << next.coord.y << endl;
			//cout << current.coord.x << ' ' << current.coord.y << endl;

			for (int j = 0; j < came_from.size(); j++) { //TODO solucionar aquest bucle
				auxSize = j;
				cout << "		Node " << j << " (" << came_from[j].first.coord.x << ", " << came_from[j].first.coord.y << ") comes from Node (" << came_from[j].second.coord.x << ", " << came_from[j].second.coord.y << ")" << endl;
				/*cout << "Node first: " << came_from[j].first.coord.x << " " << came_from[j].first.coord.y << 
					" Node second: " << came_from[j].second.coord.x << " " << came_from[j].second.coord.y << endl;*/
				found = false;			// Si next, que �s ve� de current no est� dins l'arrai de nodes explorats "came_from"
										
				if (came_from[j].first.coord == next.coord)
					found = true;
				
				if (!found) { // Afagir next a la frontera i afagir a l arrai came_from juntament amb el node del que procedeix

					frontier.push(next);
					came_from.push_back(pair<Node, Node>(next, current));
				}
				
			}
			cout << "		Came from " << auxSize << " node(s) from start" << endl;

		}


		

		/*for (int i = 0; i < came_from.size(); i++) {
			path.push_back(came_from[i].first);
			cout << path[i].coord.x << ' ' << path[i].coord.y << endl;
		}*/
		//cout << path.size() << endl;
		/*for (int i = 0; i < path.size(); i++) {
			reversed[i] = path[path.size() - 1];
		}*/
		return path;
	}
}