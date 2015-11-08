/*
 * Location: Temple University CIS 1057 Fall 2015
 * Programmer: J. Michael Evatt
 * Class: Introduction to C Programming
 * Assignment:
 * Date:
 * Description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C_PROGRAMMER_NAME "J. Michael Evatt"


#define BOARD_SIZE 9;

int main( void )
{
	int winner; //Flag for winner existence.
	char cpu_char, usr_char; //The characters used for the board game.
	char board[BOARD_SIZE]; //The array for gameplay
	int i; //placeholder index
	int turn; //Holds 0 if it is the cpu turn, 1 if it is the usr turn
	//Open the game
	//Call title graphic
	//Give user instructions
	
	//Start game
	//Initialize variables
	winner = 0;
	cpu_char = 'x';
	usr_char = 'o';
	turn = 1; //For now the usr plays first
	for (i=0;i<BOARD_SIZE;i++)
		board[i] = ' '; //Fill th board with spaces
	
	
	do 
	{
		winner_found(board[9],!turn);
		//if(usr_turn)
			//Call usr_input
		//else if(cpu_turn)
			//Call cpu_input
		//The gameplay
	}while(winner);
	
	
 	return EXIT_SUCCESS;
}

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
