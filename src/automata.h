#ifndef EP1_AUTOMATA_H_
#define EP1_AUTOMATA_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

typedef std::unordered_map<std::string,std::string> Rules;
typedef std::queue<std::string> State;

class Automata {
public:
	Automata(std::string axiom, std::vector<std::string> stringRules, int iterations);
	void run();
private:
	int iterations_;
	State currentState;
	Rules rules;
	std::string result;
	void putInState(State &state, std::string partialState);
	void initializeRules(std::vector<std::string> stringRules);
	void printState(State state);
};

#endif