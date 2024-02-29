#include "oct_disasm_utils.h"
#include <cstddef>
#include <iomanip>
#include <iostream>

std::ostream& operator<< (std::ostream &out, const OPD_SZ& op) {
	return out << static_cast<int>(op);
}

mnem_list arth = {
	{1, "or"}
};

opcode_table octal = 
{
	{350, {"call", OPD_SZ::WORD}}, 
 	{353, {"jmp",  OPD_SZ::BYTE}},
	{372, {"cli"}},
	{17,  {"",     OPD_SZ::NO_OPD, 1}},
    {303, {"ret"}},
    {146, {"[switch 16 to 32]"}},
    {203,  {"",     OPD_SZ::BYTE, 0, 1, &arth}}
};

mnem_list dtors = {
	{2, "lgdt"}
};

mnem_list cntl = {
    {0, "cr0"}
};

mnem_list gp = {
    {0, "eax"}
};

opcode_table octal_twobyte = 
{
	{1, {"", OPD_SZ::WORD, 0, 1, &dtors}},
    {40, {"mov", OPD_SZ::NO_OPD, 0, 1, &cntl, &gp}},
    {42, {"mov", OPD_SZ::NO_OPD, 0, 1, &gp, &cntl}}
};

void print_oct_as_hex(size_t oct) {
    size_t hex;
	std::istringstream(std::to_string(oct)) >> std::oct >> hex;
	std::cout << std::setfill('0') << std::setw(2) << std::hex << hex;	
}

size_t print_next_oct_as_hex () {
	size_t oct;
	std::cin >> oct;
	print_oct_as_hex(oct);

    return oct;
}

void print_opd (OPD_SZ width) {
	size_t opd_sz = static_cast<size_t>(width);

	for (size_t i = 0; i < opd_sz; i++) {
		print_next_oct_as_hex();
        std::cout << ' ';
	}
}