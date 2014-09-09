#ifndef EP1_PARSER_H_
#define EP1_PARSER_H_

#include <iostream>
#include <fstream>

class Parser {
public:
	explicit Parser(char* inputFileName);
	void parseFile();
private:
	std::ifstream inputFile_;
	char line[256];
};

#endif