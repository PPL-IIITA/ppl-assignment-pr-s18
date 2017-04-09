#include <iostream>
#include <stdio.h>
#include "implement.h"
#include "make_pair.h"
#include "hash_table.h"
#include "array.h"
#include "sorted_array.h"

int main() {
	int m[50];
	Boy boy[50];
	int kb = 0, nb;
	FILE *f;
	f = fopen ("boy_list.txt", "r");
	fscanf (f, "%d", &nb);
	fclose (f);
	Pair p;
	Implement ipl;
	ipl.generate_boy_couple (boy, p.boy, p.cp, p.k, nb, &kb);
	ipl.generate_method (kb, m);
	int temp = 0;
	Array ar(ipl.kc, ipl.cpl);
	SortedArray sa(ipl.kc, ipl.cpl);
	Hash h(ipl.kc, ipl.cpl);
	h.make_table(kb, boy);
	freopen ("ques7.txt", "w", stdout);
	for (int i = 1; i < kb; i++) {
		if (m[i] == 0) {
			temp = ar.method1(boy[i]);
		}
		else if (m[i] == 1) {
			temp = sa.method2(boy[i]);
		}
		else {
			temp = h.method3(i);
		}
		if (temp == -1) {
			printf ("%s: No Girlfriend\n", boy[i].name_id);
		}
		else {
			printf ("%s: %s\n", boy[i].name_id, p.cp[temp].girl.name_id);
		}
	}
	return 0;
}
