#include <iostream>
#include <fstream>
#include <cstdio>

#include <algorithm>
#include <time.h>

#include <vector>
#include <map>

#include <stdexcept>

void
get_good_shuf(std::vector<size_t>& arr, const size_t& len)
{
	arr.resize(len);
	int i, n, j;
	for (i = 0, n = arr.size(); i < n; i++)
		arr[i] = i;

	for (i = arr.size()-1, n = arr.size(); i >= 0; i--)
		std::swap(arr[i], arr[ rand() % n ]);

	if (len <= 3) return;

	bool changes = true;
	while (changes) {
		changes = false;
		for (i = 1, n = arr.size(); i < n; i++) {
			if ( std::abs(arr[i-1] - arr[i]) <= 1 ) {

				do {
					j = rand() % n;
				} while (j == i-1 || j == i);

				std::swap(arr[i], arr[j]);
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

	std::vector<size_t> arr;
	get_good_shuf(arr, students_orig.size());

	for (size_t i = 0; i < arr.size(); i++)
		std::cout << i+2 << "|\t" << students_orig[arr[i]] << std::endl;
}
