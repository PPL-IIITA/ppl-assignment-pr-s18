#include <iostream>
#include <string>
#include <cmath>
#include "girl.h"
#include "boy.h"
#include "gift.h"
#include "girl_choosy.h"
#include "girl_normal.h"
#include "girl_desperate.h"
#include "boy_geeks.h"
#include "boy_generous.h"
#include "boy_miser.h"
#include "gift_essential.h"
#include "gift_luxury.h"
#include "gift_utility.h"

using namespace std;

	/*!\brief CLASS COUPLE
	 *containing attributes and member functions of couples
	 */

class Couple {
	public:
		Girl girl;		//!< Object of commited girl
		Boy boy;		//!< Object of commited Boy
		Gift gift_basket[100];	//!< Object Array of Gifts exchanged between a couple 
		int happiness;		//!< Happiness of couple
		int compatibility;	//!< Compatibility of couple
		
	public:
		void find_happiness (); //!< Function to find happiness of a couple
		void find_compatibility (); //!< Function to find compatibility of a couple
};
