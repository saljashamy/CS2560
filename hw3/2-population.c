#include <stdio.h>

void promptValidDataFloat(float *data, float min){
	int try = 0;
	while (*data < min){
		if (try != 0){
			printf("    Minimum value is %.2f\% \n", min);
			printf("    Try again : ");
		}
		fflush(stdout);
		scanf("%f", data);
		try++;
	}
}

void promptValidDataInt(int *data, int min){
	int try = 0;
	while (*data < min){
		if (try != 0){
			printf("    Minimum value is %d \n", min);
			printf("    Try again : ");
		}
		fflush(stdout);
		scanf("%d", data);
		try++;
	}
	getchar();
}

void startingPopulation(int *p){
	printf("    Enter starting population: ");
	promptValidDataInt(p, 2);
}

void annualBirthRate(float *abr){
	printf("    Enter annual birth Rate: ");
	promptValidDataFloat(abr, 0);
}

void annualDeathRate(float *adr){
	printf("    Enter annual death Rate: ");
	promptValidDataFloat(adr, 0);
}

void yearsToDisplay(int *y){
	printf("    Enter years to display: ");
	promptValidDataInt(y, 1);
}

void sizePopulationYear(){
	int p = 0;
	float abr = -1;
	float adr = -1;
	int y = 0;

	startingPopulation(&p);
	annualBirthRate(&abr);
	annualDeathRate(&adr);
	yearsToDisplay(&y);

	for(int i = 0; i < y; i++){
		int n = p + p*(abr/100) - p *(adr/100);
		printf("    Population in %d year: %d \n", i+1, n);
		p = n;
	}
}


