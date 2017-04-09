#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "fill_data.h"
#include "make_pair.h"

int main () {
	int day[32];
	int t;
	Boy b[50];
	Girl g[50];
	Data in(b, g);
	in.Vdays (day, &t);
	Pair p;
	for (int i = 0; i < 29; i++) {
		if (day[i] != 0) {
			p.make_gift_basket();
			p.find_happiness_comp();
			p.print_gift6();
			printf ("NEXT GIFTING\n\n\n\n");
			int kc = p.ret_num (t);
			p.breakup (kc);
		}
	}
	
	return 0;
}
