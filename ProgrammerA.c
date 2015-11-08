enum board_locales {R1C1, R1C2, R1C3, R2C1, R2C2, R2C3, R3C1, R3C2, R3C3};

int total_moves;
int x_moves;
int o_moves;

char board[9];

void computer_move(char board[9], int last_move, char computer_char){
	int x; //Placeholder
//Check whether anyone is about to win
	if (x = win_chance(board[9])){
		board[x-1] = computer_char;
		return 0;}
//First move
	if (board[R1C1] == ' '){
		board[R1C1] = computer_char;
		return 0;
//Check the middle
	if (board[R2C2] == ' '){
		board[R2C2] = computer_char;
		return 0;
//Do the opposite
	x = opposite(last_move)
	if (board[x] == ' '){
		board[x] = computer_char;
	}
//Otherwise pick a random number between 0 and 8
	x = rand() % 8; 
	while (board[x] != ' ')
		x = rand() % 8;
	board[x] == computer_char;
}

int opposite(int last_move)
{
	if (last_move == 0 || last_move == 3 || last_move == 6)
		return last_move + 2;
	else if (last_move == 2 || last_move == 5 || last_move == 8)
		return last_move - 2;
	else if (last_move == 1)
		return 7;
	else if (last_move == 7)
		return 1;
	else
		return 0;

}
	
int player_move(char board[9], int location, char player_char){
	if (board[location]) == ' ')
		board[location] = player_char;
		return 0;
	else
		return 1;
}

/*Cases where someone is about to win*/
int winner_found(char board[9], int player)
{
if(board[R1C1] == board[R1C2] == board[R1C3])
	return player; //Player Won!
else if(board[R2C1] == board[R2C2] == board[R2C3])
	return player; //Player Won!
else if(board[R3C1] == board[R3C2] == board[R3C3])
	return player; //Player Won!
else if(board[R1C1] == board[R2C2] == board[R3C3])
	return player; //Player Won!
else if(board[R1C3] == board[R2C2] == board[R3C1])
	return player; //Player Won!
else
	return 0; //Noone has won yet
}


int win_chance(char board[9])
{
	if (board[R1C1] == board[R1C2])
		return R1C3+1;
	else if(board[R1C2] == board[R1C3])
		return R1C1+1;
	else if(board[R2C1] == board[R2C2])
		return R2C3+1;
	else if(board[R3C1] == board[R3C2])
		return R3C3+1;
	else if(board[R3C2] == board[R3C3])
		return R3C1+1;
	else if(board[R1C1] == board[R2C2])
		return R3C3+1;
	else if(board[R1C3] == board[R2C2])
		return R3C1+1;
	else if(board[R3C1] == board[R2C2])
		return R2C2+1;
	else if(board[R3C3] == board[R2C2])
		return R1C1+1;
	else
		return 0;
}
