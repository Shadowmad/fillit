#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

void		convert_tetr(char **tetr, char c);
void		shift_tetr(char **tetr);
char		***generate_tetr_list(t_list *start);
void		free_linked_list(t_list *start);
char		***convert_all(t_list *start);

#endif
