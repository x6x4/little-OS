#include "oct_disasm_utils.h"
#include <cstddef>
#include <iostream>
#include <iomanip>


int parser () {
	unsigned opcode;
	while (std::cin >> opcode) {
		if (auto elm = octal.find(opcode); elm != octal.end()) {

			if (!elm->second.two_byte) {
				if (elm->second.aux_byte) {
					std::cin >> opcode;
					size_t decs = (opcode%100)/10;
					std::cout << elm->second.decs_table->find(decs)->second << ' ';
				} else {
					std::cout << elm->second.mnem << ' ';
				}
				print_opd(elm->second.opd_sz);
			}
			else {
				std::cin >> opcode;
				
				if (auto elm = octal_twobyte.find(opcode); elm != octal.end()) {
					if (elm->second.aux_byte) {
						if (!elm->second.mnem.empty()) {
							std::cout << elm->second.mnem << ' ';
							std::cin >> opcode;
							size_t decs = (opcode%100)/10;
							size_t units = opcode%10;
							std::cout << elm->second.units_table->find(units)->second << ", ";
							std::cout << elm->second.decs_table->find(decs)->second << ' ';
						} else {
							std::cin >> opcode;
							size_t decs = (opcode%100)/10;
							std::cout << elm->second.decs_table->find(decs)->second << ' ';
						}
						
						print_opd(elm->second.opd_sz);
					}	
				}
			}
			std::cout << std::endl;

		} else continue;

	}	
    return 0;	
}

int main () {
	parser();
}
