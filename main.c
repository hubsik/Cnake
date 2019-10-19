//#define _CRT_SECURE_NO_WARNINGS //it is usefull when usinf 'scanf'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "Snake.h"
#include "Point.h"
#include "CONSTS.h"

enum GameResult {Win, Lose, Playing};

void PrintInfo(struct Snake *snake)
{
	printf("\nsnake.X: %d", snake->segments[0].X);
	printf("\nsnake.Y: %d\n", snake->segments[0].Y);
}

void PointEaten(struct Snake* snake, struct Point * point, int width, int height)
{
	if ((snake->segments[0].X == point->X) && (snake->segments[0].Y == point->Y))
	{
		int i;
		int segments;
		int equals;
		AddSegment(snake);
		segments = snake->segments;
		equals = 1;
		while(equals)
		{
			*point = GeneratePoint(width, height);
			equals = 0;

			//Check if generated point is not on the same position as snake
			//if is then Call GeneratePoint again
			for (i = 0; i < segments; i++)
			{
				if ((snake->segments[0].X == point->X) && (snake->segments[0].Y == point->Y))
				{
					equals = 1;
				}
			}
		}
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
	if ((heady == (HEIGHT-1)) || (heady < 0))
	{
		result = Lose;
	}
	return result;
}

int main(void) {
	int timeToWait;
	int width;
	int height;
	enum GameResult result;
	char pressedKey;
	struct Segment segments;
	struct Snake snake;
	struct Point point;

	timeToWait = INIT_TIMETOWAIT;
	width = WIDTH;
	height = HEIGHT;
	pressedKey = 'w';	
	snake.segmentsCount = 0;
	snake.movingDirection = UP;
	result = Playing;

	Initialize(&snake);

	point = GeneratePoint(width, height);

	while (result == Playing)
	{
		system("cls");
		PrintBoard(&snake, &point);
		PointEaten(&snake, &point, width, height);
		PrintInfo(&snake);

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


