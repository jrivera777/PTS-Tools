#ifndef ALGO_X_H
#define ALGO_X_H

	#include <iostream>

	#include <vector>

	#include <algorithm>
	#include <limits>

	#include "typedefs.h"

	/*
		algo_x: A slightly-modified Knuth's Algorithm X.
		https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X

		@param m, an incidence matrix representing which
		sets hold a certain item.

		@param available_rows a boolean vector representing
		which rows are avaiable to algo_x in the generation
		of an exact cover.

		@param available_cols a boolean vector representing
		which columns are available to algo_x in the generation
		of an exact cover.

		@param p_solution the current partial solution of the
		algorithm on this step. It can be passed as a reference
		because algo_x will resize it when backtracking. This avoids
		unnecessary copying and allows the caller to access the solution
		upon completion.
	*/
	bool
	algo_x(const incidence_matrix& m, std::vector<bool> available_rows,
	    std::vector<bool> available_cols, std::vector<size_t>& p_solution);

#endif
