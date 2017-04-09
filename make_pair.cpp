#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include "make_pair.h"

using namespace std;
Pair:: Pair(){
			Data in(boy, girl);
			int ng, nb;
			ng = in.ng;
			nb = in.nb;
			int flag, index;
			k = 0;
			int i, j;
			for (i = 0; i < ng; i++) {
				index = 0;
				flag = 0;
				for (j = 1; j < nb; j++) {
					if ((j == nb-1) && (boy[index].commited == 1 || (boy[index].budget < girl[i].man_cost || boy[index].min_atr > girl[i].atr))) {				
						flag = 1;
					}
					if (boy[j].commited == 1 || (boy[j].budget < girl[i].man_cost || boy[j].min_atr > girl[i].atr)) {
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
				}
			}
		}

void Pair::make_gift_basket () {
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


void Pair::find_happiness_comp () {
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


void Pair::print_gift() {
	int i, j, k1 = k;
	freopen ("Happiness_compatibility_gift.txt", "w", stdout);
	for (i = 0; i < k1; i++) {
		printf ("Boy: %s gave %d gifts to Girl: %s\n",cp[i].boy.name_id, cp[i].gift_basket[0].price-1, cp[i].girl.name_id);
		printf ("Type of Gift\t\tPrice\tValue\n\n");
		for (j = 1; j < cp[i].gift_basket[0].price; j++) {
			time_t now = time(0);
			char* ctt = ctime (&now);
			cout <<ctt;
			if (cp[i].gift_basket[j].type == 0) {
				printf ("Essential gift: ");
				printf ("\t%d\t%d\n", cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			else if (cp[i].gift_basket[j].type == 1) {
				printf ("Luxury gift: \t");
				printf ("\t%d\t%d\n",cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			else if (cp[i].gift_basket[j].type == 2) {
				printf ("Utility gift: \t");
				printf ("\t%d\t%d\n", cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			
			
		}
		printf ("\n\n");
	}
}

void Pair::print_gift6() {
	int i, j, k1 = k;
	freopen ("ques6.txt", "a", stdout);
	for (i = 0; i < k1; i++) {
		printf ("Boy: %s gave %d gifts to Girl: %s\n",cp[i].boy.name_id, cp[i].gift_basket[0].price-1, cp[i].girl.name_id);
		printf ("Type of Gift\t\tPrice\tValue\n\n");
		for (j = 1; j < cp[i].gift_basket[0].price; j++) {
			time_t now = time(0);
			char* ctt = ctime (&now);
			cout <<ctt;
			if (cp[i].gift_basket[j].type == 0) {
				printf ("Essential gift: ");
				printf ("\t%d\t%d\n", cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			else if (cp[i].gift_basket[j].type == 1) {
				printf ("Luxury gift: \t");
				printf ("\t%d\t%d\n",cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			else if (cp[i].gift_basket[j].type == 2) {
				printf ("Utility gift: \t");
				printf ("\t%d\t%d\n", cp[i].gift_basket[j].price, cp[i].gift_basket[j].value);
			}
			
			
		}
		printf ("\n\n");
	}
}

int Pair::ret_num (int t) {
	int temp;
	int i;
	int count = 0;
	for (i = 0; i < k; i++) {
		temp = cp[i].happiness;
		if (temp %49 < t) {
			count++;
		}
	}
	return count;
}


void Pair::breakup(int kc) {
	int i, j, index, flag, nb;
	Couple c;
	FILE *f2;
	f2 = fopen ("boy_list.txt", "r");
	fscanf (f2, "%d",&nb);
	for (i = 0; i < k; i++) {
		for (j = 0;j < k-1-i; j++) {
			if (cp[j].happiness > cp[j+1].happiness) {
				c = cp[j];
				cp[j] = cp[j+1];
				cp[j+1] = c;		
			}
		}
	}
	for (i = 0; i < kc; i++) {
				index = 0;
				flag = 0;
				for (j = 1; j < nb; j++) {
					if ((j == nb-1) && (boy[index].commited == 1 || (boy[index].budget < girl[i].man_cost || boy[index].min_atr > girl[i].atr))) {				
						flag = 1;
					}
					if (boy[j].commited == 1 || (boy[j].budget < girl[i].man_cost || boy[j].min_atr > girl[i].atr)) {
						continue;
					}
					if (cp[i].girl.criteria == 0) {
						if (boy[j].atr > boy[index].atr) {
							index = j;
						}
					}
					else if (cp[i].girl.criteria == 1) {
						if (boy[j].budget > boy[index].budget) {
							index = j;
						}
					}
					else if (cp[i].girl.criteria == 2) {
						if (boy[j].intl > boy[index].intl) {
							index = j;
						}
					}						
				}
				if (flag == 0) {
					boy[index].commited = 1;
					//girl[i].commited = 1;
					//cp[k].girl = girl[i];
					for (j = 1; j < nb; j++) {
						if (strcmp(boy[j].name_id, cp[i].boy.name_id) == 0) {
							boy[j].commited = 0;
							break;
						}
					}
					cp[i].boy = boy[index];
					
				}
						
	}
	
}





























