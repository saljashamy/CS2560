#include <stdio.h>

const float PI = 3.1415;

void printMenu(){
	printf("\nGeometry Calculator\n");
	printf("    1. Calculate the Area of a Circle\n");
	printf("    2. Calculate the Area of a Rectangle\n");
	printf("    3. Calculate the Area of a Triangle\n");
	printf("    4. Quit\n");
	printf("    Enter your choice (1-4): ");
}

void promptSelect(int *select){
	printMenu();
	fflush(stdout);
	char c = getchar( );
	*select = c - '0';
	getchar();
}

void promptMeasure(float *data){
	int try = 0;
	while (*data < 0){
		if (try != 0){
			printf("    Enter non-negative value: ");
		}
		fflush(stdout);
		scanf("%f", data);
		try++;
		getchar();
	}
}

void calculateAreaCircle(){
	printf("    Enter circle radius: ");
	float radius = -1;
	promptMeasure(&radius);
	printf("    Circle area: %.2f \n", radius * PI);
}

void calculateAreaRectangle(){
	printf("    Enter rectangle width: ");
	float width = -1;
	promptMeasure(&width);
	printf("    Enter rectangle length: ");
	float length = -1;
	promptMeasure(&length);
	printf("    Rectangle area: %.2f \n", width * length);
}

void calculateAreaTriangle(){
	printf("    Enter triangle base: ");
	float base = -1;
	promptMeasure(&base);
	printf("    Enter triangle height: ");
	float height = -1;
	promptMeasure(&height);
	printf("    Triangle area: %.2f \n", base * height * .5);
}

void geometryCalculator(){
	int select = 0;
	while(select != 4){
	    select = 0;
		int try = 0;
		while(select < 1 || select > 4){
			if (try != 0){
				printf("    Select from 1 to 4\n");
			}
			promptSelect(&select);
			try++;
		}
		if (select == 1){
			calculateAreaCircle();
		}
		else if(select == 2){
			calculateAreaRectangle();
		}
		else if (select == 3){
			calculateAreaTriangle();
		}
	}
}
