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
private:
	bool getAxiom();
	bool getRules();
	bool getIterations();
	void getNextLine(std::string &nextLine);
	std::ifstream inputFile_;
	std::string line;
	std::string axiom;
	std::vector<std::string> rules;
	int iterations;
};

#endif