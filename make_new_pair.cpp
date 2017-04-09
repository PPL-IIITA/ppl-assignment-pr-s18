#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include "make_new_pair.h"

using namespace std;
void New_Pair::make_new() {
	Data in(boy, girl);
	int ng, nb;
	ng = in.ng;
	nb = in.nb;
	int flag, index, i, j;
	k = 0;
	Girl g;
	Boy b;
	for (i = 0; i < ng; i++) {
		for (j = 0; j < ng-1; j++) {
			if (girl[j].man_cost > girl[j+1].man_cost) {
				g = girl[j];
				girl[j] = girl[j+1];
				girl[j+1] = g;
			}
		}
	}
	for (i = 0; i < nb; i++) {
		for (j = 0; j < nb-1; j++) {
			if (boy[j].atr > boy[j+1].atr) {
				b = boy[j];
				boy[j] = boy[j+1];
				boy[j+1] = b;
			}
		}
	}
	freopen ("new_couple.txt", "w", stdout);
	/*for (i = 0; i < ng; i++) {
		printf ("girl: %s %d\n",girl[i].name_id, girl[i].man_cost);
	}
	for (i = 0; i < nb; i++) {
		printf ("boy: %s %d\n",boy[i].name_id, boy[i].atr);
	}*/
	int temp = ng-1;
	int count = 0;
	while (temp--) {
		if (count%2 == 0) {
			int flag, index;
			for (i = 1; i < ng; i++) {
				if (girl[i].commited != 0) {
					continue;
				}
				index = 0;
				flag = 0;
				for (j = 1; j < nb; j++) {
					if ((j == nb-1) && (boy[index].commited == 1 || (boy[index].budget < girl[i].man_cost || boy[index].min_atr > girl[i].atr))) {				
						flag = 1;
					}
					if (boy[j].commited == 1 || (boy[j].budget < girl[i].man_cost || boy[j].min_atr > girl[i].atr || girl[i].atr == -1)) {
						continue;
					}
					if (girl[i].criteria == 0) {
						if (boy[j].atr > boy[index].atr) {
							index = j;
						}
					}
					else if (girl[i].criteria == 1) {
						if (boy[j].budget > boy[index].budget) {
							index = j;
						}
					}
					else if (girl[i].criteria == 2) {
						if (boy[j].intl > boy[index].intl) {
							index = j;
						}
					}						
				}
				if (flag == 0) {
					boy[index].commited = 1;
					girl[i].commited = 1;
					cp[k].girl = girl[i];
					cp[k].boy = boy[index];
					k++;
					count++;
					break;
				}
			}
		}
		else {
			int id = 0;
			for (i = 0; i < nb; i++) {
				if (boy[i].commited == 0) {
					for (j = 0; j < ng; j++) {
						if (boy[i].min_atr > girl[j].atr || boy[i].budget < girl[j].man_cost || girl[j].atr == -1) {
							continue;
						}
						int k3, maximum;
						if (girl[j].commited == 0) {
							maximum = girl[j].atr;
							id = j;
							for (k3 = j; k3 < ng; k3++) {
								if (girl[k3].commited == 0 && girl[k3].atr > maximum) {
									maximum = girl[k3].atr;
									id = k3;
								}
							}
						}
					}
				}
				if (boy[i].commited != 0 || girl[id].commited != 0 || girl[id].atr == -1)
					continue;
				boy[i].commited = 1;
				girl[id].commited = 1;
				cp[k].girl = girl[id];
				cp[k].boy = boy[i];
				k++;
				count++;
				break;
			}
		}
	}
	for (i = 0; i < k; i++) {
		printf ("%s %d %d %d %d %d %d\n%s %d %d %d %d %d %d\n",cp[i].girl.name_id, cp[i].girl.commited, cp[i].girl.status, cp[i].girl.atr, cp[i].girl.intl,cp[i].girl.man_cost, cp[i].girl.criteria, cp[i].boy.name_id, cp[i].boy.commited, cp[i].boy.status, cp[i].boy.atr, cp[i].boy.intl, cp[i].boy.budget, cp[i].boy.min_atr);
	}
}


