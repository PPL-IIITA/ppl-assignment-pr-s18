#ifndef BOY_H
#define BOY_H
#include"girl.h"
using namespace std;
	/*!\brief CLASS BOY
	 *containing attributes and member function of boys
	 */

class Boy {
	
	public:
		int commited;   //!< to check whether boy is commited or not
		int status;     //!< out of the three categories, which type of BOY ((1)MISER,(2)GENEROUS,(3)GEEKS)
		char name_id[7];//!< name of boy
		int atr;        //!< Attraction level out of 10
		int intl;       //!< Intelligence level out of 10
		int budget;     //!< Budget of each boy
		int min_atr;    //!< Minimum attraction level of girl required to get commited
		int happiness;  //!< Happiness of each boy
	public:
		void find_happiness (int tot_cost, Girl girl); //!< Function to find happiness of each commited boy
};
#endif
