#include "girl.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS CHOOSY inherits CLASS GIRL
	*containing attributes of choosy girl formed
	*/
class Choosy : public Girl {
	public :
		/** @brief Allocate all variables according to passed values when Choosy object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Choosy (char *nname, int natr, int nintl, int nman_cost, int ncriteria) {
			status = 0;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			man_cost = nman_cost;
			criteria = ncriteria;
			commited = 0;
			
		}	
};
