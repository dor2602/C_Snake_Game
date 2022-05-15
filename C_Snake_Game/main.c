#include <string.h>
#include <stdio.h>
#include "Snake.h"

int main()
{ 
	
label_1:
	printf("Set speed value for new game (1 - 100)\nSpeed : \n");
	scanf_s("%d", &speed);
	if (speed > 100)
		speed = 100;
	else if (speed < 0)
		speed = 1;
	speed = (int)1000 - speed * 10;
	Setup();//Prepare the game

	/*The sleep() function delayes the program execution to help slow
	down the movement of the snake , its make the play easy for the user .
				*/

	while (Game_Over == 0)
	{
		_sleep(speed);
		Draw();
		Input();
		Logic();
	}
	GameOver();
	getchar();
	char ch;
	scanf_s("%c", &ch);
	getchar();
	if (ch == 'y'|| ch == 'Y')
	{
		snake.move = up;
		goto label_1;
	}
	printf("It was a good game, hope to see you next time :)\n");
	return 0;
}