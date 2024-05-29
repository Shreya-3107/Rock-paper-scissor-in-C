#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//All function declaration

void gameplay(void);                                      //Conducts the actual game
short int computerMove(void);                             //Generates a random move for the computer
short int playerMove(void);                               //Gets input from user for user's move
char* checkType(short int play);                          //
short int checkWinner(short int player, short int comp);  //Checks the winner of game


int main()
{   
	char choice; 

	printf("\n\t--------------- ROCK, PAPER, SCISSORS ---------------\n\n");
    
/*	do{
		printf("\n\tEnter y to play or n to exit:   ");
        	scanf("%c", &choice);

        	if(choice == 'y')
            		gameplay();


    	} while(choice != 'n');
*/

	while(1)
	{
		printf("\n\tEnter y to play or n to exit:  ");
		scanf("%c", &choice);

		if(choice == 'y')
			gameplay();
			
		else if(choice != 'y' && choice != 'n')
			printf("\tInvalid choice\n");

		else
			break;
	}
	 
	printf("\tThank you for playing~~~\n\n ");
        
	return 0;
}
    

void gameplay(void)
{
	short int player = playerMove();

	short int computer = computerMove();

	short int result = checkWinner(player, computer);

	
	printf("\n\tYou entered: %s\n", checkType(player));
	printf("\tComputer entered: %s\n\n", checkType(computer));
	
	if(result == 0)
		printf("\tDraw~\n");
	
	else if(result == 1)
		printf("\tComputer won! :p\n");

	else
		printf("\tYou won!!!!!!!!!! ^w^\n");

	return;
}


short int playerMove(void)
{
	short int input;
	char c;

	printf("\n\tRock(1), Paper(2), or Scissors(3)????   ");
	scanf("%hd", &input);
	c = getchar();

	
	return input;
}

short int computerMove(void)
{
	srand(time(NULL));
	
	short int random = rand() % 1000;

	if(random % 3 == 0)
		return 1;
	
	else if(random % 3 == 1)
		return 2;
	
	else
		return 3;
}


short int checkWinner(short int player, short int computer)
{
	if(player == computer)
		return 0;

	else if( (player == 1 && computer == 2) || (player == 2 && computer == 3) || (player == 3 && computer ==1) )
		return 1;

	else
		return 1;
}

char* checkType(short int play)
{
	if(play == 1)
		return "Rock";

	else if(play == 2)
		return "Paper";

	else
		return "Scissor";
}
