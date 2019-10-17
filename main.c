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

		AddSegment(snake, point->X, point->Y);
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

int main(void) {
	int timeToWait;
	int width;
	int height;
	char pressedKey;
	struct Segment segments;
	struct Snake snake;
	struct Point point;

	timeToWait = INIT_TIMETOWAIT;
	width = getWidth();
	height = getHeight();
	pressedKey = 'w';	
	snake.segmentsCount = 0;
	snake.movingDirection = UP;

	AddSegment(&snake, START_X, START_Y);

	point = GeneratePoint(width, height);

	while(TRUE)
	{
		PointEaten(&snake, &point, width, height);
		PrintBoard(&snake, &point);
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
		system("cls");
	}

	return EXIT_SUCCESS;
}


