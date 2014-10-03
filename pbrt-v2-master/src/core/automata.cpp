#include "stdafx.h"

#include "automata.h"

#include <iostream>

#define SEPARATOR ':'
#define MATSEPARATOR '|'

Automata::Automata(std::string axiom, std::vector<std::string> stringRules, std::vector<std::string> stringMaterials, int iterations) {
	iterations_ = iterations;
	putInAutomataState(currentAutomataState, axiom);
	initializeRules(stringRules);
	initializeMaterials(stringMaterials);

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

void Automata::initializeMaterials(std::vector<std::string> stringMaterials) {
	for (std::vector<std::string>::iterator it = stringMaterials.begin() ; it != stringMaterials.end(); ++it) {
		std::size_t separatorPos, lastPos = 0;
		std::string stringMaterial = *it;
		separatorPos = stringMaterial.find_first_of(SEPARATOR);
		std::string key = stringMaterial.substr(0, separatorPos);
		std::string materialsAtStr = stringMaterial.substr(separatorPos+1);

		std::string materialAtribute;
		std::vector<std::string> materialAtributes;
		while(1) {
			separatorPos = materialsAtStr.find_first_of(MATSEPARATOR, lastPos);
			if (separatorPos == std::string::npos) break;
			materialAtribute = materialsAtStr.substr(lastPos, separatorPos);
			materialAtributes.push_back(materialAtribute);
			lastPos = separatorPos+1;
		}
		materialAtribute = materialsAtStr.substr(lastPos);
		materialAtributes.push_back(materialAtribute);
		std::pair<std::string,std::vector<std::string>> materialPair(key,materialAtributes);
		materials.insert(materialPair);
	}
}

void Automata::printMaterials() {
	for ( auto it = materials.begin(); it != materials.end(); ++it ) {
		std::cout << "The material for " << it->first << " are:\n";
		std::vector<std::string> materialAtributes = it->second;
		for (std::vector<std::string>::iterator itV = materialAtributes.begin() ; itV != materialAtributes.end(); ++itV) {
			std::cout << *itV << "\n";
		}
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

void Automata::printAutomataStateToFile(AutomataState AutomataState, string filename) {
	std::ofstream out;
	out.open (filename);
	while(!AutomataState.empty()) {
		std::string partialAutomataState = AutomataState.front();
		AutomataState.pop();
		out << partialAutomataState;
	}
	out << "\n";
	out.close();
}

void Automata::run() {
	for(int iteration = 0; iteration < iterations_; iteration++) {
		//std::cout << "Starting iteration " << iteration << "\n";
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
		//printAutomataState(currentAutomataState);
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