#ifndef GIRL_H
#define GIRL_H
using namespace std;
	/*!\brief CLASS GIRL
	 *containing attributes and member function of girls
	 */

class Girl {
	
	public:
		int commited;    //!< to check whether girl is commited or not
		int status;	 //!< out of the three categories, which type of BOY ((1)CHOOSY,(2)NORMAL,(3)DESPERATE)
		char name_id[9]; //!< name of girl
		int atr;	 //!< Attraction level of girl out of 10
		int intl;	 //!< Intelligence level of girl out of 10
		int man_cost;    //!< maintenance cost of each girl
		int criteria;    //!< criteria for which boy to choose (1) Most Attractive 2) Most Rich 3) Most Intelligent)
		int happiness;   //!< Happiness of each girl
		
	public:
		void find_happiness (int tot_cost, int tot_value); //!< Function to find happiness of each commited Girl
};
#endif
