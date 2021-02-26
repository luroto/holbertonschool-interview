#include "slide_line.h"
/*
*slide_line - Function to emulate the 2048 line game behaviour
*@line: Line to be slided and added
*@size: Size of the arguments
*@direction: direction for pushing the line
Return: 1 if process works well
*/
int slide_line(int *line, size_t size, int direction)
{
	ordering_line(line, size, direction);
	adding_lines(line, size, direction);
	return (1);
}

/*
*ordering_line - Function to rearrange the line pushing
*all positive numbers to desired direction
*@line: Line to be slided and added
*@size: Size of the arguments
*@direction: direction for pushing the line
*/
void ordering_line(int *line, size_t size, int direction)
{
	size_t start, end, i, found;

	start = 0;
	end = 0;
	i = 0;
	found = 0;

	if (direction == SLIDE_LEFT)
	{
		start = 0;
		end = size - 1;
	}
	if (direction == SLIDE_RIGHT)
	{
		start = size - 1;
		end = 0;
	}
	i = start;
	while (i != end)
	{
		if (line[i] == 0)
		{
		found = i;
		while (line[found] == 0 && found != end)
		{
			direction == SLIDE_LEFT ? found++ : found--;
		}
		line[i] = line[found];
		line[found] = 0;
		if (i == end)
			break;
		}
		direction == SLIDE_LEFT ? i++ : i--;
	}
}

/*
*adding_lines - Function to add the equal values
*@line: Line to be slided and added
*@size: Size of the arguments
*@direction: direction for pushing the line
*/
void adding_lines(int *line, size_t size, int direction)
{
	size_t start, end, i, next;

	start = 0;
	end = 0;
	i = 0;
	next = 0;

	if (direction == SLIDE_LEFT)
	{
		start = 0;
		end = size - 1;
	}
	if (direction == SLIDE_RIGHT)
	{
		start = size - 1;
		end = 0;
	}
	i = start;
	next = i;
	while (i != end)
	{
		direction == SLIDE_LEFT ? next++ : next--;
		if (line[i] == line[next])
		{
		line[i] = line[i] + line[next];
		line[next] = 0;
		ordering_line(line, size, direction);
		}
		direction == SLIDE_LEFT ? i++ : i--;
	}
}
