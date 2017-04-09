#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include "array.h"

Array::Array(int k, Couple cl[50]) {
	int i;
	kc = k;
	for (i = 0; i < kc; i++) {
		cpl[i] = cl[i];
	}
	
}

int Array::method1(Boy b) {
	int i;
	int flag = 0;
	for (i = 0; i < kc; i++) {
		//printf ("hello\n");
		if (strcmp(cpl[i].boy.name_id, b.name_id) == 0) {
			return i;
		}
	}
	return -1;
}
