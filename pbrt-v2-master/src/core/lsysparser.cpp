#include "stdafx.h"

#include <sstream>

#include "lsysparser.h"

lSysParser::lSysParser(const char* inputFileName) {
	inputFile_.open(inputFileName);
}

void lSysParser::parseFile() {
	if (!parseAxiom()) std::cout << "The Axiom has some error\n";
	else if (!parseRules()) std::cout << "The Rules has some error\n";
	else if (!parseMaterials()) std::cout << "The Material has some error\n";
	else if (!parseIterations()) std::cout << "The Iteration has some error\n";
	inputFile_.close();
}

void lSysParser::getNextLine(std::string &nextLine) {
	char line[256];
	inputFile_.getline(line, 256);
	nextLine.assign(line);
}

bool lSysParser::parseAxiom() {
	getNextLine(line);
	bool gotAxiom = false;
	if(line.compare("Axiom:") == 0) {
		getNextLine(axiom);
		gotAxiom = true;
	}
	return gotAxiom;
}

bool lSysParser::parseRules() {
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

bool lSysParser::parseMaterials() {
	getNextLine(line);
	bool gotMaterials = false;
	if(line.compare("Materials:") == 0) {
		std::string material;
		getNextLine(material);
		while(material.compare("endMaterials") != 0) {
			materials.push_back(material);
			getNextLine(material);
		}
		gotMaterials = !materials.empty();
	}
	return gotMaterials;
}


bool lSysParser::parseIterations() {
	bool gotIterations = false;
	getNextLine(line);
	if(line.compare("Iterations:") == 0) {
		getNextLine(line);
		std::istringstream(line) >> iterations;
		gotIterations = true;
	}
	return gotIterations;
}