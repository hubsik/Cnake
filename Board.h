/*
 * Board.h
 *
 *  Created on: 15 wrz 2019
 *      Author: Hubert
 */


#ifndef BOARD_H_
#define BOARD_H_

struct Point
{
	int X;
	int Y;
};

struct Point GeneratePoint(struct Snake* snake);
void PrintBoard(struct Snake* snake, struct Point* point);

#endif /* BOARD_H_ */
