#include "girl.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS NORMAL inherits CLASS GIRL
	*containing attributes of normal girl formed
	*/
class Normal : public Girl {
	public :
		/** @brief Allocate all variables according to passed values when Normal object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Normal (char *nname, int natr, int nintl, int nman_cost, int ncriteria) {
			status = 1;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			man_cost = nman_cost;
			criteria = ncriteria;
			commited = 0;
		
		}	
};
