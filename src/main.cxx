#include <iostream>
#include <fstream>

#include "parser.h"
#include "automata.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Dae precisa do arquivo com os roles\n";
	} else {
		Parser parser(argv[1]);
		parser.parseFile();
		Automata automata(parser.getAxiom(), parser.getRules(), parser.getIterations());
		automata.run();
	}
	return 0;
}