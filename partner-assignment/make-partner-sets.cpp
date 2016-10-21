#include <iostream>

#include <vector>
#include <unordered_map>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"

/* helper functions */
static void print_p_set(const size_t_vec& pset, const std::vector<s_vec>& combos);
static void reset_used(std::unordered_map<std::string, bool>& used);
static bool unusable_partners(const s_vec& group, std::unordered_map<std::string, bool>& used);

void make_partner_sets(const s_vec& all_students, const std::vector<s_vec>& combos) {

	/* track which students are already in the set */
	std::unordered_map<std::string, bool> used;
	for (const auto& s : all_students)
		used[s] = false;

	/* keep track of the combos that have been used already */
	std::vector<bool> used_combos(combos.size(), false);

	/* storage for the current set, each element
	 	refers to an element in combos. */
	size_t_vec partner_set;

	size_t i, in_set, n_combos_used;
	in_set = n_combos_used = 0;
	i = -1;

	while ( n_combos_used < combos.size() ) {

		while ( ++i < combos.size() && in_set < all_students.size() ) {

			if (used_combos[i] || unusable_partners(combos[i], used))
				continue;

			for (const auto& s : combos[i])
				used[s] = true;

			in_set += combos[i].size();

			partner_set.push_back( i );

			used_combos[i] = true;
			n_combos_used++;
		}

		print_p_set(partner_set, combos);
		partner_set.clear();

		reset_used(used);
		in_set = 0;
		i = -1;
	}
}

static void print_p_set(const size_t_vec& pset, const std::vector<s_vec>& combos) {
	std::cout << "A complete partner set: \n";
	for (const size_t& idx : pset) {
		std::cout << "\t";
		for (const auto& s : combos[idx]) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}

static void reset_used(std::unordered_map<std::string, bool>& used) {
	for (auto& p : used)
		p.second = false;
}

static bool unusable_partners(const s_vec& group, std::unordered_map<std::string, bool>& used) {
	for (const auto& s : group)
		if (used[s])
			return true;

	return false;
}
