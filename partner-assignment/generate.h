/*
	generate.h
*/
#ifndef GENERATE_H
#define GENERATE_H

#include "typedefs.h"
#include <vector>
#include <string>

/*
	generate_partners

	@param classmates is a vector of strings denoting the total
	class of students.

	@param partners is a vector of indexes that holds the current
	combination set. Each element in partners represents an index
	in classmates.

	@param start the starting index in partners. A user should always
	make this parameter 0.

	@param idx the current index in partners. A user should also
	always make this paramter 0.

	@param len the desired length of a partner set.

	@param combos a vector of string vectors that will hold
	all the sets of partners.
*/
void
generate_partners(const s_vec& classmates, size_t_vec& partners,
	const size_t& start, const size_t& idx, const size_t& len, std::vector<size_t_vec>& combos);

#endif
