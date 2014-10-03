#ifndef EP1_AUTOMATA_H_
#define EP1_AUTOMATA_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

typedef std::unordered_map<std::string,std::vector<std::string>> Materials;
typedef std::unordered_map<std::string,std::string> Rules;
typedef std::queue<std::string> AutomataState;

class Automata {
public:
	Automata(std::string axiom, std::vector<std::string> stringRules, std::vector<std::string> stringMaterials, int iterations);
	void run();
	std::string getFinalState();
private:
	int iterations_;
	AutomataState currentAutomataState;
	Rules rules;
	Materials materials;
	std::string result;
	void putInAutomataState(AutomataState &AutomataState, std::string partialAutomataState);
	void initializeRules(std::vector<std::string> stringRules);
	void initializeMaterials(std::vector<std::string> stringMaterials);
	void printAutomataState(AutomataState AutomataState);
	void printMaterials();
	void printAutomataStateToFile(AutomataState AutomataState, string filename);
};

#endif