/*
	make-partner-sets.cpp
	@author Charles Bailey
	@version 0.0.1 10/22/16

	Description: This program converts the combinatins
	into an incidence matrix, which is then passed off
	to a slightly tweaked version of Algorithm X.
*/

#include <iostream>

#include <vector>
#include <unordered_map>

#include "typedefs.h"
#include "generate.h"
#include "make-partner-sets.h"
#include "algo-x.h"

void make_partner_sets(const s_vec& all_students, const std::vector<s_vec>& combos) {

	/* build out an incidence matrix. */
	incidence_matrix m( combos.size(), matrix_row(all_students.size() , false) );
	for (size_t i = 0 ; i < m.size() ; i++ ) {
		for (size_t j = 0 ; j < m[i].size() ; j++ ) {
			m[i][j] = combos[i].end() != std::find(combos[i].begin(), combos[i].end(), all_students[j]);
		}
	}

	/* available rows will track which sets have been used. */
	std::vector<bool> avail_sets(combos.size(), true);

	/* round_solution is passed by reference to algo_x
	   and holds, upon being returned from the algorithm,
	   a valid, unique set of partners. */
	std::vector<size_t> round_solution;

	/* Go through the n-1 available, unique
	   partner sets, keep track of the sets used,
	   and relay the results. */
	for (size_t i = 0; i < all_students.size(); i++) {

		/* get rid of last round's solution if there is one. */
		round_solution.clear();

		/* call the algorthm */
		algo_x( m , avail_sets , std::vector<bool>{} , round_solution);

		if (round_solution.size() == 0)
			break;

		/* print out the partner set and
		   *ensure* that the sets will
		   not be used again later. */
		std::cout << "Partner Set: \n";
		for (const size_t& set : round_solution) {
			avail_sets[set] = false; /* this line "deletes" the set from combos*/
			std::cout << "\t";
			for (const std::string& s : combos[set])
				std::cout << s << " ";
			std::cout << std::endl;
		}
	}
}
