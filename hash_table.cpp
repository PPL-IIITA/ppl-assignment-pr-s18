#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include "hash_table.h"

Hash::Hash(int k, Couple cl[50]) {
	int i;
	kc = k;
	for (i = 0; i < kc; i++) {
		cpl[i] = cl[i];
	}
	
}

void Hash::make_table(int kb, Boy b[50]) {
	int i, j;
	for (i = 0; i < kb; i++) {
		H[i] = -1;
	}
	for (i = 0; i < kb; i++) {
		for (j = 0; j < kc; j++) {
			if (strcmp(cpl[j].boy.name_id, b[i].name_id) == 0) {
				H[i] = j;
			}
		}
	}
}
int Hash::method3(int i) {
	
	return H[i];
}
