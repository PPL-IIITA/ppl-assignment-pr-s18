#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "fill_data.h"
using namespace std;
Data::Data(Boy boy[], Girl girl[]) {
	char dname[9];
	int datr;
	int dintl;
	int dbudget;
	int dmin_atr;
	int dstatus;
	int dmain_cost;
	int dcriteria;
	int dcommited;

	FILE *fpb, *fpg;
	fpb = fopen("boy_list.txt", "r");
	
	fscanf (fpb, "%d", &nb);
	for(int i = 0; i < nb; i++) {
		Boy *temp;
		fscanf(fpb,"%s %d %d %d %d %d %d", dname, &dcommited, &dstatus, &datr, &dintl, &dbudget, &dmin_atr);
		if(dstatus == 0) {
			temp = new Miser(dname, datr, dintl, dbudget, dmin_atr);
		} else if(dstatus == 1) {
			temp = new Generous(dname, datr, dintl, dbudget, dmin_atr);
		} else {
			temp = new Geek(dname, datr, dintl, dbudget, dmin_atr);
		}
		boy[i] = *temp;
	}
	/*for (int i = 0; i < nb; i++) {
		printf ("%d %s %d %d %d %d %d %d\n", i, boy[i].name_id, boy[i].status, boy[i].commited, boy[i].atr, boy[i].intl, boy[i].budget, boy[i].min_atr);
	}*/
	fpg = fopen ("girl_list.txt", "r");
	fscanf (fpg, "%d", &ng);
	for (int i = 0; i < ng; i++) {
		Girl *temp;
		fscanf(fpg,"%s %d %d %d %d %d %d", dname, &dcommited, &dstatus, &datr, &dintl, &dmain_cost, &dcriteria);
		if(dstatus == 0){
			temp = new Choosy(dname, datr, dintl, dmain_cost, dcriteria);
		} else if(dstatus == 1) {
			temp = new Normal(dname, datr, dintl, dmain_cost, dcriteria);
		} else {
			temp = new Desperate(dname, datr, dintl, dmain_cost, dcriteria);
		}
		girl[i] = *temp;
	}
	/*for (int i = 0; i < ng; i++) {
		printf ("%d %s %d %d %d %d %d %d\n", i, girl[i].name_id, girl[i].status, girl[i].commited, girl[i].atr, girl[i].intl, girl[i].man_cost, girl[i].criteria);
	}*/
}


void Data::gifting(Gift gift[]) {
	FILE *fp;
	fp = fopen ("gift_list.txt", "r");
	int ttype;
	int tprice;
	int tvalue;
	int tluxury;
	int tdifficulty;
	int tutility;
	int tutilityc;
	int isselected;
	fscanf(fp,"%d", &n);
	for(int i = 0; i < n; i++) {
		Gift *temp;
		fscanf(fp, "%d %d %d %d", &tvalue, &tprice, &ttype, &isselected);
		if(ttype == 0) {
			temp = new Essential(tprice, tvalue);
		} else if(ttype == 1) {
			fscanf(fp,"%d %d",&tluxury, &tdifficulty);
			temp = new Luxury(tprice, tvalue, tluxury, tdifficulty);
		} else {
			fscanf(fp,"%d %d", &tutility, &tutilityc);
			temp = new Utility(tprice, tvalue, tutility, tutilityc);
		}
		gift[i] = *temp;
	}
	/*printf ("hello\n");
	for (int i = 0; i < n; i++) {
		if (gift[i].type == 0) {
			printf ("%d %d %d %d %d\n", i, gift[i].price, gift[i].value, gift[i].type, gift[i].is_selected);
		}
		else if (gift[i].type == 1) {
			printf ("%d %d %d %d %d\n", i, gift[i].price, gift[i].value, gift[i].type, gift[i].is_selected);
		}
		else {
			printf ("%d %d %d %d %d\n", i, gift[i].price, gift[i].value, gift[i].type, gift[i].is_selected);
		}
	}*/

}

void Data::Vdays (int day[], int *t) {
	*t = 0;
	for (int i = 0; i < 29; i++) {
		day[i] = rand()%2;
	}
	for (int i = 0; i < 29; i++) {
		if (day[i]) {
			*t = *t + 1;
		}
	}
}
