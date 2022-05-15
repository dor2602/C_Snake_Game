#ifndef SNAKE_H
#define SNAKE_H
#define MAX_X 20
#define MAX_Y 20

enum boolEnum { false, true };
typedef enum boolEnum bool;

/* Typedef enum SnakeDirection Direction */
typedef enum SnakeDirection
{
	up, down, left, right
}Direction;

/* Typedef struct snake_Location Location */
typedef struct Snake_Location
{
	int x;
	int y;
}Location;

/* Typedef struct Main_Snake Snake */
typedef struct Main_Snake
{
	Direction move;
	Location head;
	Location tail[3];
	int length;
}Snake;

/* Global variables */
Snake snake;
Location activeFood; 
bool Flag;
int score, Game_Over, speed;

/*Start of functions declarations and explanations */


void Draw();
/*
* void draw();
*
  name: Draw
  type: void
  return values:None
  Parameters the function accepts: None
  explanation: This draw function is responsible to build the boundary within which the game will be played.
*
*/


void Input();
/*
* void input();
*
  name: Input
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function will take the input from the keyboard.
*
*/


void SetTail(Location);
/*
* void SetTail(Location);
*
  name: SetTail
  type: void
  return values: None
  Parameters the function accepts: Location(int,int)
  explanation:This function helps to synchronize the tail of the snake with its head.
*
*/


bool CheckLocationIfEmpty(Location);
/*
* bool CheckLocationIfEmpty(Location);
*
  name: CheckLocationIfEmpty
  type: void
  return values: true or false
  Parameters the function accepts: Location(int,int)
  explanation:This function checks whether the newly created fruit is not in a position that collides with the snake.
*
*/


void RandomFoodCreation();
/*
* void RandomFoodCreation();
*
  name: RandomFoodCreation
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function will create a new fruit for the snake only in case it has already eaten the previous fruit.
*
*/


void Logic();
/*
* void Logic();
*
  name: Logic
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function will set the movement of the snake,its also checks if game was finish and if the fruit  has been eaten by the snake.
*
*/


void Setup();
/*
* void Setup();
*
  name: Setup
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function helps to initialize a new game
*
*/

void GameOver();
/*
* void GameOver();
*
  name: GameOver
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function will print to the user that the game is over to him and she'll check to see if he's interested in starting a new game
*
*/


void CheckIfSnakeCrushed();
/*
* void CheckIfSnakeCrushed();
*
  name: CheckIfSnakeCrushed
  type: void
  return values: None
  Parameters the function accepts: None
  explanation:This function checks whether the snake has gone beyond the game and behaves accordingly.
*
*/

/* End of declarations and explanations */

#endif
