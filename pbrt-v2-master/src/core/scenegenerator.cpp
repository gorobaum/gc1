#include "stdafx.h"

#include "scenegenerator.h"
#include "api.h"
#include "paramset.h"
#include "transform.h"

#include <iostream>
#include <stack>


#define angle 25
#define radius 0.4
#define distanceMultiplier 1.2

float *getDirection(float *direction, Transform object2world)
{
	direction[0] = 0.0;
	direction[1] = 0.0;
	direction[2] = 1.0;
	direction[3] = 0.0;
	direction = MatrixVectorMult(object2world, direction);
	return direction;
}

float getDistance(float *direction, Transform object2world)
{
	return sqrt(direction[0]*direction[0]+direction[1]*direction[1]+direction[2]*direction[2]);
}

void AdjustParameters(ParamSet *ps, float distance)
{
	float value, *ptr;
	value = radius;
	ptr = &value;
	ps->AddFloat("radius",  ptr, 1);
	*ptr = distance*distanceMultiplier;
	ps->AddFloat("zmax", ptr, 1);
	*ptr = 0*distanceMultiplier;
	ps->AddFloat("zmin", ptr, 1);
}

void SceneGenerator::run(Transform *object2world, Transform *world2object) {
	std::stack<Transform> translationstck, rotationstck;
	float *initial_direction, *new_dir, distance;
	initial_direction = new float[4];
	initial_direction = getDirection(initial_direction, *object2world);
	distance = getDistance(initial_direction, *object2world);
	Transform *to,*tw, rotation, translation;
	ParamSet *ps = new ParamSet();
	AdjustParameters(ps, distance);
	int openBracer = 0;
	for ( std::string::iterator it=lsystem_.begin(); it!=lsystem_.end(); ++it) {
		char currentChar = *it;
		//std::cout << "Current char = " << currentChar << "\n";
		switch(currentChar) {
			case '-':
				// turn left
				rotation = Rotate(angle, Vector(0.0, 1.0, 0.0))*rotation;
				break;
			case '+':
				// turn right
				rotation = Rotate(-angle, Vector(0.0, 1.0, 0.0))*rotation;
				break;
			case '^':
				// pitch down
				rotation = Rotate(angle, Vector(1.0, 0.0, 0.0))*rotation;
				break;
			case '&':
				// pitch up
				rotation = Rotate(-angle, Vector(1.0, 0.0, 0.0))*rotation;
				break;
			case '/':
				// roll right
				rotation = Rotate(angle, Vector(0.0, 0.0, 1.0))*rotation;
				break;
			case '\\':
				// roll left
				rotation = Rotate(-angle, Vector(0.0, 0.0, 1.0))*rotation;
				break;
			case 'A':
				printf("initial: [0]=%f [1]=%f [2]=%f\n",initial_direction[0],initial_direction[1],initial_direction[2]);
				new_dir = MatrixVectorMult(rotation, initial_direction);
				printf("new: [0]=%f [1]=%f [2]=%f\n",new_dir[0],new_dir[1],new_dir[2]);
				to = new Transform(translation*rotation**object2world);
				tw = new Transform(Inverse(*to));
				pbrtRenderStaticShape("cylinder", *ps, to, tw);
				translation = Translate(Vector(new_dir[0], new_dir[1], new_dir[2]))*translation;
				break;
			case 'C':
				break;
			case '[':
				openBracer++;
				translationstck.push(translation);
				rotationstck.push(rotation);
				break;
			case ']':
				if (openBracer == 0) {
					std::cout << "Existe um ] a mais \n";
					exit(0);
				}
				else openBracer--;
				translation = translationstck.top();
				rotation = rotationstck.top();
				translationstck.pop();
				rotationstck.pop();
				break;
			default:
				//std::cout << "Ta errado \n";
				break;
		}
	}
}