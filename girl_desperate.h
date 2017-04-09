#include "girl.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS DESPERATE inherits CLASS GIRL
	*containing attributes of desperate girl formed
	*/
class Desperate : public Girl {
	public :
		/** @brief Allocate all variables according to passed values when Desperate object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Desperate (char *nname, int natr, int nintl, int nman_cost, int ncriteria) {
			status = 2;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			man_cost = nman_cost;
			criteria = ncriteria;
			commited = 0;		
		}	
};