void New_Pair::make_gift_basket () {
			int ngf, i, j;
			Gift gift[100];
			Boy b[50];
			Girl g[50];
			Data in(b, g);
			in.gifting (gift);
			ngf = in.n;
			Gift cpgift[k+1][100];
			int l = 0;
			int min = 0, bg, bg1, bg2, min1, M = 0, flag;
			for (i = 1; i < ngf; i++) {
				if (gift[i].price < gift[M].price) {
					M = i;
				}
			}
			for (i = 0; i < k; i++) {
				l = 1;
				if (cp[i].boy.status == 0) {
					bg = (cp[i].girl.man_cost);
				}
				else if (cp[i].boy.status == 1) {
					bg = cp[i].boy.budget;
				}
				else if (cp[i].boy.status == 2) {
					bg = (cp[i].girl.man_cost);
					bg1 = bg;
				}
				while (bg > 0) {
					if (cp[i].boy.status == 1) {
						gift[0].price = 0;
					}
					else if (cp[i].boy.status == 0 || cp[i].boy.status == 2){
						gift[0].price = 11000;
					}
					min = 0;
					for (j = 1; j < ngf; j++) {
						if (gift[j].is_selected == 1) {
							continue;
						}
						if (cp[i].boy.status == 0 || cp[i].boy.status == 2) {
							if (gift[j].price < gift[min].price) {
								min = j;
							}
						}
						else if (cp[i].boy.status == 1) {
							if (bg < gift[M].price) {
								break;
							}
							else if (gift[j].price > gift[min].price && gift[j].price <= bg) {
								min = j;
							}
						}
					}
					if (bg >= gift[min].price && min != 0) {
						gift[min].is_selected = 1;	
						cpgift[i][l] = gift[min];
						bg -= gift[min].price;
						l++;
					}
					else if (bg < gift[min].price && min != 0){
						if (cp[i].boy.status == 1) {
							break;
						}
						if ((cp[i].girl.man_cost + (gift[min].price - bg)) > cp[i].boy.budget) {
							cp[i].boy.budget = (cp[i].girl.man_cost + (gift[min].price - bg));
						}
						gift[min].is_selected = 1;
						cpgift[i][l] = gift[min];
						bg = 0;
						l++;
						break;
					}
					else {
						break;
					}
				
				}
				if (cp[i].boy.status == 2) {
					bg2 = cp[i].boy.budget - bg1;
					for (j = 1; j < ngf; j++) {
						if (gift[j].is_selected == 1 || (gift[i].type == 0 || gift[i].type == 2)) {
							continue;
						}
						else if (gift[j].type == 1 && gift[j].price <= bg2) {
							gift[j].is_selected = 1;					
							cpgift[i][l] = gift[j];
							l++;
							break;
						}
					}
				}
				cpgift[i][0].price = l;
				for (j = 0; j < ngf; j++) {
					gift[j].is_selected = 0;
				}
			}
			for (i = 0; i < k; i++) {
				cp[i].gift_basket[0].price = cpgift[i][0].price;
				for (j = 1; j < cpgift[i][0].price; j++) {
					cp[i].gift_basket[j] = cpgift[i][j];
				}
			}
}

void New_Pair::find_happiness_comp () {
			int tot_cost, tot_value;
			int i, j;
			for (i = 0; i < k; i++) {
				tot_cost = 0;
				tot_value = 0;
				for (j = 1; j < cp[i].gift_basket[0].price; j++) {
					tot_cost += cp[i].gift_basket[j].price;
					tot_value += cp[i].gift_basket[j].value;
				}
				cp[i].girl.find_happiness (tot_cost, tot_value);
				cp[i].boy.find_happiness (tot_cost, cp[i].girl);
				cp[i].find_happiness();
				cp[i].find_compatibility();
			}
}	


