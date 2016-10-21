#include <algorithm>
#include <iostream>

#include <vector>
#include <string>

#include "typedefs.h"
#include "generate.h"

void
generate_partners(const s_vec& classmates, size_t_vec& partners,
	const size_t& start, const size_t& idx, const size_t& len, std::vector<s_vec>& combos)
{
	if (idx >= len) {
		s_vec tmp;
		for (const auto& i : partners)
			tmp.push_back(classmates[i]);

		combos.push_back(tmp);

		return; /* return bcs we don't need any more people */
	}

	for (size_t i = start; i < classmates.size(); i++) {
		partners[idx] = i;

		generate_partners(classmates, partners, i+1, idx+1, len, combos);
	}
}
