#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "Snake.h"
#include "CONSTS.h"

enum GameResult {Win, Lose, Playing};
enum Solution {Release, Debug};

void PrintInfo(struct Snake *snake, int * timeToWait)
{
	printf("\nsnake.X: %d", snake->segments[0].X);
	printf("\nsnake.Y: %d\n", snake->segments[0].Y);
	printf("\ntimeToWait: %d\n", *timeToWait);
}

int PointEaten(struct Snake* snake, struct Point *point)
{
	if ((snake->segments[0].X == point->X) && (snake->segments[0].Y == point->Y))
	{
		AddSegment(snake);

		*point = GeneratePoint(snake);
		return 1;
	}
	else
	{
		return 0;
	}
}

enum GameResult DidGameFinished(struct Snake* snake)
{
	int seg;
	int headx;
	int heady;
	enum GameResult result = Playing;

	seg = snake->segmentsCount;
	headx = snake->segments[0].X;
	heady = snake->segments[0].Y;

	int i;
	
	for (i = 1; i < seg; i++)
	{
		if ((headx == snake->segments[i].X) && (heady == snake->segments[i].Y))
		{
			result = Lose;
			break;
		}
	}
	if ((headx > (WIDTH-1)) || (headx < 0))
	{
		result = Lose;
	}
	if ((heady > (HEIGHT-1)) || (heady < 0))
	{
		result = Lose;
	}
	if (snake->segmentsCount == WIDTH * HEIGHT)
	{
		result = Win;
	}
	return result;
}

void ChangeTimeToWait(int * timeToWait)
{
	if (*timeToWait > MIN_TIMETOWAIT)
	{
		*timeToWait = *timeToWait - (int)(CHANGE_RATE * INIT_TIMETOWAIT);
	}
}

int main(void) {
	int timeToWait;
	int width;
	int height;
	enum GameResult result;
	enum Solution solution;
	char pressedKey;
	struct Snake snake;
	struct Point point;

	timeToWait = INIT_TIMETOWAIT;
	width = WIDTH;
	height = HEIGHT;
	pressedKey = 'w';	
	snake.segmentsCount = 0;
	snake.movingDirection = UP;
	result = Playing;
	solution = Release;

	Initialize(&snake);

	point = GeneratePoint(&snake);

	while (result == Playing)
	{
		system("cls");
		if (PointEaten(&snake, &point))
		{
			ChangeTimeToWait(&timeToWait);
		}
		PrintBoard(&snake, &point);

		/* Only for debug */
		if (solution == Debug)
		{
			PrintInfo(&snake, &timeToWait);
		}
		

		int countdown;
		int isPressed;
		for(countdown = 0; countdown < timeToWait; countdown++) 
		{
			isPressed = _kbhit();
			if (isPressed != 0)
			{
				pressedKey = _getch();
				SetDirection(pressedKey, &snake);
				break;
			}
			Sleep(1);                
		}
		MoveSnake(&snake);
		Sleep(timeToWait-countdown);
		result = DidGameFinished(&snake);
	}

	if (result == Win)
	{
		printf("YOU WON!\n");
	}
	else
	{
		printf("YOU LOSE!\n");
	}

	return EXIT_SUCCESS;
}


