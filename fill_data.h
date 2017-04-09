#ifndef FILL_DATA_H
#define FILL_DATA_H
#include "couple.h"
	/*!\brief CLASS DATA
	*containing constructor and function to take data 
	*from various lists and store them into passed array
	*/
class Data {
	public:
		int nb;		//!< Number of boys
		int ng;		//!< Number of girls
		int n;		//!< Number of gifts
	public:
		/** @brief Allocate information of all boys and girls into array
 		*
		* Reads the data of girls from girl_list.txt
		* Reads the data of boys from boy_list.txt
		* and store them into boy and girl array passed
	 	*/
		Data(Boy boy[], Girl girl[]);		//!< Constructor on calling will result in transferring information of all girls and boys into array
		/** @brief Allocate information of all gifts into array
 		*
		* Reads the data of girls from gift_list.txt
		* and store them into gift array passed
	 	*/
		void gifting (Gift gift[]);		//!< Function to transfer information of all gifts into gift array

		/** @brief Allocate information regarding days on which gifting has to be performed and store it into an array
 		*
		* Randomly allocate days for gifting and count number of days allocated
	 	*/
		void Vdays (int day[], int *t);		//!< Function to randomly generate information regarding days on which gifting has to be done
};
#endif
