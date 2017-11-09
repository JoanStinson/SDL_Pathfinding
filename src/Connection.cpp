#include "Connection.h"

Connection::Connection()
{
}

Connection::Connection(Vector2D f, Vector2D t, float c) {
	from.coord = f;
	to.coord = t;
	cost = c;
}

Connection::~Connection() {
}

float Connection::GetCost() {
	return 0.0f;
}

Node Connection::GetFromNode() {
	return from;
}

Node Connection::GetToNode() {
	return to;
}