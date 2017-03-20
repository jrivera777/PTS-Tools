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

set_of_partner_sets make_partner_sets(const s_vec& all_students, const std::vector<size_t_vec>& combos) {

	/* build out an incidence matrix. */
	incidence_matrix m( combos.size(), matrix_row(all_students.size() , false) );
	for (size_t i = 0 ; i < m.size() ; i++ ) {
		for (size_t j = 0 ; j < m[i].size() ; j++ ) {
			m[i][j] = combos[i].end() != std::find(combos[i].begin(), combos[i].end(), j);
		}
	}

	/* available rows will track which sets have been used. */
	std::vector<bool> avail_sets(combos.size(), true);

	/* round_solution is passed by reference to algo_x
	   and holds, upon being returned from the algorithm,
	   a valid, unique set of partners. */
	std::vector<size_t> round_solution;

	/*
		This'll hold all the solutions for returning.
	*/
	set_of_partner_sets solutions;

	/* Go through the n-1 available, unique
	   partner sets, keep track of the sets used,
	   and relay the results. */
	while (true) {

		/* get rid of last round's solution if there is one. */
		round_solution.clear();

		/* call the algorthm */
		algo_x( m , avail_sets , std::vector<bool>{} , round_solution);

		if (round_solution.size() == 0)
			break;

		/* print out the partner set and
		   *ensure* that the sets will
		   not be used again later. */
		// std::cout << "Partner Set: \n";
		// for (const size_t& set : round_solution) {
		// 	avail_sets[set] = false; /* this line "deletes" the set from combos*/
		// 	std::cout << "\t";
		// 	for (const size_t& s : combos[set])
		// 		std::cout << all_students[s] << " ";
		// 	std::cout << std::endl;
		// }

		solutions.push_back(std::vector<std::vector<std::string>>());
		for (const size_t& set : round_solution) {
			avail_sets[set] = false;
			solutions.back().push_back(std::vector<std::string>());
			for (const size_t& s : combos[set]) {
				solutions.back().back().push_back(all_students[s]);
			}
		}
	}

	return solutions;
}
