#pragma once
#include <cstddef>
#include <string>
#include <unordered_map>
#include <ostream>


enum class OPD_SZ{
	NO_OPD = 0,
	BYTE = 1, 
	WORD = 2, 
	DWORD = 4,
};

using mnem_list = std::unordered_map<size_t, std::string>;

struct entry_dtor {
	std::string mnem;
	OPD_SZ opd_sz = OPD_SZ::NO_OPD;
	bool two_byte = 0;
	bool aux_byte = 0;
	mnem_list *decs_table = nullptr;
	mnem_list *units_table = nullptr;
};

using opcode_table = std::unordered_map<size_t, entry_dtor>;

std::ostream& operator<< (std::ostream &out, const OPD_SZ& op);

extern opcode_table octal;
extern mnem_list dtors;
extern opcode_table octal_twobyte;

void print_oct_as_hex(size_t oct);
size_t print_next_oct_as_hex ();
void print_opd (OPD_SZ width);