/*
	partner-list-generator.cpp
	@author Charles Bailey
	@version 0.0.1 10/11/16

	Description: this program generates all possible
	combinations of a bunch of students into a certain
	size group. Any left-over students will be accounted
	for as well. Someone could run this program once and
	check it off as they go. At least, that is what this
	program is intended to do. Who really knows, right?
*/

#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>

#include <vector>

#include <stdexcept>

#include "typedefs.h"
#include "generate.h"

int main(int argc, char **argv) {

	if (argc != 3) {
		std::cout << "[!] Usage: ./partner-list-generator <text file with students> <group size>\n";
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

	size_t_vec group(group_size);
	generate_partners(students, group, 0, 0, group_size);

	/* since we may have extras, we need to generate padding groups: */
	if (students.size() % group_size != 0) {
		group = size_t_vec(students.size() % group_size);
		generate_partners(students, group, 0, 0, students.size() % group_size);
	}

	std::cout << "A class of size " << students.size() << " split into "
		<< students.size() / group_size << " groups of " << group_size
		<< " with " << students.size() % group_size << " students left over.\n";

	return 0;
}
