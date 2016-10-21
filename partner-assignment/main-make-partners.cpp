/*
	main-make-partners.cpp
	@author Charles Bailey
	@version 0.0.1 10/21/16

	Description: *
*/

#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>

#include <vector>

#include <stdexcept>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"

int main(int argc, char **argv) {

	if (argc != 3) {
		std::cout << "[!] Usage: ./make-partner-sets <text file with students> <group size>\n";
		std::exit(1);
	}

	std::fstream fs;
	try {
		fs = std::fstream(argv[1], std::fstream::in);
	} catch (std::exception& e) {
		std::cout << "Something went wrong: " << e.what() << std::endl;
		std::exit(2);
	}

	const size_t group_size = std::stoi(std::string(argv[2]));

	s_vec students;
	std::string tmp_student;
	while(std::getline(fs, tmp_student))
		students.push_back(tmp_student);

	fs.close();

	std::vector<s_vec> combos;
	size_t_vec partners;
	generate_partners(students, partners, 0, 0, group_size, combos);
	make_partner_sets(students, combos);

	return 0;
}
