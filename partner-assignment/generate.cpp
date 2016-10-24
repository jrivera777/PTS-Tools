/*
	generate.cpp
	@author Charles Bailey
	@version 0.0.2 10/22/16

	Description: this routine generates all
	possible sets of partners of a given group
	for a given set size.
*/
#include <algorithm>
#include <iostream>

#include <vector>
#include <string>

#include "typedefs.h"
#include "generate.h"

void
generate_partners(const s_vec& classmates, size_t_vec& partners,
	const size_t& start, const size_t& idx, const size_t& len, std::vector<size_t_vec>& combos)
{
	if (idx >= len) {
		combos.push_back(partners);
		return;
	}

	for (size_t i = start; i < classmates.size(); i++) {
		partners[idx] = i;
		generate_partners(classmates, partners, i+1, idx+1, len, combos);
	}
}
