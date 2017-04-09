#include "boy.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS MISER inherits CLASS BOY
	*containing attributes of Miser boy formed
	*/
class Miser : public Boy {
	public :
		/** @brief Allocate all variables according to passed values when Miser object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Miser (char *nname, int natr, int nintl, int nbudget, int nmin_atr) {
			status = 0;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			budget = nbudget;
			min_atr = nmin_atr;
			commited = 0;
		}	
};
