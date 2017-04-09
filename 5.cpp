#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "make_new_pair.h"
using namespace std;

int main () {
	New_Pair p;
	p.make_new();
	int i ,j, k1, kc, cph, cpc, mcph = 20000, mcpc = 20000,cph1, cpc1;
	p.make_gift_basket();
	p.find_happiness_comp();
	//p.print_gift();
	k1 = p.k;
	cin >> kc;
	printf ("%d Happiest couples:\t\t\t%d Compatible couples:\n",kc, kc);
	for (i = 0; i < kc; i++) {
		cph = 0;
		cph1 = -1;
		cpc = 0;
		cpc1 = -1;
		for (j = 0; j < k1; j++) {
			if (p.cp[j].happiness > cph && p.cp[j].happiness < mcph) {
				cph = p.cp[j].happiness;
				cph1 = j;
			} 
			if (p.cp[j].compatibility > cpc && p.cp[j].compatibility < mcpc) {
				cpc = p.cp[j].compatibility;
				cpc1 = j;
			}
		}
		mcph = cph;
		mcpc = cpc;
		time_t now = time(0);
		char* ctt = ctime (&now);
		cout <<ctt;
		printf ("%s %s %d\t\t\t%s %s %d\n", p.cp[cph1].girl.name_id, p.cp[cph1].boy.name_id, cph, p.cp[cpc1].girl.name_id, p.cp[cpc1].boy.name_id, cpc);
		printf ("\n");
	}
	return 0;
}
