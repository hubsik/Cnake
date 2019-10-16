#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point.h"

struct Point GeneratePoint(int width, int height)
{
	struct Point point;
	int seed;
	time_t tt;

	seed = time(&tt);
	srand(seed);

	point.X = (int)(rand()% width);
	point.Y = (int)(rand()% height);

	return point;
}