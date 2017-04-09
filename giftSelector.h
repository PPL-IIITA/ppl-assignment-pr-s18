#ifndef GIFTSELECTOR_H
#define GIFTSELECTOR_H
#include "fill_data.h"
	/*!\brief CLASS GIFTSELECTOR
	 *containing attributes and member function for ques 8
	 */
class giftSelector {
	public:
		int k;			//!< number of couples
		Couple cp[50];		//!< Couple array
	public:
		
		void set_values (int kcc, Couple cl[50]);	//!< set attributes of this class
		void generate_method (int m[50]);		//!< generate mode of way selection for ques 8
};
#endif
