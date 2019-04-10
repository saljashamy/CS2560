#include <stdio.h>
#include <stdbool.h>

/**
 * @file 4-pattern-display.c
 * @author Saif Aljashamy
 * @date 10 April 2019
 * @brief displays triangle pattern
 *
 * @see https://github.com/saljashamy/CS2560/blob/master/hw2
 */

/**
 * @brief displays triangle pattern with n rows and c character
 * @param ch character
 * @param row number of rows
 * @param reverse reversed pattern
 */
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
