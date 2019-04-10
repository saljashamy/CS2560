/**
 * @file driver.c
 * @author Saif Aljashamy
 * @date 10 April 2019
 * @brief driver
 *
 * @see https://github.com/saljashamy/CS2560/blob/master/hw2
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"


int main(void) {
	// #1
	printBill(88.67);

	// #2
	printf("Ocean level expected to rise by %.2f mm in 5 years\n", calculateOceansLevelRiseIn(5));
	printf("Ocean level expected to rise by %.2f mm in 7 years\n", calculateOceansLevelRiseIn(7));
	printf("Ocean level expected to rise by %.2f mm in 10 years\n", calculateOceansLevelRiseIn(10));

	// #3
	buyStock(1000, 45.50);
	sellStock(1000, 56.90);
	printPortfolioInfo();

	// #4
	printf("Pattern A \n");
	displayPattern('+', 10, 0);
	printf("Pattern B \n");
	displayPattern('+', 10, 1);

	return 0;
}
