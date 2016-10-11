#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>

#include <vector>

#include <stdexcept>

#define PARTNER_LEN 2

void
generate_partners(const std::vector<std::string>& classmates,
	std::vector<size_t>& partners, const size_t& start,
	const size_t& idx, const size_t& len)
{
	//printf("generate_partners(classmates, partners, start = %i, idx = %i, len = %i)\n", start,idx,len);

	if (len <= 0) return; /* return if we don't need any more people */

	for (size_t i = start; i < classmates.size(); i++) {
		partners[idx] = i;
 		//printf("partners[%i] = %s\n", idx, partners[idx].c_str());
		generate_partners(classmates, partners, i+1, idx+1, len-1);
	}
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "[!] Usage: ./partner-assignment <text file with partners>\n";
		exit(1);
	}

	std::fstream fs;
	try {
		fs = std::fstream(argv[1], std::fstream::in);
	} catch (std::exception& e) {
		std::cout << "Something went wrong: " << e.what() << std::endl;
		exit(2);
	}

	std::vector<std::string> students;
	std::string tmp_student;
	while(std::getline(fs, tmp_student))
		students.push_back(tmp_student);

	fs.close();

	std::vector< size_t > group;
	for (size_t i = 0; i < students.size(); i++) {
		group = std::vector<size_t>(PARTNER_LEN);

		generate_partners(students, group, i, 0, PARTNER_LEN);

		for (auto& p : group) {
			std::cout << students[p] << " ";
		}
		std::cout << std::endl;

	}
}
