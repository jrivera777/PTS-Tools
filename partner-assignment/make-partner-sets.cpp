#include <iostream>

#include <vector>
#include <unordered_map>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"

void make_partner_sets(const s_vec& all_students, std::vector<s_vec> combos) {
	std::unordered_map<std::string, bool> used;
	for (const auto& s : all_students)
		used[s] = false;

	std::vector<s_vec> partner_set;
	int i; bool usable;
	while (!combos.empty()) {
		std::cout << "A complete partner set: \n";
		partner_set = std::vector<s_vec>{};

		i = 0;
		while (i < combos.size()) {
			usable = true;
			for (auto& s : combos[i]) {
				if (used[s]) {
					usable = false;
					break;
				}
			}
			if (!usable) {
				i++;
				continue;
			}

			partner_set.push_back(std::move(combos[i]));
			combos.erase( combos.begin() + i );

			for (auto& u : used) {
				if (!u.second) {
					usable = true;
					break;
				}
			}
			if (!usable)
				break;
		}
		for (auto& s : partner_set) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}

}
