#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

int         read_file(char *fname, char *input_buffer);
int         check_tetr(char *tetr);
static int  check_con(char *tetr);
int         check_all_tetr(char *tetr, int size);
int         count_tetr(char *input);
char        ***generate_tetr_list(char *input);
void        convert_tetr(char **tetr, char c);
void        shift_tetr(char **tetr);
void        print_tetr(char **tetr);
#endif
