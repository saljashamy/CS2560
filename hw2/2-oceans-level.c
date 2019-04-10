#include <stdio.h>

const float oceansLevelRisingRate = 1.5;


float calculateOceansLevelRiseIn(int years){
	return oceansLevelRisingRate * years;
}

