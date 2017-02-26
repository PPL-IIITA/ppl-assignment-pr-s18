#include <iostream>
#include <cmath>
#include <stdio.h>
#include "girl.h"
using namespace std;

void Girl::find_happiness (int tot_cost, int tot_value) {
	if (status == 0) {
		happiness = log(1 + ((int)((tot_cost - man_cost)%10)));
	}
	else if (status == 1) {
		happiness = (tot_cost - man_cost)+tot_value;
	}
	else if (status == 2) {
		happiness = exp((int)((tot_cost - man_cost)%10));
	}
}	 
