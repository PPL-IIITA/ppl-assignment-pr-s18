#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/**@detail
 * Testing utility to randomly generate details of all boys
 */

int main () {
	srand (time (NULL));
	freopen ("boy_list.txt","w", stdout);
	char name_id[35][10];
	int i, j;
	int commited[35];
	int status[35]; 
	int atr[35]; 
	int intl[35]; 
	int budget[35]; 
	int min_atr[35];
	for (i = 1; i < 35; i++) {
		status[i] = rand() % 3;
		commited[i] = 0;
		atr[i] = rand() % 11;
		intl[i] = rand() % 11;
		budget[i] = 2000 + (rand() % 8001);
		min_atr[i] = rand() % 5;
				
	} 
	for (i = 1; i < 35; i++) {
		for (j = 0; j < 5; j++) {
			name_id[i][j] = (rand()%26)+65;
		}
		name_id[i][5] = '\0';
	}
	printf ("35\n");
	strcpy (name_id[0], "");
	commited[0] = 0;
	status[0] = -1;
	atr[0] = -1;
	intl[0] = -1;
	budget[0] = 0;
	min_atr[0] = 11;
	for (i = 0; i < 35; i++) {
		printf ("%s %d %d %d %d %d %d\n", name_id[i], commited[i], status[i], atr[i], intl[i], budget[i], min_atr[i]);
	}
	return 0;
}
