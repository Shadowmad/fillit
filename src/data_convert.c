void		convert_tetr(char **tetr, char c)
{
	int row_index;
	int col_index;

	row_index = 0;
	col_index = 0;
	while (row_index < 5)
	{
		col_index = 0;
		while (col_index < 5)
		{
			if (tetr[row_index][col_index] == '#')
			{
				tetr[row_index][col_index] = c;
			}
			col_index++;
		}
		row_index++;
	}
}
