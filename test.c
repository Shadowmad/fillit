#include <unistd.h>
void		print_tetr(char **tetr);
void		convert_tetr(char **tetr, char c);
void		shift_tetr(char **tetr);

int main()
{
	char row0[5] = ".###\n";
	char row1[5] = "..#.\n";
	char row2[5] = "....\n";
	char row3[5] = "....\n";
	char *tetr[4] = { row0, row1, row2, row3 };

	print_tetr(tetr);

	convert_tetr(tetr, 'A');
	write(1, "\n", 1);
	print_tetr(tetr);

	shift_tetr(tetr);
	write(1, "\n", 1);
	print_tetr(tetr);
	return (1);
}
