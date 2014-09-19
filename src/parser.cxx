#include <sstream>

#include "parser.h"

Parser::Parser(char* inputFileName) {
	inputFile_.open(inputFileName);
}

void Parser::parseFile() {
	if (!getAxiom()) std::cout << "The Axiom has some error\n";
	else if (!getRules()) std::cout << "The Rules has some error\n";
	else if (!getIterations()) std::cout << "The Iteration has some error\n";
	std::cout << axiom << "\n";
	for (std::vector<std::string>::iterator it = rules.begin() ; it != rules.end(); ++it)
    	std::cout << *it << "\n";
   	std::cout << iterations << "\n";
}

void Parser::getNextLine(std::string &nextLine) {
	char line[256];
	inputFile_.getline(line, 256);
	nextLine.assign(line);
}

bool Parser::getAxiom() {
	getNextLine(line);
	bool gotAxiom = false;
	if(line.compare("Axiom:") == 0) {
		getNextLine(axiom);
		gotAxiom = true;
	}
	return gotAxiom;
}

bool Parser::getRules() {
	getNextLine(line);
	bool gotRules = false;
	if(line.compare("Rules:") == 0) {
		std::string rule;
		getNextLine(rule);
		while(rule.compare("endRules") != 0) {
			rules.push_back(rule);
			getNextLine(rule);
		}
		gotRules = !rules.empty();
	}
	return gotRules;
}

bool Parser::getIterations() {
	bool gotIterations = false;
	getNextLine(line);
	if(line.compare("Iterations:") == 0) {
		getNextLine(line);
		std::istringstream(line) >> iterations;
		gotIterations = true;
	}
	return gotIterations;
}