#include <stdio.h>

void		convert_tetr(char **tetr, char c)
{
	int row_index;
	int col_index;

	row_index = -1;
	while (++row_index < 5)
	{
		col_index = -1;
		while (++col_index < 5)
		{
			if (tetr[row_index][col_index] == '#')
				tetr[row_index][col_index] = c;
		}
	}
}

int			find_first_index(char **tetr, int mode)
{
	int row_index;
	int col_index;

	row_index = -1;
	while (++row_index < 5)
	{
		col_index = -1;
		while (++col_index < 5)
		{
			if (tetr[row_index][col_index] != '.')
			{
				if (mode == 0)
					return (row_index);
				else
					return (col_index);
			}
		}
	}
	return (row_index);
}

void		shift_tetr(char **tetr)
{
	int row_index;
	int col_index;
	int offset_x;
	int offset_y;

	row_index = -1;
	offset_x = find_first_index(tetr, 0);
	offset_y = find_first_index(tetr, 1);
	while (++row_index < 4)
	{
		col_index = -1;
		while (++col_index < 4)
		{
			if (tetr[row_index][col_index] != '.')
			{
				tetr[row_index - offset_x][col_index - offset_y] = tetr[row_index][col_index];
				tetr[row_index][col_index] = '.';
			}
		}
	}
}
