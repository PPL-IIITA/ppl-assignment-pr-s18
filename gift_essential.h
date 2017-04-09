#ifndef GIFT_ESSENTIAL_H
#define GIFT_ESSENTIAL_H
#include "gift.h"
	/*!\brief CLASS ESSENTIAL inherits CLASS GIFT
	*containing attributes of Essential gifts formed
	*/
class Essential : public Gift {
	public:
		/** @brief Allocate all variables according to passed values when essential object is created
 		*
		* Initial Selection of all is zero
	 	*/
		Essential (int prc, int val) {
			type = 0;
			price = prc;
			value = val;
			is_selected = 0;
		}

};
#endif
