#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "implement.h"

void Implement::generate_boy_couple (Boy boy[50], Boy b[50], Couple c[50], int n, int nb, int *kb) {
	int is[nb+1];
	int i;
	int t = 0;
	for (i = 0; i < nb; i++) {
		is[i] = rand()%2;
	}
	for (i = 0; i < nb; i++) {
		if (is[i]) {
			boy[t] = b[i];
			t++;
		}
	}
	*kb = t;
	for (i = 0; i < n; i++) {
		cpl[i] = c[i];
	}
	kc = n;
}

void Implement::generate_method(int kb, int m[50]) {
	int i;
	for (i = 0; i < kb; i++) {
		m[i] = rand()%3;
	}
}


