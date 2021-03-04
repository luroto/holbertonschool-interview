#include "menger.h"
/**
 * menger - Function to print a Sierpinsky's carpet or
 * 2d menger sponge
 * @level: level of the menger sponge to draw
 */

void menger(int level)
{
	int x, y, little_x, little_y, size;
	char printing;

	if (level >= 0)
	{
		size = pow(3, level);
		x = 0;
		y = 0;
		little_x = 0;
		little_y = 0;
		while (x < size)
		{
			y = 0;
			while (y < size)
			{
				little_x = x;
				little_y = y;
				printing = '#';
				while (little_x > 0 || little_y > 0)
				{
					if (little_x % 3 == 1 && little_y % 3 == 1)
						printing = ' ';
					little_x /= 3;
					little_y /= 3;
				}
				printf("%c", printing);
				y++;
			}
			printf("\n");
			x++;
		}
	}

}
