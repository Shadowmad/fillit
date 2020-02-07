#include "ft_fillit.h"

int       read_file(char *fname, char *input_buffer)
{
  int fd;
  int index;

  fd = open(fname, O_RDONLY, 0);
  index = 0;
  if (fd == -1)
    return (-1);
  while ((read(fd, input_buffer + index, 1)))
    index++;
  if (index > 545)
    return (-1);
  return (index);
}

int     main(int argc, char **argv)
{
  char  *file_input;
  int   ret;
  char  ***list;

  file_input = (char *) malloc(sizeof(char) * 545);
  ret = read_file(argv[1], file_input);
  if (argc != 2 || ret == -1)
  {
    write(1, "usage: ./fillit source_file\n", 28);
    return (-1);
  }
  ret = check_all_tetr(tetr, ret);
  if (ret)
  {
    list = generate_tetr_list(file_input);
  }
  else
  {
    write(1, "error", 5);
  }
}