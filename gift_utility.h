#ifndef GIFT_UTILITY_H
#define GIFT_UTILITY_H
#include "gift.h"
	/*!\brief CLASS UTILITY inherits CLASS GIFT
	*containing attributes of Utility gifts formed
	*/
class Utility : public Gift {
	public:
		int utl_value;		//!< Utility value of UTILITY gift out of 100
		int utl_class;		//!< Utility class of UTILITY gift out of 10
		/** @brief Allocate all variables according to passed values when Utility object is created
 		*
		* Initial Selection of all is zero
	 	*/
		Utility (int prc, int val, int v, int c) {
			type = 2;
			price = prc;
			value = val;
			utl_value = v;
			utl_class = c;
			is_selected = 0;
		}

};
#endif
