#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/**@detail
 * Testing utility to randomly generate details of all girls
 */
int main () {
	srand (time (NULL));
	freopen ("girl_list.txt","w", stdout);
	char name_id[22][10];
	int i, j;
	int commited[22];
	int status[22]; 
	int atr[22]; 
	int intl[22]; 
	int man_cost[22]; 
	int criteria[22];
	for (i = 1; i < 22; i++) {
		status[i] = rand() % 3;
		commited[i] = 0;
		atr[i] = rand() % 11;
		intl[i] = rand() % 11;
		man_cost[i] = 2000 + (rand() % 5001);
		criteria[i] = rand() % 3;
				
	} 

	for (i = 1; i < 22; i++) {
		for (j = 0; j < 7; j++) {
			name_id[i][j] = (rand()%26)+65;
		}
		name_id[i][7] = '\0';
	}

	printf ("22\n");
	strcpy (name_id[0], "");
	commited[0] = 0;
	status[0] = -1;
	atr[0] = -1;
	intl[0] = -1;
	man_cost[0] = 0;
	criteria[0] = -1;
	for (i = 0; i < 22; i++) {
		printf ("%s %d %d %d %d %d %d\n", name_id[i], commited[i], status[i], atr[i], intl[i], man_cost[i], criteria[i]);
	}
	return 0;
}
