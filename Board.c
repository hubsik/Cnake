/*
 * Board.c
 *
 *  Created on: 15 wrz 2019
 *      Author: Hubert
 */

#include <stdio.h>
#include "Board.h"
#include "Snake.h"
#include "Point.h"
#include "CONSTS.h"

void PrintBoard(struct Snake *snake, struct Point *point)
{
	printf(" "); //odsunięcie o 1 od krawędzi
	for (int columns = 0; columns < WIDTH; columns++) //górna krawędź
	{
		printf("#");
	}
	printf("\n"); //nowa linia
	for(int rows = 0; rows < HEIGHT; rows++)
	{
		printf("#");
		for (int columns = 0; columns < WIDTH; columns++)
		{
			if((snake->segments[0].X == columns) && (snake->segments[0].Y == rows))
			{
				printf("o");
			}
			else if((point->X == columns) && (point->Y == rows))
			{
				printf("@");
			}
			else 
			{
				printf(" ");
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

int getWidth()
{
	return WIDTH;
}

int getHeight()
{
	return HEIGHT;
}
