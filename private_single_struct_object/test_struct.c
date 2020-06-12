#include <stdio.h>
#include "point.h"

int main()
{
	extern struct point coordinate;
	coordinate.x = 10;
	coordinate.y = 6;
	print_point(&coordinate);
	return 0;
}
