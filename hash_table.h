#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "implement.h"
	/*!\brief CLASS HASH Inherits Implement
	 *containing member function to implement method 3 of ques 7
	 */
class Hash:public Implement {
	public:
		int H[50];		//!< Hash Table
	public:
		/** @brief Allocate all variables according to passed values when Hash object is created
 		*
	 	*/
		Hash(int k, Couple cl[50]);
		void make_table (int kb, Boy b[50]);	//!< makes hash table foe method3 implementation
		int method3 (int i);			//!< member function to implement method 3 of ques 7
};
#endif
