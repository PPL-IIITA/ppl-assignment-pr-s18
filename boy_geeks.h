#include "boy.h"
#include <stdio.h>
#include <string.h>
	/*!\brief CLASS GEEK inherits CLASS BOY
	*containing attributes of Geek boy formed
	*/
class Geek : public Boy {
	public :
		/** @brief Allocate all variables according to passed values when Geek object is created
 		*
		* Initial Commitment of all is zero
	 	*/
		Geek (char *nname, int natr, int nintl, int nbudget, int nmin_atr) {
			status = 2;
			strcpy (name_id, nname);
			atr = natr;
			intl = nintl;
			budget = nbudget;
			min_atr = nmin_atr;
			commited = 0;	
		}	
};
