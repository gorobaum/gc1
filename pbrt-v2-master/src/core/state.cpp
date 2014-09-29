#include "stdafx.h"

#include "state.h"

#include <cmath>

	State::State(){
	double pos[3] = {0,0,0};
	double left[3] = {1,0,0};
	double up[3] = {0,1,0};
	double heading[3] = {0,0,1};
}

	State::~State(){
	}

void State::move(double distance) {
	pos[0] = pos[0] + heading[0]*distance;
	pos[1] = pos[1] + heading[1]*distance;
	pos[2] = pos[2] + heading[2]*distance;
}

void State::matrixTimesVector(double m[3][3], double v[3]){
	v[0] = m[0][0]*v[0] + m[0][1]*v[1] + m[0][2]*v[2];
	v[1] = m[1][0]*v[0] + m[1][1]*v[1] + m[1][2]*v[2];
	v[2] = m[2][0]*v[0] + m[2][1]*v[1] + m[2][2]*v[2];
} 

void State::rollLeft(double angle) {
	double rotationMatrix[3][3];
	double seno = std::sin(angle);
	double coss = std::cos(angle);
	rotationMatrix[0][0] = coss;
	rotationMatrix[0][1] = -1*seno;
	rotationMatrix[0][2] = 0;
	rotationMatrix[1][0] = seno;
	rotationMatrix[1][1] = coss;
	rotationMatrix[1][2] = 0;
	rotationMatrix[2][0] = 0;
	rotationMatrix[2][1] = 0;
	rotationMatrix[2][2] = 1;
	matrixTimesVector(rotationMatrix, left);
	matrixTimesVector(rotationMatrix, up);
	matrixTimesVector(rotationMatrix, heading);
}

void State::rollRight(double angle) {
	rollLeft(-1*angle);
}

void State::pitchUp(double angle) {
	double rotationMatrix[3][3];
	double seno = std::sin(angle);
	double coss = std::cos(angle);
	rotationMatrix[0][0] = 1;
	rotationMatrix[0][1] = 0;
	rotationMatrix[0][2] = 0;
	rotationMatrix[1][0] = 0;
	rotationMatrix[1][1] = coss;
	rotationMatrix[1][2] = seno;
	rotationMatrix[2][0] = 0;
	rotationMatrix[2][1] = -1*seno;
	rotationMatrix[2][2] = coss;
	matrixTimesVector(rotationMatrix, left);
	matrixTimesVector(rotationMatrix, up);
	matrixTimesVector(rotationMatrix, heading);
}

void State::pitchDown(double angle) {
	pitchUp(-1*angle);
}

void State::turnLeft(double angle) {
	double rotationMatrix[3][3];
	double seno = std::sin(angle);
	double coss = std::cos(angle);
	rotationMatrix[0][0] = coss;
	rotationMatrix[0][1] = 0;
	rotationMatrix[0][2] = -1*seno;
	rotationMatrix[1][0] = 0;
	rotationMatrix[1][1] = 1;
	rotationMatrix[1][2] = 0;
	rotationMatrix[2][0] = seno;
	rotationMatrix[2][1] = 0;
	rotationMatrix[2][2] = coss;
	matrixTimesVector(rotationMatrix, left);
	matrixTimesVector(rotationMatrix, up);
	matrixTimesVector(rotationMatrix, heading);
}

void State::turnRight(double angle) {
	turnLeft(-1*angle);
}

double* State::getPos() { 
	return pos; 
}