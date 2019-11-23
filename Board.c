/*
 * Board.c
 *
 *  Created on: 15 wrz 2019
 *      Author: Hubert
 */

#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "Snake.h"
#include "CONSTS.h"

struct Point GeneratePoint(struct Snake *snake)
{
	struct Point point;
	int segmentsCount;
	int seed;
	int randValue;
	time_t tt;

	segmentsCount = snake->segmentsCount;
	seed = time(&tt);
	srand(seed);
	if (segmentsCount < WIDTH * HEIGHT)
	{
		/* +1 to prevent randValue == 0*/
		randValue = (rand() % (WIDTH * HEIGHT - segmentsCount))+1;
	}
	else
	{
		randValue = 0;
	}
	point.X = 0;
	point.Y = 0;

	int i;
	int j;
	int k;
	int counter;
	counter = 0;
	for (i = 0; i < WIDTH; i++)
	{
		if (counter < randValue)
		{
			for (j = 0; j < HEIGHT; j++)
			{
				if (counter < randValue)
				{
					k = 0;
					while (k < segmentsCount)
					{
						if ((snake->segments[k].X == i) && (snake->segments[k].Y == j))
						{
							break;
						}
						else
						{
							k = k + 1;
						}
					}
					if (k == segmentsCount)
					{
						counter = counter + 1;
					}
					if (counter == randValue)
					{
						point.X = i;
						point.Y = j;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}

	return point;
}

void PrintBoard(struct Snake *snake, struct Point *point)
{

	printf(" "); 
	for (int columns = 0; columns < WIDTH; columns++)
	{
		printf("#");
	}
	printf("\n");
	for(int rows = 0; rows < HEIGHT; rows++)
	{
		printf("#");
		for (int columns = 0; columns < WIDTH; columns++)
		{
			int i;
			int seg;
			int printed;

			printed = 0;
			seg = snake->segmentsCount;
			for (i = 0; i < seg; i++)
			{
				if ((snake->segments[i].X == columns) && (snake->segments[i].Y == rows))
				{
					if (i == 0)
					{
						printf("O");
					}
					else
					{
						printf("o");
					}
					printed = 1;
					break;
				}
			}
			if (printed == 0)
			{
				if ((point->X == columns) && (point->Y == rows))
				{
					printf("@");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("#");
		printf("\n");
	}
	printf(" ");
	for (int columns = 0; columns < WIDTH; columns++)
	{
		printf("#");
	}
	printf("\n");
}
