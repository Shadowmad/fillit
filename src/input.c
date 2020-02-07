#include "ft_fillit.h"

int       read_file(char *fname, char *input_buffer)
{
  int fd;
  int ret;
  int index;
  char input1[600];

  fd = open(fname, O_RDONLY, 0);
  if (fd == -1)
  {
    return (-1);
  }
  ret = read(fd, input1, 1);
  printf("%s\n", input1);
  return (ret);
}

int     main(int argc, char **argv)
{
  char *file_input;
  int fd;

  file_input = (char *) malloc(sizeof(char) * 545);
  fd = read_file(argv[0], file_input);
  if (argc != 2 || fd == -1)
  {
    write(1, "usage: ./fillit source_file\n", 28);
    return (-1);
  }
  printf("%d\n", fd);
  printf("%s", file_input);
}