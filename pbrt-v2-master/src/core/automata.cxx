#include "stdafx.h"

#include "automata.h"

#include <iostream>

#define SEPARATOR ':'

Automata::Automata(std::string axiom, std::vector<std::string> stringRules, int iterations) {
	iterations_ = iterations;
	putInAutomataState(currentAutomataState, axiom);
	initializeRules(stringRules);
}

void Automata::putInAutomataState(AutomataState &AutomataState, std::string partialAutomataState) {
	for(std::string::iterator it=partialAutomataState.begin(); it!=partialAutomataState.end(); ++it) {
		std::string character(1, *it);
		AutomataState.push(character);
	}
}

void Automata::initializeRules(std::vector<std::string> stringRules) {
	for (std::vector<std::string>::iterator it = stringRules.begin() ; it != stringRules.end(); ++it) {
		std::string stringRule = *it;
		size_t separatorPos = stringRule.find_first_of(SEPARATOR);
		std::string key = stringRule.substr(0, separatorPos);
		std::string rule = stringRule.substr(separatorPos+1);
		std::pair<std::string,std::string> rulePair(key,rule);
		rules.insert(rulePair);
	}
}

void Automata::printAutomataState(AutomataState AutomataState) {
	while(!AutomataState.empty()) {
		std::string partialAutomataState = AutomataState.front();
		AutomataState.pop();
		std::cout << partialAutomataState;
	}
	std::cout << "\n";
}

void Automata::run() {
	for(int iteration = 0; iteration < iterations_; iteration++) {
		std::cout << "Starting iteration " << iteration << "\n";
		AutomataState nextAutomataState;
		while(!currentAutomataState.empty()) {
			std::string character = currentAutomataState.front();
			currentAutomataState.pop();
			Rules::const_iterator got = rules.find(character);
			if(got != rules.end()) {
				std::string partialAutomataState =  got->second;
				putInAutomataState(nextAutomataState, partialAutomataState);
			} else {
				putInAutomataState(nextAutomataState, character);
			}
		}
		currentAutomataState = nextAutomataState;
		printAutomataState(currentAutomataState);
	}
}

std::string Automata::getFinalState() {
	std::string finalState;
	while(!currentAutomataState.empty()) {
		finalState.append(currentAutomataState.front());
		currentAutomataState.pop();
	}
	return finalState;
}