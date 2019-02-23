#include <stdio.h>

void printBoard(char (*b)[3][3]){
	printf("  1 2 3\n");
	for(int i = 0; i < 3; i++){
		putchar((i + 1) + '0');
		putchar(' ');
		for(int j = 0; j < 3; j++){
			putchar((*b)[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}

void initializeBoard(char (*b)[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			(*b)[i][j] = '*';
		}
	}
}

void moveInput(char (*b)[3][3], char ch){
	int taken = 1;
	while(taken != 0){
		int row = -1;
		int column = -1;
		while(row < 1 || row > 3){
			printf("Enter row (1-3): ");
			scanf("%d", &row);
		}
		while(column < 1 || column > 3){
			printf("Enter column (1-3): ");
		    scanf("%d", &column);
		}
		if((*b)[row-1][column-1] == '*'){
			taken = 0;
			(*b)[row-1][column-1] = ch;
		}
		else{
			taken = 1;
			printf("Row %d column %d taken \n", row, column);
		}
	}
}

void checkWon(char (*b)[3][3], char ch, char *won){
	for(int r = 0; r < 3; r++){
		if((*b)[r][0] == ch && (*b)[r][1] == ch && (*b)[r][2] == ch){
			*won = ch;
			return;
		}
	}

	for(int c = 0; c < 3; c++){
		if((*b)[0][c] == ch && (*b)[1][c] == ch && (*b)[2][c] == ch){
			*won = ch;
			return;
		}
	}
	if((*b)[0][0] == ch && (*b)[1][1] == ch && (*b)[2][2] == ch){
		*won = ch;
		return;
	}
	if((*b)[0][2] == ch && (*b)[1][1] == ch && (*b)[2][0] == ch){
		*won = ch;
		return;
	}
}

void ticTacToeGame(){
	char board [3][3];
	initializeBoard(&board);
	printBoard(&board);
	int turns = 0;
	char won = '*';
	while(turns != 9 && won == '*'){
		for(int i = 0; i < 2; i++){
			printf("\nPlayer %d turn\n", i+1);
			if(i == 0){
				moveInput(&board, 'X');
				checkWon(&board, 'X', &won);
			}
			else{
				moveInput(&board, 'O');
				checkWon(&board, 'O', &won);
			}
			printBoard(&board);
			turns++;
			if(turns == 9 || won != '*'){
				break;
			}
		}
	}
	if(won != '*'){
		if(won == 'X'){
			printf("Player 1 won");
		}
		else{
			printf("Player 2 won");
		}
	}
	else{
		printf("Tie");
	}
}
