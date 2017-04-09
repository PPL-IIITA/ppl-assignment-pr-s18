#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H
#include "implement.h"
	/*!\brief CLASS SORTEDARRAY Inherits Implement
	 *containing member function to implement method 2 of ques 7
	 */
class SortedArray:public Implement {
	public:
		Couple coupl[50];	//!< Couple array which will later be sorted
		/** @brief Allocate all variables according to passed values when SortedArray object is created
 		*
	 	*/
		SortedArray(int k, Couple cl[50]);
		int method2(Boy b);	//!< member function to implement method 2 of ques 7
};
#endif
