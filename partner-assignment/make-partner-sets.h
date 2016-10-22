/*
	make-partner-sets.h
*/
#ifndef MPARTNER_SETS_H
#define MPARTNER_SETS_H

#include "typedefs.h"

/*
	make_partner_sets generates an incidence matrix
	using all_students and combos that is then passed
	to algo_x to form an exact cover, creating a unique
	set of partners including each and every student in
	all_students *exactly once*.

	@param all_students a string vector containing all students.
	@param combos a vector of string vectors holding all possible
	sets of partners.
*/
void make_partner_sets(const s_vec& all_students, const std::vector<s_vec>& combos);

#endif
