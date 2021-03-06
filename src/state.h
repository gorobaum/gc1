#ifndef STATE_H_
#define STATE_H_

class State {
public:
	void move(double distance);
	void turnLeft(double angle);
	void turnRight(double angle);
	void pitchDown(double angle);
	void pitchUp(double angle);
	void rollLeft(double angle);
	void rollRight(double angle);
	double* getPos() { return pos; }
private:
	void matrixTimesVector(double m[3][3], double v[3]);
	double pos[3] = {0,0,0};
	double left[3] = {1,0,0};
	double up[3] = {0,1,0};
	double heading[3] = {0,0,1};
};

#endif