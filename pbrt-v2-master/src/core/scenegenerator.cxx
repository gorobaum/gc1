#include "stdafx.h"

#include "scenegenerator.h"
#include "api.h"
#include "paramset.h"
#include "transform.h"

#include <iostream>
#include <stack>


#define angle 45
#define radius 1
#define halfdistance 0.5

void AdjustParameters(ParamSet *ps)
{
	float value, *ptr;
	value = radius;
	ptr = &value;
	ps->AddFloat("radius",  ptr, 1);
	*ptr = halfdistance;
	ps->AddFloat("zmax", ptr, 1);
	*ptr = -halfdistance;
	ps->AddFloat("zmin", ptr, 1);
}

void SceneGenerator::run(Transform *object2world, Transform *world2object) {
	std::stack<Transform *> obj2worldstck, world2objstck;
	Transform *to,*tw;
	ParamSet *ps = new ParamSet();
	AdjustParameters(ps);
	for ( std::string::iterator it=lsystem_.begin(); it!=lsystem_.end(); ++it) {
		char currentChar = *it;
		std::cout << "Current char = " << currentChar << "\n";
		switch(currentChar) {
			case '+':
				// turn right
				*object2world = *object2world*Rotate(angle, Vector(0.0, 1.0, 0.0));
				*world2object = Inverse(*object2world);
				break;
			case '-':
				// turn left
				*object2world = *object2world*Rotate(-angle, Vector(0.0, 1.0, 0.0));
				*world2object = Inverse(*object2world);
				break;
			case '&':
				// pitch up
				*object2world = *object2world*Rotate(angle, Vector(1.0, 0.0, 0.0));
				*world2object = Inverse(*object2world);
				break;
			case '^':
				// pitch down
				*object2world = *object2world*Rotate(-angle, Vector(1.0, 0.0, 0.0));
				*world2object = Inverse(*object2world);
				break;
			case '\\':
				// roll right
				*object2world = *object2world*Rotate(angle, Vector(0.0, 0.0, 1.0));
				*world2object = Inverse(*object2world);
				break;
			case '/':
				// roll left
				*object2world = *object2world*Rotate(angle, Vector(0.0, 0.0, 1.0));
				*world2object = Inverse(*object2world);
				break;
			case 'A':
				to = new Transform(*object2world);
				tw = new Transform(*world2object);
				pbrtRenderStaticShape("cylinder", *ps, to, tw);
				//turtle.move(distance_);
				*object2world = Translate(Vector(0.0,0.5,0.0))**object2world;
				*world2object = Inverse(*object2world);
				break;
			case 'C':
				pbrtRenderStaticShape("cylinder", *ps, object2world, world2object);
				turtle.move(distance_);
				break;
			case '[':
				obj2worldstck.push(object2world);
				world2objstck.push(world2object);
				break;
			case ']':
				object2world = obj2worldstck.top();
				world2object = world2objstck.top();
				obj2worldstck.pop();
				world2objstck.pop();
				break;
			default:
				std::cout << "Ta errado \n";
				break;
		}
	}
}