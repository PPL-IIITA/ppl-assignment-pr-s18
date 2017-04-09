#ifndef SELECT2_H
#define SELECT2_H
#include "giftSelector.h"
#include "gift.h"
	/*!\brief CLASS SELECT2 inherits CLASS GIFTSELECTOR
	 *containing attributes and member function for way 2 of ques 8
	 */
class Select2:public giftSelector {
	public:
		Gift cpgift[100][100];		//!< 2D gift array to store gifts exchanged between couples a/c to method 1
	public:
		/** @brief Allocate all variables according to passed values when Select2 object is created
 		*
	 	*/
		Select2 (int kcc, Couple cl[50]);
		void way2 (Gift gift[100], int ngf);		//!< method 2 of ques 8
};
#endif
