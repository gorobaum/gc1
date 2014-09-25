#ifndef EP1_AUTOMATA_H_
#define EP1_AUTOMATA_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

typedef std::unordered_map<std::string,std::string> Rules;
typedef std::queue<std::string> AutomataState;

class Automata {
public:
	Automata(std::string axiom, std::vector<std::string> stringRules, int iterations);
	void run();
private:
	int iterations_;
	AutomataState currentAutomataState;
	Rules rules;
	std::string result;
	void putInAutomataState(AutomataState &AutomataState, std::string partialAutomataState);
	void initializeRules(std::vector<std::string> stringRules);
	void printAutomataState(AutomataState AutomataState);
};

#endif