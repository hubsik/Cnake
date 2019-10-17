/*
 * Snake.c
 *
 *  Created on: 15 wrz 2019
 *      Author: Hubert
 */

#include "Snake.h"


//Function to change position of snake segments
void MoveSnake(struct Snake *snake)
{
	int i;
	int seg;
	enum Direction dir;

	seg = snake->segmentsCount;
	
	for (i = seg-1; i > 0; i--)
	{
		snake->segments[i].Y = snake->segments[i-1].Y;
		snake->segments[i].X = snake->segments[i-1].X;
	}

	dir = snake->movingDirection;

	if (dir == UP)
	{
		snake->segments[0].Y = snake->segments[i].Y - 1;
	}
	else if (dir == DOWN)
	{
		snake->segments[0].Y = snake->segments[i].Y + 1;
	}
	else if (dir == RIGHT)
	{
		snake->segments[0].X = snake->segments[i].X + 1;
	}
	else if (dir == LEFT)
	{
		snake->segments[0].X = snake->segments[i].X - 1;
	}
	
}

//Function to set move direction
void SetDirection(char pk, struct Snake *snake)
{
	int i;
	int seg;

	if (pk == 'w')
	{
		snake->movingDirection = UP;
	}
	else if (pk == 's')
	{
		snake->movingDirection = DOWN;
	}
	else if (pk == 'a')
	{
		snake->movingDirection = LEFT;
	}
	else if (pk == 'd')
	{
		snake->movingDirection = RIGHT;
	}
}

void AddSegment(struct Snake *snake, int x, int y)
{
	int seg;

	snake->segmentsCount = (snake->segmentsCount) + 1;
	seg = snake->segmentsCount;
		
	snake->segments[seg - 1].X = x;
	snake->segments[seg - 1].Y = y;
}