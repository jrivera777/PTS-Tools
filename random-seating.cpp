#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>
#include <time.h>

#include <vector>
#include <map>

#include <stdexcept>

std::vector<std::string>
get_neighbors(const std::vector<std::string>& pop, const int& idx) {
	if (pop.empty())
		throw std::invalid_argument("An empty vector cannot yield neighbors.");
	else if (pop.size() == 1)
		return std::vector<std::string>{""};
	else if (idx < 0 || idx >= pop.size())
		throw std::out_of_range("idx is out of the range of pop");

	if ( idx == 0 )
		return std::vector<std::string>{ pop[idx+1], pop.back() };
	else if ( idx == pop.size()-1 )
		return std::vector<std::string>{ pop.front(), pop[idx-1] };

	return std::vector<std::string>{ pop[idx-1], pop[idx+1] };
}

void
shuffle_and_verify(std::vector<std::string>& pop,
	std::map<std::string, std::vector<std::string>>& neighbors)
{
	int i, n, j;
	for (i = pop.size()-1, n = pop.size(); i >= 0; i--) {
		j = rand() % n;
		std::swap(pop[i], pop[j]);
	}


	bool changes = true;
	while (changes) {
		changes = false;
		for (i = 1, n = pop.size(); i < n; i++) {
			if ( std::find(neighbors[pop[i]].begin(), neighbors[pop[i]].end(), pop[i-1]) != neighbors[pop[i]].end() ) {

				do {
					j = rand() % n;
				} while (j == i-1 || j == i);

				std::swap(pop[i], pop[j]);

				changes = true;
			}
		}
	}
}

int main(int argc, char **argv) {
	srand(time(NULL));

	if (argc != 2) {
		std::cout << "Usage: ./random-seating [seating file]\n";
		exit(1);
	}

	std::fstream fs;
	try {
		fs = std::fstream(argv[1], std::fstream::in);
	} catch (...) {
		std::cout << "Could not open " << std::string(argv[1]) << std::endl;
		exit(2);
	}

	std::vector<std::string> students_orig;
	std::string tmp;
	while(std::getline(fs, tmp)) {
		students_orig.push_back(tmp);
	}

	/* close file stream*/
	fs.close();

	if (students_orig.size() <= 1) {
		std::cout << "Not enough students to shuffle.\n";
		exit(3);
	}

	std::map<std::string, std::vector<std::string> > neighbors;
	for (int i = 0; i < students_orig.size(); i++)
		neighbors[ students_orig[i] ] = get_neighbors(students_orig, i);

	std::vector<std::string> students_new = students_orig;
	shuffle_and_verify(students_new, neighbors);

	for (int i = 0; i < students_new.size(); i++)
		std::cout << i+2 << "|\t" << students_new[i] << std::endl;
}