#ifndef EP1_PARSER_H_
#define EP1_PARSER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Parser {
public:
	explicit Parser(char* inputFileName);
	void parseFile();
	std::string getAxiom() { return axiom; }
	std::vector<std::string> getRules() { return rules; }
	int getIterations() { return iterations; }
private:
	bool parseAxiom();
	bool parserules();
	bool parseIterations();
	void getNextLine(std::string &nextLine);
	std::ifstream inputFile_;
	std::string line;
	std::string axiom;
	std::vector<std::string> rules;
	int iterations;
};

#endif