#include "stdafx.h"

#include "scenegenerator.h"

#include <iostream>

#define angle 45
#define distance 1


void SceneGenerator::run() {
	for ( std::string::iterator it=lsystem_.begin(); it!=lsystem_.end(); ++it) {
		char currentChar = *it;
		std::cout << "Current char = " << currentChar << "\n";
		switch(currentChar) {
			case '+':
				turtle.turnLeft(angle);
				break;
			case '-':
				turtle.turnRight(angle);
				break;
			case '&':
				turtle.pitchDown(angle);
				break;
			case '^':
				turtle.pitchUp(angle);
				break;
			case '\\':
				turtle.rollLeft(angle);
				break;
			case '/':
				turtle.rollRight(angle);
				break;
			case 'A':
			case 'C':
				turtle.move(distance_);
				break;
			case '[':
				turtle.pushState();
				break;
			case ']':
				turtle.popState();
				break;
			default:
				std::cout << "Ta errado \n";
				break;
		}
	}
}