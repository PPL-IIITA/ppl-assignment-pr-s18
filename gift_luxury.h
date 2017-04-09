#ifndef GIFT_LUXURY_H
#define GIFT_LUXURY_H
#include "gift.h"
	/*!\brief CLASS LUXURY inherits CLASS GIFT
	*containing attributes of Luxury gifts formed
	*/
class Luxury : public Gift {
	public:
		int lux_rate;		//!< Luxury rating of Luxury gift out of 5
		int lux_difficulty;	//!< Difficulty to obtain LUXURY gift out of 10
		/** @brief Allocate all variables according to passed values when Luxury object is created
 		*
		* Initial Selection of all is zero
	 	*/
		Luxury (int prc, int val, int l_rate, int l_difficulty) {
			type = 1;
			price = prc;
			value = val;
				lux_rate = l_rate;
			lux_difficulty = l_difficulty; 
			is_selected = 0;
		}

};
#endif
