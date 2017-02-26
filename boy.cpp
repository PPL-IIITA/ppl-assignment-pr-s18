#include<iostream>
#include"boy.h"
#include"girl.h"
using namespace std;
//Function to find happiness of each type of boy
void Boy::find_happiness(int total_cost, Girl girl)  {
	if (status == 0) {
		happiness = budget - total_cost;
	}
	else if (status == 1) {
		happiness = girl.happiness;
	}
	else if (status == 2) {
		happiness = girl.intl;
	}
}
