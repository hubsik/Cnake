/*
 * Snake.h
 *
 *  Created on: 15 wrz 2019
 *      Author: Hubert
 */

#include "CONSTS.h"
#ifndef SNAKE_H_
#define SNAKE_H_

enum Direction {UP, DOWN, RIGHT, LEFT};

struct Segment
{
	int X;
	int Y;
};

struct Snake
{
	int segmentsCount;
	enum Direction movingDirection;
	struct Segment segments[WIDTH*HEIGHT];
};

void MoveSnake(struct Snake *snake);
void SetDirection(char pk, struct Snake *snake);
void AddSegment(struct Snake* snake, int x, int y);

#endif /* SNAKE_H_ */
