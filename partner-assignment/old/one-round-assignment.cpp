/*
	partner-list-generator.cpp
	@author Charles Bailey
	@version 0.0.1 10/11/16

	Description: this program will generate
	a single, complete round of partners. It expects
	a text file with the names of students, or
	some other (unique) student-identifying information.
*/

#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>
#include <time.h>

#include <vector>

#include <stdexcept>

#include "../typedefs.h"

void shuffle(s_vec& students);

void print_partners(const s_vec& students, const size_t& group_size);

int main(int argc , char **argv){
	srand(time(NULL));

	if (argc != 3) {
		std::cout << "[!] Usage: ./one-round-assignment <text file with students> <group size>\n";
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

	std::cout << "[*] Shuffling...\n";
	shuffle(students);
	std::cout << "[*] Shuffled!\n";

	print_partners(students, group_size);

	return 0;
}

void shuffle(s_vec& students) {
	int rand_idx;
	for (int i = students.size() - 1; i >= 0; i--) {
		rand_idx = rand() % students.size();
		std::swap(students[i], students[rand_idx]);
	}
}

void print_partners(const s_vec& students, const size_t& group_size) {
	for (size_t i = 0; i < students.size(); i++) {
		std::cout << students[i]
			<< ((i+1) % group_size == 0 ? "\n" : " ");
	}
	std::cout << std::endl;
}
