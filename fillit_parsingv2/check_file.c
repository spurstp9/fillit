/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:11:09 by agardina          #+#    #+#             */
/*   Updated: 2019/06/14 11:35:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Counts the number of blocks that are in contact with at least 2 other
** blocks. A valid tetrimino should have at least two of them, or one that
** is in contact with 3 blocks (case of the T-shaped tetrimino).
*/

int	count_double_sides(t_tetri tetri, t_point p, int *count)
{
	int nb;

	nb = check_bloc_side(tetri, p);
	if (nb >= 2)
		(*count)++;
	if (nb > 2)
		(*count)++;
	return ((nb > 0) ? 1 : 0);
}

/*
** Counts the number of blocks that touch the block at point p.
*/

int	check_bloc_side(t_tetri tetri, t_point p)
{
	int nb;

	nb = 0;
	if (p.y > 0)
		if ((tetri.str)[p.y - 1][p.x] == '#')
			nb++;
	if (p.y < 3)
		if ((tetri.str)[p.y + 1][p.x] == '#')
			nb++;
	if (p.x > 0)
		if ((tetri.str)[p.y][p.x - 1] == '#')
			nb++;
	if (p.x < 3)
		if ((tetri.str)[p.y][p.x + 1] == '#')
			nb++;
	return (nb);
}

int	check_tetri(t_tetri *tetri)
{
	int		blocs_nb;
	int		count;
	t_point p;

	blocs_nb = 0;
	p.x = -1;
	p.y = -1;
	count = 0;
	while (++p.y < 4)
	{
		while (++p.x < 5)
		{
			if ((tetri->str)[p.y][p.x] == '#')
			{
				if (!count_double_sides(*tetri, p, &count))
					return (0);
				else
					blocs_nb++;
			}
		}
		p.x = -1;
	}
	return ((blocs_nb == 4 && count >= 2) ? 1 : 0);
}

int	check_file(const int fd, t_tetri **list)
{
	char	line[5];
	char	file[547];
	int		line_index;
	int		file_index;
	int		ret;

	file_index = 0;
	line_index = 0;
	ret = 0;
	if ((ret = read(fd, file, 546)) > 545)
		return (0);
	file[ret] = '\0';
	while ((ret = fill_line(file, &file_index, line, line_index + 1)) > 0)
	{
		line_index++;
		if (!make_check_tetri(list, line, line_index))
			return (0);
	}
	return (ret == 0 ? 1 : 0);
}
