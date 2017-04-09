#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include "sorted_array.h"

SortedArray::SortedArray(int k, Couple cl[50]) {
	int i;
	kc = k;
	for (i = 0; i < kc; i++) {
		cpl[i] = cl[i];
	}
	
}

int SortedArray::method2(Boy b) {
	int i, j;
	for (i = 0; i < kc; i++) {
		coupl[i] = cpl[i];
	}
	for (i = 0; i < kc; i++) {
		for (j = 0; j < kc-1; j++) {
			if (strcmp(coupl[j].boy.name_id, coupl[j+1].boy.name_id) > 0) {
				Couple temp = coupl[j];
				coupl[j] = coupl[j+1];
				coupl[j+1] = temp;
			}
		}
	}
	int l, r, mid;
	l = 0;
	r = kc-1;
	while (l <= r) {
		mid = (l+r)/2;
		if (strcmp(coupl[mid].boy.name_id, b.name_id) > 0) {
			r = mid-1;
		}
		else if (strcmp(coupl[mid].boy.name_id, b.name_id) < 0) {
			l = mid+1;
		}
		else {
			return mid;
		}
		
	}
	return -1;
}
