#include "ft_fillit.h"

void		convert_tetr(char **tetr, char c)
{
	int row_index;
	int col_index;

	row_index = -1;
	while (++row_index < 4)
	{
		col_index = -1;
		while (++col_index < 4)
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
	while (++row_index < 4)
	{
		col_index = -1;
		while (++col_index < 4)
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
	int row;
	int col;
	int offset_x;
	int offset_y;

	row = -1;
	offset_x = find_first_index(tetr, 0);
	offset_y = find_first_index(tetr, 1);
	while (++row < 4 && (offset_x || offset_y))
	{
		col = -1;
		while (++col < 4)
		{
			if (tetr[row][col] != '.')
			{
				tetr[row - offset_x][col - offset_y] = tetr[row][col];
				tetr[row][col] = '.';
			}
		}
	}
}

int     count_tetr(char *input)
{
  int   count;
  char  *scanner;

  count = 0;
  scanner = input;
  while (*scanner)
  {
    if (*scanner == '\n')
      count++;
    scanner++;
  }
  return ((count + 1)/ 5);
}

void    fill_tetr_list(char ***list, char *input, int num)
{
  int index;
  int row;
  int col;

  index = 0;
  while (index < num)
  {
    list[index] = (char**)malloc(sizeof(char*) * 4);
    row = 0;
    while (row < 4)
    {
      list[index][row] = (char*)malloc(sizeof(char) * 4);
      col = 0;
      while (col < 4)
      {
        list[index][row][col] = *input;
        input++;
        col++;
      }
      input++;
      row++;
    }
    input++;
    index++;
  }
}

char    ***generate_tetr_list(char *input)
{
  char    ***list;
  int     num_tetr;
  int     index;
  char    convert_char;

  convert_char = 'A';
  index = 0;
  num_tetr = count_tetr(input);
  list = (char***)malloc(sizeof(char**) * num_tetr);
  fill_tetr_list(list, input, num_tetr);
  while (index < num_tetr)
  {
    convert_tetr(list[index], convert_char + index);
    shift_tetr(list[index]);
    index++;
  }
  print_tetr(list[0]);
  print_tetr(list[1]);
  print_tetr(list[2]);
  print_tetr(list[3]);
  return (list);
}