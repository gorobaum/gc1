#include "automata.h"

#include <iostream>

#define SEPARATOR ':'

Automata::Automata(std::string axiom, std::vector<std::string> stringRules, int iterations) {
	iterations_ = iterations;
	putInState(currentState, axiom);
	initializeRules(stringRules);
}

void Automata::putInState(State &state, std::string partialState) {
	for(std::string::iterator it=partialState.begin(); it!=partialState.end(); ++it) {
		std::string character(1, *it);
		state.push(character);
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

void Automata::printState(State state) {
	while(!state.empty()) {
		std::string partialState = state.front();
		state.pop();
		std::cout << partialState;
	}
	std::cout << "\n";
}

void Automata::run() {
	for(int iteration = 0; iteration < iterations_; iteration++) {
		std::cout << "Starting iteration " << iteration << "\n";
		State nextState;
		while(!currentState.empty()) {
			std::string character = currentState.front();
			currentState.pop();
			Rules::const_iterator got = rules.find(character);
			if(got != rules.end()) {
				std::string partialState =  got->second;
				putInState(nextState, partialState);
			} else {
				putInState(nextState, character);
			}
		}
		currentState = nextState;
		printState(currentState);
	}
}