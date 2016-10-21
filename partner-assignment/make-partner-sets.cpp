#include <iostream>

#include <vector>
#include <unordered_map>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"

static void print_p_set(const std::vector<s_vec>& pset);
static void reset_used(std::unordered_map<std::string, bool>& used);

void make_partner_sets(const s_vec& all_students, std::vector<s_vec> combos) {

	std::unordered_map<std::string, bool> used;
	for (const auto& s : all_students)
		used[s] = false;

	std::vector<s_vec> partner_set;
	size_t i, in_set; bool usable;

	i = in_set = 0;
	while ( !combos.empty() ) {

		while ( i < combos.size() && in_set < all_students.size() ) {

			usable = true;
			for (const auto& s : combos[i]) {
				if (used[s]) {
					usable = false;
					break;
				}
			}

			if (!usable) {
				i++;
				continue;
			}

			for (const auto& s : combos[i])
				used[s] = true;

			in_set += combos[i].size();

			partner_set.push_back( std::move( combos[ i ] ) );

			combos.erase( combos.begin() + i );
		}
		print_p_set(partner_set);
		partner_set.clear();

		reset_used(used);
		i = in_set = 0;
	}
}

static void print_p_set(const std::vector<s_vec>& pset) {
	std::cout << "A complete partner set: \n";
	for (const s_vec& group : pset) {
		std::cout << "\t";
		for (const auto& s : group) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}

static void reset_used(std::unordered_map<std::string, bool>& used) {
	for (auto& p : used)
		p.second = false;
}
