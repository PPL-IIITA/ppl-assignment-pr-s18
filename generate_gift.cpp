#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/**@detail
 * Testing utility to randomly generate details of all gifts
 */
int main () {
	int value[60], price[60], type[60], is_selected[60], lux_rate[60], lux_difficulty[60], utl_value[60], utl_class[60];
	int i;
	srand (time (NULL));
	freopen ("gift_list.txt", "w", stdout);
	for ( i = 1; i <60; i++) {
		value[i] = rand()%101;
		type[i] = rand()%3;
		is_selected[i] = 0;
		if (type[i] == 0) {
			price[i] = 50+ (rand()%1051);
			lux_rate[i] = -1;
			lux_difficulty[i] = -1;
			utl_value[i] = -1;
			utl_class[i] = -1;
		}
		else if (type[i] == 1) {
			price[i] = 2000 + (rand()%2001);
			lux_rate[i] = rand()%5;
			lux_difficulty[i] = rand()%10;
			utl_value[i] = -1;
			utl_class[i] = -1;
		}
		else if (type[i] == 2) {
			price[i] = 4000 + (rand()%2001);
			lux_rate[i] = -1;
			lux_difficulty[i] = -1;
			utl_value[i] = rand()%101;
			utl_class[i] = rand()%10;
		}
	}
	printf ("60\n");
	value[0] = -1;
	price[0] = 11000;
	is_selected[0] = 0;
	type[0] = 0;
	lux_rate[0] = -1;
	lux_difficulty[0] = -1;
	utl_value[0] = -1;
	utl_class[0] = -1;
	for (i = 0; i < 60; i++) {
		printf ("%d %d %d %d %d %d %d %d\n", value[i], price[i], type[i], is_selected[i], lux_rate[i], lux_difficulty[i], utl_value[i], utl_class[i]);
	}
	return 0;
}
