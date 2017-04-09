#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "giftSelector.h"

void giftSelector::set_values (int kcc, Couple cl[50]) {
	for (int i = 0; i < kcc; i++) {
		cp[i] = cl[i];
	}
	k = kcc;
}

void giftSelector::generate_method(int m[50]) {
	int i;
	for (i = 0; i < k; i++) {
		m[i] = rand()%2;
	}
}


