#include <stdio.h>

/**
 * @file 2-oceans-level.c
 * @author Saif Aljashamy
 * @date 10 April 2019
 * @brief calculates ocean's level rise in centimeters
 *
 * @see https://github.com/saljashamy/CS2560/blob/master/hw2
 */

const float oceansLevelRisingRate = 1.5; /**< rate of ocean level rise **/


/**
 * @brief returns total ocean's level rise in n @p years 
 *
 */
float calculateOceansLevelRiseIn(int years){
	return oceansLevelRisingRate * years;
}
