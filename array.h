#ifndef ARRAY_H
#define ARRAY_H
#include "implement.h"
	/*!\brief CLASS ARRAY Inherits Implement
	 *containing member function to implement method 1 of ques 7
	 */
class Array:public Implement {
	public:
		/** @brief Allocate all variables according to passed values when Array object is created
 		*
	 	*/
		Array(int k, Couple cl[50]);
		int method1(Boy b);		//!< member function to implement method 1 of ques 7
};
#endif
