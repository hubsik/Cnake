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
	
	for ( i = 0; i < seg; i++)
	{
		dir = snake->segments[i].movingDirection;

		if (dir == UP)
		{
			snake->segments[i].Y = snake->segments[i].Y - 1;
		}
		else if (dir == DOWN)
		{
			snake->segments[i].Y = snake->segments[i].Y + 1;
		}
		else if (dir == RIGHT)
		{
			snake->segments[i].X = snake->segments[i].X + 1;
		}
		else if (dir == LEFT)
		{
			snake->segments[i].X = snake->segments[i].X - 1;
		}
	}
}

//Function to set move direction
void SetDirection(char pk, struct Snake *snake)
{
	int i;
	int seg;

	seg = snake->segmentsCount;

	if (pk == 'w')
	{
		snake->segments[0].movingDirection = UP;
	}
	else if (pk == 's')
	{
		snake->segments[0].movingDirection = DOWN;
	}
	else if (pk == 'a')
	{
		snake->segments[0].movingDirection = LEFT;
	}
	else if (pk == 'd')
	{
		snake->segments[0].movingDirection = RIGHT;
	}

	for (i = 1; i < seg; i++)
	{
		snake->segments[i].movingDirection = snake->segments[i - 1].movingDirection;
	}
}

/*void AddSegment(struct Snake* snake, int x, int y)
{
	int seg;

	seg = snake->segmentsCount;
	snake->segments[seg - 1].movingDirection = snake->segments[seg - 2].movingDirection;

	snake->segmentsCount += 1;

}*/