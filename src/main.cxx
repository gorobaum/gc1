#include <iostream>
#include <fstream>

#include "parser.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Dae precisa do arquivo com os roles\n";
	} else {
		Parser parser(argv[1]);
		parser.parseFile();
	}
	return 0;
}