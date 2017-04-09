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
};
#endif
