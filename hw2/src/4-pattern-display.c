#include <stdio.h>
#include <stdbool.h>

void displayPattern(char ch, int rows, int reverse){
	int len;
	int add;
	if(reverse == 1){
		len = rows;
		add = -1;
	}else{
		len = 1;
		add = 1;
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < len; j++){
			putchar(ch);
		}
		putchar('\n');
		len += add;
	}
}
