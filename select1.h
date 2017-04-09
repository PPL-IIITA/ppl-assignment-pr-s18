#ifndef SELECT1_H
#define SELECT1_H
#include "giftSelector.h"
#include "gift.h"
	/*!\brief CLASS SELECT1 inherits CLASS GIFTSELECTOR
	 *containing attributes and member function for way 1 of ques 8
	 */
class Select1:public giftSelector {
	public:
		Gift cpgift[100][100];		//!< 2D gift array to store gifts exchanged between couples a/c to method 1
	public:
		/** @brief Allocate all variables according to passed values when Select1 object is created
 		*
	 	*/
		Select1 (int kcc, Couple cl[50]);
		void way1 (Gift gift[100], int ngf);		//!< method1 of ques 8
};
#endif
