#ifndef TURTLE_H_
#define TURTLE_H_

#include <stack>
#include <vector>

#include "state.h"

class Turtle {
public:
	Turtle() {
		State state;
		stateStack.push(state);
	}
	void move(double distance);
	void turnLeft(double angle);
	void turnRight(double angle);
	void pitchDown(double angle);
	void pitchUp(double angle);
	void rollLeft(double angle);
	void rollRight(double angle);
	double* getPos();
	void pushState();
	void popState();
private:
	std::stack<State> stateStack;
};

#endif