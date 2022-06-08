#include <stdio.h>
#include <stdlib.h>
#include <time.h>//for rand() function
#include <conio.h>//for kbhit() function
#include <windows.h>//for _sleep() function
#include <string.h>
#include "Snake.h"

void Setup()
{
	Game_Over = 0;
	snake.move = up;
	snake.head.x = MAX_X / 2;
	snake.head.y = MAX_Y / 2;
	snake.length = 4;
	snake.tail[0].x = snake.head.x + 1;
	snake.tail[0].y = snake.head.y ;
	snake.tail[1].x = snake.head.x + 2;
	snake.tail[1].y = snake.head.y;
	snake.tail[2].x = snake.head.x + 3;
	snake.tail[2].y = snake.head.y;

label1:
	activeFood.x = rand() % MAX_X; // Create a random number within 
	if (!activeFood.x)
		goto label1;
label2:
	activeFood.y = rand() % MAX_Y;
	if (!activeFood.y)
		goto label2;
	if (CheckLocationIfEmpty(activeFood) == false)
		goto label1;
}


void Draw()
{
	system("cls");//clean CMD
	printf("Press Left, Right, Up or Down Arrow to Start...\n\n");
	for (int i = 0; i < MAX_X; i++) //Double for loop to creates the boundary
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			if (i == MAX_X - 1 || i * j == 0 || j == MAX_Y - 1)
			{
				printf("#");
				continue;
			}
			bool Flag = true;
			if (i == snake.head.x && snake.head.y == j)
			{
				printf("$");
				Flag = false;
			}


			else if (i == activeFood.x && j == activeFood.y)
			{
				printf("*");
				Flag = false;

			}
			else
				for (int k = 0; k < snake.length - 1; k++)
				{
					if (snake.tail[k].x == i && snake.tail[k].y == j)
					{
						printf("O");
						Flag = false;
						break;
					}
				}

			if (Flag == true) printf(" ");

		}
		printf("\n");
	}
	printf("score = %d", score);
	printf("\n");
}

void Input()
{
	if (_kbhit())//here we chack if a key as been pressed or not (for _khbit() we must include the header file conio.h)
	{
		_getch();
		char key = _getch();
		switch (key)//check what the user as been pressed
		{
		case 72://up
			if (snake.move != down)
				snake.move = up;
			break;
		case 75://left
			if (snake.move != right)
				snake.move = left;
			break;
		case 80://down
			if (snake.move != up)	
				snake.move = down;
			break;
		case 77://right
			if (snake.move != left)
				snake.move = right;
			break;
		default:
			break;
		}
	}
}

void Logic()
{

	
	Location TailBeckup;
	TailBeckup.x = snake.tail[0].x;
	TailBeckup.y = snake.tail[0].y;
	snake.tail[0].x = snake.head.x;
	snake.tail[0].y = snake.head.y;

	switch (snake.move)
	{
	case up:
		snake.head.x--;
		break;
	case left:
		snake.head.y--;
		break;
	case down:
		snake.head.x++;
		break;
	case right:
		snake.head.y++;
		break;
	}
	SetTail(TailBeckup);
	CheckIfSnakeCrushed(snake);
	
	//checking if the snake reaches the fruit. if its true then update the score and create a new fruit randomly.
	if (snake.head.x == activeFood.x && snake.head.y == activeFood.y)
	{
		score++;
		RandomFoodCreation();
	}
}

void SetTail(Location SnakeTailBackup)
{
	for (int i = snake.length - 2; i > 1; i--)
	{
		snake.tail[i].x = snake.tail[i - 1].x;
		snake.tail[i].y = snake.tail[i - 1].y;
	}
	snake.tail[1].x = SnakeTailBackup.x;
	snake.tail[1].y = SnakeTailBackup.y;
}

void CheckIfSnakeCrushed()
{
	if (snake.head.x >= 0 && snake.head.y >= 0 && snake.head.x <= MAX_X - 1 && snake.head.y <= MAX_Y - 1)
	{
		for (int i = 0; i < snake.length - 1; i++)
			if (snake.tail[i].x <= 0 || snake.tail[i].y <= 0 || snake.tail[i].x >= MAX_X - 1 || snake.tail[i].y >= MAX_Y - 1)
			{
				Game_Over = 1;
				return;
			}
	}
	else Game_Over = 1; 
						
}

bool CheckLocationIfEmpty(Location CheckFoodPlace)
{
	if (CheckFoodPlace.x == snake.head.x && CheckFoodPlace.y == snake.head.y)
		return false;
	for (int i = 0; i < snake.length - 1; i++)
		if (CheckFoodPlace.x = snake.tail[i].x && CheckFoodPlace.y == snake.tail[i].y)
			return false;
	return true;
}

void RandomFoodCreation()
{
label1:
	activeFood.x = rand() % MAX_X; // Create a random number within 
	if (!activeFood.x)
		goto label1;
label2:
	activeFood.y = rand() % MAX_Y;
	if (!activeFood.y)
		goto label2;
	if (CheckLocationIfEmpty(activeFood) == false)
		goto label1;
}

void GameOver() 
{
	printf("\n*****************************\n");
	printf("=         Game Over !!!     =\n");
	printf("=============================\n");
	printf("          Final Score : %d     \n\n", score);
	printf("*** For New Game Please Press Y And Than Press Enter ***\n\n");
	printf("*** Else , Please Press Any Key To QUIT And Than Press Enter ***\n\n");
	printf("Please Type Your Answer Here: ");
}

