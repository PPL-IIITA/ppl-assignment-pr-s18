#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "select1.h"

Select1::Select1 (int kcc, Couple cl[50]) {
	k = kcc;
	int i;
	for (i = 0; i < k; i++) {
		cp[i] = cl[i];
	}
}

void Select1::way1 (Gift gift[100], int ngf) {
	int l = 0, i, j;
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
}


