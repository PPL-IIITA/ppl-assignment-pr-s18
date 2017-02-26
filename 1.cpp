#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "make_pair.h"
using namespace std;

int main () {
	Pair p;
	int i;
	freopen ("couple.txt", "w", stdout);
	printf ("%d\n", p.k);
	for (i = 0; i < p.k; i++) {
		printf ("%s %d %d %d %d %d %d\n%s %d %d %d %d %d %d\n",p.cp[i].girl.name_id, p.cp[i].girl.commited, p.cp[i].girl.status, p.cp[i].girl.atr, p.cp[i].girl.intl,p.cp[i].girl.man_cost, p.cp[i].girl.criteria, p.cp[i].boy.name_id, p.cp[i].boy.commited, p.cp[i].boy.status, p.cp[i].boy.status, p.cp[i].boy.intl, p.cp[i].boy.budget, p.cp[i].boy.min_atr);
	}
	return 0;
}
