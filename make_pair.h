#ifndef MAKE_PAIR_H
#define MAKE_PAIR_H
#include "couple.h"

using namespace std;
	/*!\brief CLASS PAIR
	*containing attributes of couples formed
	*/

class Pair {
	public:
		int k;		//!< Number of couples
		Couple cp[100];	//!< Object Array of Couple
		
	public:
		/** @brief Allocate boyfriends to all girls when Pair object is created
 		*
		* Reads the data of girls from girl_list.txt
		* Reads the data of boys from boy_list.txt
		* Couples are formed in the same order as given in the input, and store them in cp array of Pair class
	 	*/
		Pair();				//!< Constructor on calling will result in pair formation on the basis of input
		/** @brief Gift baskets of all couples are formed on the basis of all restrictions and are stored in gift_basket array of couple class 
 		*
	 	*/
		void make_gift_basket (); 	//!< Function to make gift basket for couple
		/** @brief Find Happiness and compatibility of all couples so formed in cp array of Pair class
 		*
	 	*/
		void find_happiness_comp ();	//!< Function to find happiness and compatibility of a couple
		/** @brief Print the gift basket of all couples along with the type of gift
 		*
	 	*/
		void print_gift ();		//!< Print the gifts exchanged between a couple

};
#endif
