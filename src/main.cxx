#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Dae precisa do arquivo com os roles\n";
	} else {
		std::cout << "O arquivo é " << argv[1] << "\n";
	}
	return 0;
}