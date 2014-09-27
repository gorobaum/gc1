#ifndef STATE_H_
#define STATE_H_

class State {
public:
	State();
	~State();
	void move(double distance);
	void turnLeft(double angle);
	void turnRight(double angle);
	void pitchDown(double angle);
	void pitchUp(double angle);
	void rollLeft(double angle);
	void rollRight(double angle);
	double* getPos();
private:
	void matrixTimesVector(double m[][3], double v[3]);
	double pos[3];
	double left[3];
	double up[3];
	double heading[3];
};

#endif