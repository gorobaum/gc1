#include "turtle.h"

void Turtle::move(double distance) {
	stateStack.top().move(distance);
}

void Turtle::turnLeft(double angle) {
	stateStack.top().turnLeft(angle);
}
void Turtle::turnRight(double angle) {
	stateStack.top().turnRight(angle);	
}
void Turtle::pitchDown(double angle) {
	stateStack.top().pitchDown(angle);
}

void Turtle::pitchUp(double angle) {
	stateStack.top().pitchUp(angle);
}

void Turtle::rollLeft(double angle) {
	stateStack.top().rollLeft(angle);
}

void Turtle::rollRight(double angle) {
	stateStack.top().rollRight(angle);
}

double* Turtle::getPos() { 
	return stateStack.top().getPos(); 
}

void Turtle::pushState() {
	State newState = stateStack.top();
	stateStack.push(newState);
}
void Turtle::popState() {
	stateStack.pop();
}