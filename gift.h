#ifndef GIFT_H
#define GIFT_H
using namespace std;

	/*!\brief CLASS GIFT
	 *containing attributes of all Gifts
	 */

class Gift {
	public:
		int value;		//!< Value of each gift out of 100
		int price;		//!< Price of each gift
		int type;		//!< Type of Gift (1)ESSENTIAL 2)LUXURY 3)UTILITY)
		int is_selected;	//!< to check whether that gift has been exchanged between a couple or not
		int lux_rate;		//!< Luxury rating of Luxury gift out of 5, -1 otherwise
		int lux_difficulty;	//!< Difficulty to obtain LUXURY gift out of 10, -1 otherwise
		int utl_value;		//!< Utility value of UTILITY gift out of 100, -1 otherwise
		int utl_class;		//!< Utility class of UTILITY gift out of 10, -1 otherwise
};
#endif
