#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "select1.h"
#include "select2.h"
#include "make_pair.h"

int main () {
	Pair p;
	giftSelector gs;
	gs.set_values (p.k, p.cp);
	int m[100];
	gs.generate_method (m);
	Select1 s1(gs.k, gs.cp);
	Select2 s2(gs.k, gs.cp);
	Boy b[50];
	Girl g[50];
	Data d(b, g);
	Gift gift[100];
	d.gifting (gift);
	s1.way1 (gift, d.n);
	s2.way2 (gift, d.n);
	freopen ("ques8.txt", "w", stdout);
	for (int i = 0; i < gs.k; i++) {
		if (m[i]) {
			printf ("Boy: %s gave %d gifts to Girl: %s\n",gs.cp[i].boy.name_id, s2.cpgift[i][0].price-1, gs.cp[i].girl.name_id);
			printf ("Type of Gift\t\tPrice\tValue\n\n");
			for (int j = 1; j < s2.cpgift[i][0].price; j++) {
				time_t now = time(0);
				char* ctt = ctime (&now);
				cout <<ctt;
				if (s2.cpgift[i][j].type == 0) {
					printf ("Essential gift: ");
					printf ("\t%d\t%d\n", s2.cpgift[i][j].price, s2.cpgift[i][j].value);
				}
				else if (s2.cpgift[i][j].type == 1) {
					printf ("Luxury gift: \t");
					printf ("\t%d\t%d\n",s2.cpgift[i][j].price, s2.cpgift[i][j].value);
				}
				else if (s2.cpgift[i][j].type == 2) {
					printf ("Utility gift: \t");
					printf ("\t%d\t%d\n", s2.cpgift[i][j].price, s2.cpgift[i][j].value);
				}


			}
		printf ("\n\n");
		}
		else {
			printf ("Boy: %s gave %d gifts to Girl: %s\n",gs.cp[i].boy.name_id, s1.cpgift[i][0].price-1, gs.cp[i].girl.name_id);
			printf ("Type of Gift\t\tPrice\tValue\n\n");
			for (int j = 1; j < s1.cpgift[i][0].price; j++) {
			time_t now = time(0);
			char* ctt = ctime (&now);
			cout <<ctt;
			if (s1.cpgift[i][j].type == 0) {
				printf ("Essential gift: ");
				printf ("\t%d\t%d\n", s1.cpgift[i][j].price, s1.cpgift[i][j].value);
			}
			else if (s1.cpgift[i][j].type == 1) {
				printf ("Luxury gift: \t");
				printf ("\t%d\t%d\n",s1.cpgift[i][j].price, s1.cpgift[i][j].value);
			}
			else if (s1.cpgift[i][j].type == 2) {
				printf ("Utility gift: \t");
				printf ("\t%d\t%d\n", s1.cpgift[i][j].price, s1.cpgift[i][j].value);
			}


		}
		printf ("\n\n");
		}
	}
	return 0;
}
