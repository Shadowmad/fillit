/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:57:16 by lmartyny          #+#    #+#             */
/*   Updated: 2020/02/05 21:06:24 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "filit.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

/*
** checking for invalid characters
** returns 0 if any checks are failed
** pereviryaemo vsi tetraminu
*/

int					check_tetr(char *tetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i <= 19)
	{
		if (tetr[i] && tetr[i] != '\n' && tetr[i] != '#' && tetr[i] != '.')
			return (0);
		if (tetr[i] != '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (tetr[i] == '#')
			count++;
		i++;
	}
	return (count);
}

/*
**checking for a valid 4'#' piece and it's connection(6 or 8 to be valid
*/

static int			check_con(char *tetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (tetr[i] == '#')
		{
			if (i + 1 <= 18 && tetr[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && tetr[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && tetr[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && tetr[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int				valid(char *tetr, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (check_tetr(tetr + 1) != 4)
			return (0);
		if (check_con(tetr + 1) != 6 && check_con(tetr + 1) != 8)
			return (0);
		if ((*(tetr + 20) != "\n") && (*(tetr + 20) != "#" || *(tetr + 20) != "."))
			return (0);
		i += 21;
	}
	return (1);
}



/*
int		main(int size, char **path)
{
	int		fd;
	char	*buf;
	char	**output;
	char	i;
	int		res;

	i = 0;
	buf = ft_strnew(21);
	output = (char**)malloc(sizeof(char*) * (size + 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (res == read(fd, buf, 21))
	{
		output[i] = ft_strdup(buf);
		i++;
	}
	free (buf);
	if (close == -1)
		return (NULL);
	return (output);
}
*/
