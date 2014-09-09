#include "parser.h"

Parser::Parser(char* inputFileName) {
	inputFile_.open(inputFileName);
}


void Parser::parseFile() {
	while(!inputFile_.eof()) {
		inputFile_.getline(line, 256);
		std::cout << line << "\n";
	}
}