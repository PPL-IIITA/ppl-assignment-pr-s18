#include <iostream>
#include <cmath>
#include "girl.h"
#include "boy.h"
//#include "gift.h"
#include "couple.h"

void Couple::find_happiness () {
	happiness = (girl.happiness) + (boy.happiness);
}
void Couple::find_compatibility () {
	compatibility = (boy.budget-girl.man_cost) + abs (girl.intl - boy.intl) + abs (girl.atr - boy.atr);
}
