#include "boy.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS GENEROUS inherits CLASS BOY
	*containing attributes of Generous boy formed
	*/
class Generous : public Boy {
	public :
		/** @brief Allocate all variables according to passed values when Generous object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Generous (char *nname, int natr, int nintl, int nbudget, int nmin_atr) {
			status = 1;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			budget = nbudget;
			min_atr = nmin_atr;
			commited = 0;
		}	
};
