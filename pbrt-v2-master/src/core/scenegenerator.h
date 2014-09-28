#ifndef SECNEGENERATOR_H_
#define SECNEGENERATOR_H_

#include <string>

#include "turtle.h"
#include "transform.h"

class SceneGenerator {
public:
	SceneGenerator(std::string lsystem, int distance = 1):
		lsystem_(lsystem),
		distance_(distance) {}
	void run(Transform *object2world, Transform *world2object);
private:
	std::string lsystem_;
	int distance_;
	Turtle turtle;
};

#endif