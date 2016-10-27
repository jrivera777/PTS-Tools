/*
	main-make-partners.cpp
	@author Charles Bailey
	@version 0.0.1 10/22/16

	Description: This program will generate sets of
	partners that do not overlap. Thus, it generates
	arrangements of partners that never repeat, and it
	generates as many of these as it can.
*/

#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>
#include <time.h>

#include <vector>

#include <stdexcept>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"

static void readfile(std::fstream& fs, s_vec& students);
static void shuffle(s_vec& vec);

int main(int argc, char **argv) {
	srand(time(NULL));

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

	s_vec students;
	readfile(fs, students);
	fs.close();

	shuffle(students);

	const size_t group_size = std::stoi(std::string(argv[2]));

	std::vector<size_t_vec> combos;
	size_t_vec partners(group_size);

	generate_partners(students, partners, 0, 0, group_size, combos);

	if (students.size() % group_size != 0) {
		partners.resize( students.size() % group_size );
		generate_partners(students, partners, 0, 0, students.size() % group_size, combos);
	}

	make_partner_sets(students, combos);

	return 0;
}

static void readfile(std::fstream& fs, s_vec& students) {
	std::string tmp_student;
	while(std::getline(fs, tmp_student))
		students.push_back(tmp_student);
}

static void shuffle(s_vec& vec) {
	for (int i = vec.size()-1, rand_idx; i >= 0; i--) {
		rand_idx = rand() % vec.size();
		std::swap( vec[ i ] , vec[ rand_idx ] );
	}
}
