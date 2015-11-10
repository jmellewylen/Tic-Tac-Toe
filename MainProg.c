/*
 *
 * Location: Temple University CIS 1057 Fall 2015
 * Programmer: J. Michael Evatt
 * Class: Introduction to C Programming
 * Assignment:
 * Date:
 * Description:
*/
enum board_locales {R1C1, R1C2, R1C3, R2C1, R2C2, R2C3, R3C1, R3C2, R3C3};
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Group.h"
#define C_PROGRAMMER_NAME "J. Michael Evatt"
#define MAX_LEN 1024

#define BOARD_SIZE 9

int winner_found(char board[], int player, int moves);
int win_chance(char board[]);
int player_move(char board[], int location, char player_char);
int opposite(int last_move);
void computer_move(char board[], int last_move, char computer_char);
void print_board( int board[]);
int determine_order(void);
int getspace( void );
int open_file(char *fname);
void print_image(FILE *fptr);


int main( void )
{
	int winner; //Flag for winner existence.
	char cpu_char, usr_char; //The characters used for the board game.
	char board[BOARD_SIZE]; //The array for gameplay
	int i; //placeholder index
	int turn; //Holds 0 if it is the cpu turn, 1 if it is the usr turn
	int total_moves;	//Keeps an increment of the number of moves of the game
	char y_or_n; //Holds gameplay status
	int is_playing;
	int last_move;
	
	//Open the game
	//Call title graphic
	open_file("Titleimg.txt");
	//Give user instructions
	
	//Start game
	//Initialize variables
	while(is_playing){
	winner = 0;
	cpu_char = 'x';
	usr_char = 'o';
	turn = 1; //For now the usr plays first
	for (i=0;i<BOARD_SIZE;i++)
		board[i] = ' '; //Fill th board with spaces
	total_moves = 0; //Hey! The game just started so noone has moved yet! 
	
	do 
	{
		winner = winner_found(board,turn, total_moves);
		if(turn){//if(usr_turn)
			//Call usr_input
			total_moves++;
			winner_found(board, PLAYER, total_moves);
		}
		else//else if(cpu_turn)
			computer_move(board, last_move, cpu_char);//Call cpu_input
			winner_found(board, COMPUTER, total_moves);
			total_moves++;
		//The gameplay
	}while(!winner);
	
	if(winner == 1)
		open_file("playerimg.txt");
	else if (winner == 2)
		open_file("loserimg.txt");
		//Computer Won...
	else
		open_file("drawimg.txt");
		//Draw
	printf("Do you want to play again, y or n?");
	scanf("%c", &y_or_n);
	if(y_or_n == 'y' || y_or_n == 'Y')
		is_playing = 1;
	else 
		is_playing = 0;
	
	printf("Goodbye!/n");
	
 	return EXIT_SUCCESS;
}
}

void computer_move(char board[], int last_move, char computer_char){
	int x; //Placeholder
//Check whether anyone is about to win
	if (x = win_chance(board)){
		board[x-1] = computer_char;
		return;}
//First move
	if (board[R1C1] == ' '){
		board[R1C1] = computer_char;
		return;
	}
//Check the middle
	if (board[R2C2] == ' '){
		board[R2C2] = computer_char;
		return;
	}
//Do the opposite
	x = opposite(last_move);
	if (board[x] == ' '){
		board[x] = computer_char;
		return;
	}
//Otherwise pick a random number between 0 and 8
	x = rand() % 8; 
	while (board[x] != ' '){
		x = rand() % 8;
		board[x] == computer_char;
	}
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
	
int player_move(char board[], int location, char player_char){
	if (board[location] == ' '){
		board[location] = player_char;
		return 0;
	}
	else
		return 1;
}

/*Cases where someone is about to win*/
int winner_found(char board[], int player, int moves)
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
else if (moves == BOARD_SIZE)
	return DRAW;
else
	return 0; //Noone has won yet
}

int win_chance(char board[])
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

void print_board(int board[]){



        printf(" %c | %c | %c \n",board[0],board[1],board[2]);
        puts("-----------");
        printf(" %c | %c | %c \n",board[3],board[4],board[5]);
        puts("-----------");
        printf(" %c | %c | %c \n",board[6],board[7],board[8]);
return;
}

void implement_user_move(int board[ ]){
        int bn;
        scanf("Enter the box you would like to claim %d", &bn);
        /*check function runs*/
        board[bn]= 'x';
}

int determine_order(void){
        int p1;
        char z;

        while(1){
        scanf("%c", &z);

			if(z == 'x' || z == 'X'){
                printf("You have chosen to play as %c", z);
                return 1;
			}else if(z == 'O' || z == 'o'){
                printf("You have chosen to play as %c", z);
                return 2;
			}else{
                puts("Try again");
                continue;
			}
		}
}

int getspace( void ){
        int a;
        while (1){
                scanf("%d", &a);
                        if ( a>9 || a<1){
                                return a;
                        }else{
                                puts("try again");
                                continue;
                        }
                }
return 0;
}

int open_file(char *fname)
{
	char *filename = "image.txt";
	FILE *fptr = NULL;
	
	if((fptr = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"error opening %s\n", filename);
		return 1;
	}
	
	print_image(fptr);
	
	fclose(fptr);
 	return EXIT_SUCCESS;
}

void print_image(FILE *fptr){
	char read_string[MAX_LEN];
	
	while(fgets(read_string,sizeof(read_string),fptr) != NULL)
		printf("%s", read_string);
}
