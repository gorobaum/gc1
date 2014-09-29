#if defined(_MSC_VER)
#pragma once
#endif

#ifndef EP1_PARSER_H_
#define EP1_PARSER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class lSysParser {
public:
	explicit lSysParser(const char* inputFileName);
	void parseFile();
	std::string getAxiom() { return axiom; }
	std::vector<std::string> getRules() { return rules; }
	std::vector<std::string> getMaterials() { return materials; }
	int getIterations() { return iterations; }
private:
	bool parseAxiom();
	bool parseRules();
	bool parseMaterials();
	bool parseIterations();
	void getNextLine(std::string &nextLine);
	std::ifstream inputFile_;
	std::string line;
	std::string axiom;
	std::vector<std::string> rules;
	std::vector<std::string> materials;
	int iterations;
};

#endif