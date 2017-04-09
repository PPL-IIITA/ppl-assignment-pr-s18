#ifndef IMPLEMENT_H
#define IMPLEMENT_H
#include "fill_data.h"
	/*!\brief CLASS Implement
	 *containing member function to implement ques 7
	 */
class Implement {
	public:
		int kc;		//!<number of couples
		Couple cpl[50];	//!<couple array
	public:
		void generate_boy_couple(Boy boy[], Boy b[], Couple c[], int n, int nb, int *kb);//!< picks various boys and set couple array
		void generate_method (int kb, int m[]);						 //!< generate mode array to select method
		

};
#endif
