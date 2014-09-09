#include "parser.h"

Parser::Parser(char* inputFileName) {
	inputFile_.open(inputFileName);
}


void Parser::parseFile() {
	if (getAxiom()) {
		getRules();
	} else {
		std::cout << "The file has some error\n";
	}
	std::cout << axiom << "\n";
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

	}
	return gotRules;
}