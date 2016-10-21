#ifndef GENERATE_H
#define GENERATE_H

#include "typedefs.h"
#include <vector>
#include <string>

void
generate_partners(const s_vec& classmates, size_t_vec& partners,
	const size_t& start, const size_t& idx, const size_t& len, std::vector<s_vec>& combos);

#endif
